# 🛠️ Scripts del Proyecto SignaturePro

## 📋 **Scripts Disponibles**

Esta carpeta contiene scripts de utilidad para el proyecto SignaturePro.

### 📊 **project-info.sh** - Información del Proyecto
```bash
./scripts/project-info.sh
```

**Funcionalidad**:
- ✅ Información completa del proyecto
- ✅ Estadísticas de código fuente
- ✅ Estado del build
- ✅ Resumen de archivos y líneas
- ✅ Información de dependencias

### 🍎 **build-macos-app.sh** - Build de Aplicación macOS
```bash
./scripts/build-macos-app.sh
```

**Funcionalidad**:
- ✅ Configuración automática CMake (Release)
- ✅ Build optimizado para macOS
- ✅ Creación de bundle SignaturePro.app
- ✅ Verificación de build exitoso

### � **sign-and-notarize.sh** - Firma y Notarización
```bash
# Firma ad-hoc (desarrollo/testing)
./scripts/sign-and-notarize.sh adhoc

# Firma con Developer ID (requiere certificado)
./scripts/sign-and-notarize.sh developer

# Firma completa + notarización (distribución)
./scripts/sign-and-notarize.sh full
```

**Funcionalidad**:
- ✅ Firma ad-hoc para desarrollo local
- ✅ Firma con certificado Developer ID
- ✅ Notarización con Apple para distribución
- ✅ Firma de archivos DMG

**Variables de entorno para firma completa**:
- `DEVELOPER_ID` - Certificado de desarrollador
- `APPLE_ID` - Tu Apple ID
- `TEAM_ID` - Tu Team ID de desarrollador
- `APP_PASSWORD` - App-specific password

### 📦 **create-dmg.sh** - Creación de DMG
```bash
./scripts/create-dmg.sh
```

**Funcionalidad**:
- ✅ Creación de DMG de distribución
- ✅ Configuración visual del instalador
- ✅ Inclusión de enlace a Applications

## 🔧 **Proceso de Build Simplificado**

El proyecto usa CMake para el build:

1. **Configurar**: `cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release`
2. **Compilar**: `cmake --build build --parallel`
3. **Ejecutar**: `./build/bin/SignaturePro.app/Contents/MacOS/SignaturePro`

O usar las tareas de VS Code:
- `Ctrl+Shift+P` → "Tasks: Run Task" → Seleccionar tarea deseada

## ⚠️ **Nota sobre Firma de Código en macOS**

Para distribución en macOS, las aplicaciones deben estar firmadas:

- **Desarrollo local**: Usa firma ad-hoc (`./scripts/sign-and-notarize.sh adhoc`)
- **Distribución interna**: Usa certificado Developer ID
- **Distribución pública**: Requiere firma + notarización

Sin firma, macOS mostrará advertencias de seguridad al ejecutar la app.
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