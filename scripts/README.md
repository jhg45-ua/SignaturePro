# 🛠️ Scripts del Proyecto wxWidgets

## 📋 **Scripts Disponibles**

Esta carpeta contiene un script de utilidad para el proyecto wxWidgets. El build y ejecución ahora se maneja directamente con CMake a través de las tareas de VS Code.

### � **project-info.sh** - Información del Proyecto
```bash
./scripts/project-info.sh
```

**Funcionalidad**:
- ✅ Información completa del proyecto
- ✅ Estadísticas de código fuente
- ✅ Estado del build
- ✅ Resumen de archivos y líneas
- ✅ Información de dependencias

## 🔧 **Proceso de Build Simplificado**

El proyecto ahora usa únicamente CMake para el build:

1. **Configurar**: `cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug`
2. **Compilar**: `cmake --build build --parallel`
3. **Ejecutar**: `./build/bin/app`

O usar las tareas de VS Code:
- `Ctrl+Shift+P` → "Tasks: Run Task" → Seleccionar tarea deseada
```

**Funcionalidad**:
- ✅ Cuenta archivos fuente
- ✅ Calcula líneas de código
- ✅ Muestra tamaño del ejecutable
- ✅ Fecha de última compilación

**Salida típica**:
```
📊 Información del Proyecto wxWidgets
=================================
📁 Archivos fuente: 9
📏 Líneas de código: 157 total
🔧 Tamaño del ejecutable: 1.5M
⏱️  Última compilación: Jun 19 13:07:23 2025
```

## 🔧 **Integración con VS Code**

Estos scripts están integrados con las tareas de VS Code en `.vscode/tasks.json`: