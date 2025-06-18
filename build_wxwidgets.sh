#!/bin/bash

# Script de construcción para wxWidgets + SDL3

echo "🔨 Construyendo aplicación wxWidgets + SDL3..."

# Crear directorio build si no existe
mkdir -p build
cd build

# Verificar si wxWidgets está instalado
if ! command -v wx-config &> /dev/null; then
    echo "⚠️  wxWidgets no encontrado. Instalando con Homebrew..."
    echo "💡 Ejecuta: brew install wxwidgets"
    echo "   O instala desde: https://www.wxwidgets.org/"
    echo ""
    echo "📋 Instalación alternativa:"
    echo "   brew install wxwidgets"
    echo "   brew install sdl3"
    exit 1
fi

echo "✅ wxWidgets $(wx-config --version) encontrado"

# Configurar con CMake
echo "🔧 Configurando proyecto..."
cmake .. -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"

# Compilar
echo "🔨 Compilando..."
make -j$(sysctl -n hw.ncpu)

if [ $? -eq 0 ]; then
    echo "✅ Compilación exitosa!"
    echo ""
    echo "🚀 Ejecutables disponibles:"
    if [ -f "./bin/wxWidgets_Simple_Demo" ]; then
        echo "   • ./bin/wxWidgets_Simple_Demo (Demo wxWidgets + SDL3) ✓"
    fi
    echo ""
    echo "🎯 Para ejecutar:"
    echo "   cd build && ./bin/wxWidgets_Simple_Demo    # Aplicación principal"
else
    echo "❌ Error en la compilación"
    exit 1
fi
