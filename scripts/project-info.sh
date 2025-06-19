#!/bin/bash

# Script para mostrar información del proyecto wxWidgets

echo "📊 Información del Proyecto wxWidgets"
echo "================================="

echo "📁 Archivos fuente:"
find src -name "*.cpp" -o -name "*.hpp" | wc -l

echo "📏 Líneas de código:"
find src -name "*.cpp" -o -name "*.hpp" -exec wc -l {} + | tail -1

echo "🔧 Tamaño del ejecutable:"
if [ -f "./build/bin/app" ]; then
    ls -lh ./build/bin/app | awk '{print $5}'
else
    echo "No compilado"
fi

echo "⏱️  Última compilación:"
if [ -f "./build/bin/app" ]; then
    stat -f "%Sm" ./build/bin/app
else
    echo "N/A"
fi

echo "================================="
echo "🎯 Proyecto wxWidgets listo!"
