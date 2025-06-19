#!/bin/bash

# Script para compilar la aplicación wxWidgets usando make

echo "🔨 Compilando aplicación wxWidgets con make..."
echo "============================================="

# Compilar con información de progreso usando make
if cmake --build build --parallel $(nproc 2>/dev/null || echo 4); then
    echo "✅ Compilación exitosa con make!"
    echo "📁 Archivos generados:"
    ls -la build/bin/
    echo "============================================="
    echo "🎯 Aplicación lista para ejecutar!"
else
    echo "❌ Error en la compilación"
    echo "💡 Verifica los errores arriba"
    exit 1
fi
