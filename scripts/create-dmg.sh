#!/bin/bash

# ==========================================
# SCRIPT PARA CREAR DMG DE DISTRIBUCIÓN
# ==========================================
# Script que crea un DMG listo para distribución
# con la aplicación y enlace a Applications

set -e  # Salir si hay error

# Colores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}📦 Creando DMG de distribución de SignaturePro${NC}"
echo "=================================================="

# Verificar que estamos en el directorio correcto
if [ ! -f "CMakeLists.txt" ]; then
    echo -e "${RED}❌ Error: Ejecutar desde el directorio raíz del proyecto${NC}"
    exit 1
fi

# Verificar que existe el build
if [ ! -d "build" ]; then
    echo -e "${YELLOW}⚠️  No existe directorio build. Construyendo aplicación...${NC}"
    ./scripts/build-macos-app.sh
fi

# Verificar que existe la aplicación
if [ ! -d "build/bin/SignaturePro.app" ]; then
    echo -e "${RED}❌ Error: No se encontró SignaturePro.app${NC}"
    echo "   Ejecutar primero: ./scripts/build-macos-app.sh"
    exit 1
fi

cd build

# Limpiar DMG anterior si existe
if [ -f "SignaturePro-0.0.1-Darwin.dmg" ]; then
    echo -e "${YELLOW}🧹 Eliminando DMG anterior...${NC}"
    rm -f SignaturePro-0.0.1-Darwin.dmg
fi

# Crear DMG
echo -e "${BLUE}📦 Generando DMG...${NC}"
if cpack; then
    echo -e "${GREEN}✅ DMG creado exitosamente${NC}"
    
    # Mostrar información del DMG
    DMG_FILE="SignaturePro-0.0.1-Darwin.dmg"
    if [ -f "$DMG_FILE" ]; then
        DMG_SIZE=$(du -h "$DMG_FILE" | cut -f1)
        echo ""
        echo -e "${GREEN}📋 Información del DMG:${NC}"
        echo -e "   📍 Archivo: $(pwd)/$DMG_FILE"
        echo -e "   📏 Tamaño: $DMG_SIZE"
        echo ""
        echo -e "${BLUE}💡 Contenido del DMG:${NC}"
        echo -e "   • SignaturePro.app - La aplicación"
        echo -e "   • Applications - Enlace para instalación"
        echo ""
        echo -e "${GREEN}🚀 Para probar el DMG:${NC}"
        echo -e "   open $DMG_FILE"
        echo ""
        echo -e "${GREEN}📤 Para distribuir:${NC}"
        echo -e "   El archivo $DMG_FILE está listo para compartir"
    fi
else
    echo -e "${RED}❌ Error al crear DMG${NC}"
    exit 1
fi
