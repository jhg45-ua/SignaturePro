#!/bin/bash

# Script para ejecutar la aplicación wxWidgets

echo "🚀 Ejecutando aplicación wxWidgets..."
echo "===================================="

# Verificar si el ejecutable existe
if [ -f "./build/bin/app" ]; then
    echo "✅ Ejecutable encontrado"
    echo "📱 Iniciando aplicación..."
    echo "===================================="
    ./build/bin/app
else
    echo "❌ Error: El ejecutable no existe"
    echo "💡 Ejecuta la tarea 'build' primero"
    echo "===================================="
    exit 1
fi
