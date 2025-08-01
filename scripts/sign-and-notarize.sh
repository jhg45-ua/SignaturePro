#!/bin/bash

# ==========================================
# SCRIPT PARA FIRMA Y NOTARIZACIÓN EN MACOS
# ==========================================
# Script opcional para firma con certificado de desarrollador Apple
# Requiere: Developer ID Application certificate y App Store Connect API key

set -e

# Colores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

APP_PATH="build/bin/SignaturePro.app"
DMG_PATH="build/SignaturePro-*.dmg"

# Configuración (establecer estas variables en GitHub Secrets o localmente)
DEVELOPER_ID="${DEVELOPER_ID:-}"  # Ej: "Developer ID Application: Tu Nombre (TEAM_ID)"
APPLE_ID="${APPLE_ID:-}"          # Tu Apple ID
TEAM_ID="${TEAM_ID:-}"            # Tu Team ID
APP_PASSWORD="${APP_PASSWORD:-}" # App-specific password

echo -e "${BLUE}🔐 Iniciando proceso de firma y notarización${NC}"
echo "=============================================="

# Verificar que la app existe
if [ ! -d "$APP_PATH" ]; then
    echo -e "${RED}❌ Error: No se encontró $APP_PATH${NC}"
    echo "Ejecuta primero el script build-macos-app.sh"
    exit 1
fi

# Función para firma ad-hoc (desarrollo/testing)
sign_adhoc() {
    echo -e "${YELLOW}📝 Aplicando firma ad-hoc (desarrollo)...${NC}"
    codesign --force --deep --sign - "$APP_PATH"
    echo -e "${GREEN}✅ Firma ad-hoc aplicada${NC}"
}

# Función para firma con Developer ID
sign_with_developer_id() {
    if [ -z "$DEVELOPER_ID" ]; then
        echo -e "${RED}❌ Error: DEVELOPER_ID no está configurado${NC}"
        echo "Configura la variable DEVELOPER_ID con tu certificado"
        echo "Ejemplo: 'Developer ID Application: Tu Nombre (TEAM_ID)'"
        exit 1
    fi

    echo -e "${BLUE}📝 Firmando con Developer ID...${NC}"
    echo "Certificado: $DEVELOPER_ID"
    
    # Firmar la aplicación
    codesign --force --deep --options runtime --sign "$DEVELOPER_ID" "$APP_PATH"
    
    # Verificar la firma
    codesign --verify --verbose "$APP_PATH"
    echo -e "${GREEN}✅ Aplicación firmada correctamente${NC}"
}

# Función para notarización
notarize_app() {
    if [ -z "$APPLE_ID" ] || [ -z "$TEAM_ID" ] || [ -z "$APP_PASSWORD" ]; then
        echo -e "${RED}❌ Error: Variables de notarización no configuradas${NC}"
        echo "Necesitas configurar: APPLE_ID, TEAM_ID, APP_PASSWORD"
        exit 1
    fi

    echo -e "${BLUE}📤 Creando archivo ZIP para notarización...${NC}"
    ZIP_FILE="build/SignaturePro.zip"
    ditto -c -k --keepParent "$APP_PATH" "$ZIP_FILE"

    echo -e "${BLUE}📤 Enviando para notarización...${NC}"
    xcrun notarytool submit "$ZIP_FILE" \
        --apple-id "$APPLE_ID" \
        --team-id "$TEAM_ID" \
        --password "$APP_PASSWORD" \
        --wait

    echo -e "${BLUE}📎 Aplicando ticket de notarización...${NC}"
    xcrun stapler staple "$APP_PATH"
    
    echo -e "${GREEN}✅ Aplicación notarizada correctamente${NC}"
    
    # Limpiar archivo ZIP temporal
    rm -f "$ZIP_FILE"
}

# Función para firmar DMG
sign_dmg() {
    if [ -z "$DEVELOPER_ID" ]; then
        echo -e "${YELLOW}⚠️  No se puede firmar DMG sin Developer ID${NC}"
        return
    fi

    for dmg in $DMG_PATH; do
        if [ -f "$dmg" ]; then
            echo -e "${BLUE}📦 Firmando DMG: $(basename "$dmg")${NC}"
            codesign --force --sign "$DEVELOPER_ID" "$dmg"
            echo -e "${GREEN}✅ DMG firmado: $(basename "$dmg")${NC}"
        fi
    done
}

# Menú principal
case "${1:-adhoc}" in
    "adhoc")
        sign_adhoc
        ;;
    "developer")
        sign_with_developer_id
        ;;
    "full")
        sign_with_developer_id
        notarize_app
        sign_dmg
        ;;
    "help")
        echo "Uso: $0 [adhoc|developer|full|help]"
        echo ""
        echo "  adhoc     - Firma ad-hoc para desarrollo (por defecto)"
        echo "  developer - Firma con Developer ID (requiere certificado)"
        echo "  full      - Firma completa + notarización (requiere certificado y Apple ID)"
        echo "  help      - Muestra esta ayuda"
        echo ""
        echo "Variables de entorno necesarias para firma completa:"
        echo "  DEVELOPER_ID  - Certificado (ej: 'Developer ID Application: Nombre (ID)')"
        echo "  APPLE_ID      - Tu Apple ID"
        echo "  TEAM_ID       - Tu Team ID de desarrollador"
        echo "  APP_PASSWORD  - App-specific password de Apple ID"
        ;;
    *)
        echo -e "${RED}❌ Opción no válida: $1${NC}"
        echo "Usa '$0 help' para ver las opciones disponibles"
        exit 1
        ;;
esac

echo ""
echo -e "${GREEN}🎉 Proceso completado${NC}"
echo -e "   📍 Aplicación: $APP_PATH"

exit 0
