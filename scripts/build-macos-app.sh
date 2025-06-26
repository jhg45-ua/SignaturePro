#!/bin/bash

# ==========================================
# SCRIPT PARA CONSTRUCCIÓN DE APP MACOS
# ==========================================
# Script que automatiza la creación de la aplicación macOS
# Incluye configuración, build y empaquetado

set -e  # Salir si hay error

# Colores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}🍎 Iniciando construcción de SignaturePro.app${NC}"
echo "=============================================="

# Limpiar build anterior si existe
if [ -d "build" ]; then
    echo -e "${YELLOW}🧹 Limpiando build anterior...${NC}"
    rm -rf build
fi

# Crear directorio build
mkdir -p build
cd build

# Configurar con CMake para Release
echo -e "${BLUE}⚙️  Configurando proyecto (Release)...${NC}"
cmake -S .. -B . -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Construir la aplicación
echo -e "${BLUE}🔨 Construyendo aplicación...${NC}"
cmake --build . --parallel

# Verificar que el bundle se creó correctamente
if [ -d "bin/SignaturePro.app" ]; then
    echo -e "${GREEN}✅ SignaturePro.app creado exitosamente${NC}"
    echo -e "   📍 Ubicación: $(pwd)/bin/SignaturePro.app"
    
    # Mostrar información del bundle
    echo ""
    echo -e "${BLUE}📋 Información del bundle:${NC}"
    ls -la bin/SignaturePro.app/Contents/
    
    # Intentar crear DMG si se solicita
    read -p "¿Crear archivo DMG para distribución? (y/N): " -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        echo -e "${BLUE}📦 Creando DMG...${NC}"
        if cpack; then
            echo -e "${GREEN}✅ DMG creado exitosamente${NC}"
            DMG_FILE=$(find . -name "*.dmg" -type f | head -1)
            if [ -n "$DMG_FILE" ]; then
                echo -e "   📍 Archivo DMG: $(pwd)/$DMG_FILE"
                echo -e "   💡 Abrir con: open $DMG_FILE"
                echo -e "   🎨 Con fondo personalizado y versión 0.0.1"
            fi
        else
            echo -e "${RED}❌ Error al crear DMG${NC}"
        fi
    fi
    
else
    echo -e "${RED}❌ Error: No se pudo crear SignaturePro.app${NC}"
    exit 1
fi

echo ""
echo -e "${GREEN}🎉 Proceso completado${NC}"
echo -e "   • Para ejecutar: open bin/SignaturePro.app"
echo -e "   • Para crear DMG manualmente: cpack"
