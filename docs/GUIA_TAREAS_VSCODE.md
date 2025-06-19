# 🛠️ Guía de Tareas VS Code - Proyecto wxWidgets

## 📋 **Tareas Disponibles**

### 🏗️ **Tareas de Construcción**

#### 1. **configure** - Configurar Proyecto
- **Descripción**: Configura el proyecto CMake con Unix Makefiles
- **Comando**: `cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=<tipo>`
- **Características**:
  - ✅ Selección de tipo de build (Debug, Release, RelWithDebInfo, MinSizeRel)
  - ✅ Generación de compile_commands.json para IntelliSense
  - ✅ Variables de entorno optimizadas
  - ✅ Uso de make tradicional para mayor compatibilidad
- **Uso**: **Ctrl+Shift+P** → "Tasks: Run Task" → "configure"

#### 2. **build** (Tarea por defecto)
- **Descripción**: Compila la aplicación wxWidgets
- **Script**: `./scripts/build.sh`
- **Características**:
  - ✅ Compilación paralela para mayor velocidad
  - ✅ Información de progreso mejorada
  - ✅ Verificación de archivos generados
  - ✅ Depende automáticamente de "configure"
  - ✅ Script separado para mejor compatibilidad con zsh
- **Uso**: **Ctrl+Shift+B** (tarea por defecto) o **Ctrl+Shift+P** → "Tasks: Run Task" → "build"

#### 3. **clean** - Limpiar Build
- **Descripción**: Elimina completamente el directorio build
- **Comando**: `rm -rf build`
- **Uso**: **Ctrl+Shift+P** → "Tasks: Run Task" → "clean"

#### 4. **rebuild** - Reconstruir Completo
- **Descripción**: Limpia y reconstruye el proyecto completamente
- **Secuencia**: clean → build
- **Uso**: **Ctrl+Shift+P** → "Tasks: Run Task" → "rebuild"

### 🚀 **Tareas de Ejecución**

#### 1. **run** - Ejecutar Aplicación
- **Descripción**: Ejecuta la aplicación wxWidgets
- **Script**: `./scripts/run.sh`
- **Características**:
  - ✅ Verificación de existencia del ejecutable
  - ✅ Compilación automática si es necesario
  - ✅ Mensajes informativos mejorados
  - ✅ Panel dedicado para la ejecución
  - ✅ Script separado para mejor compatibilidad con zsh
- **Uso**: **Ctrl+Shift+P** → "Tasks: Run Task" → "run"

#### 2. **run-debug** - Ejecutar en Modo Debug
- **Descripción**: Ejecuta la aplicación con LLDB debugger
- **Comando**: `lldb ./build/bin/app`
- **Uso**: **Ctrl+Shift+P** → "Tasks: Run Task" → "run-debug"

### 🔍 **Tareas de Información**

#### 1. **check-dependencies** - Verificar Dependencias
- **Descripción**: Verifica que todas las dependencias estén instaladas
- **Verifica**: wxwidgets, spdlog, cmake, make
- **Uso**: **Ctrl+Shift+P** → "Tasks: Run Task" → "check-dependencies"

#### 2. **project-info** - Información del Proyecto
- **Descripción**: Muestra estadísticas del proyecto
- **Script**: `./scripts/project-info.sh`
- **Información mostrada**:
  - 📁 Número de archivos fuente
  - 📏 Total de líneas de código
  - 🔧 Tamaño del ejecutable
  - ⏱️ Fecha de última compilación
- **Uso**: **Ctrl+Shift+P** → "Tasks: Run Task" → "project-info"

## ⚡ **Flujo de Trabajo Recomendado**

### 🔄 **Desarrollo Diario**
1. **build** (Ctrl+Shift+B) - Compilar cambios
2. **run** - Probar la aplicación
3. Repetir según sea necesario

### 🆕 **Configuración Inicial**
1. **check-dependencies** - Verificar instalación
2. **configure** - Configurar proyecto
3. **build** - Compilar por primera vez
4. **run** - Ejecutar aplicación

### 🔧 **Problemas de Compilación**
1. **clean** - Limpiar build
2. **configure** - Reconfigurar
3. **build** - Compilar desde cero

### 📊 **Monitoreo**
- **project-info** - Ver estadísticas del proyecto
- **check-dependencies** - Verificar dependencias

## 🎯 **Características Avanzadas**

### 📋 **Entradas Interactivas**
- **Tipo de Build**: Selección entre Debug, Release, RelWithDebInfo, MinSizeRel
- **Acceso**: Automático al ejecutar "configure"

### 🌍 **Variables de Entorno**
```json
{
    "PATH": "/opt/homebrew/bin:/usr/local/bin:${env:PATH}",
    "PKG_CONFIG_PATH": "/opt/homebrew/lib/pkgconfig:/usr/local/lib/pkgconfig"
}
```

### 🎨 **Presentación Mejorada**
- **Paneles Dedicados**: Para ejecución y debugging
- **Colores y Emojis**: Mejor visualización de mensajes
- **Mensajes Informativos**: Estado claro de cada operación

## 🔧 **Configuración Técnica**

### 📁 **Estructura de Archivos**
```
.vscode/
└── tasks.json                 # Configuración de tareas
    ├── configure              # Configuración CMake
    ├── build                  # Compilación
    ├── clean                  # Limpieza
    ├── rebuild                # Reconstrucción
    ├── run                    # Ejecución
    ├── run-debug              # Debug
    ├── check-dependencies     # Verificación
    └── project-info           # Información
```

### ⚙️ **Problem Matchers**
- **$gcc**: Para errores de compilación C++
- **Integración**: Con VS Code Problems panel

### 🔄 **Dependencias**
```
configure → build → run
    ↓       ↓
   clean ← rebuild
```

## 📁 **Scripts de Automatización**

### 🛠️ **Scripts Creados**

El proyecto incluye scripts especializados para evitar problemas con caracteres especiales en zsh:

```
scripts/
├── build.sh           # Script de compilación
├── run.sh            # Script de ejecución
└── project-info.sh   # Script de información
```

#### **build.sh**
```bash
#!/bin/bash
# Compila la aplicación con información detallada
cmake --build build --parallel
```

#### **run.sh**
```bash
#!/bin/bash
# Ejecuta la aplicación con verificaciones
if [ -f "./build/bin/app" ]; then
    ./build/bin/app
else
    echo "❌ Error: Ejecuta 'build' primero"
fi
```

#### **project-info.sh**
```bash
#!/bin/bash
# Muestra estadísticas del proyecto
find src -name "*.cpp" -o -name "*.hpp" | wc -l
ls -lh ./build/bin/app 2>/dev/null || echo "No compilado"
```

## 📚 **Ejemplos de Uso**

### **Compilación Rápida**
```bash
# Equivalente a la tarea "build"
cmake --build build --parallel
```

### **Ejecución Manual**
```bash
# Equivalente a la tarea "run"
./build/bin/app
```

### **Configuración Manual**
```bash
# Equivalente a la tarea "configure"
cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
```

---

**🎯 Tareas optimizadas para desarrollo eficiente - Junio 2025**
