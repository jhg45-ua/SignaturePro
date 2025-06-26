# Construcción de App macOS - SignaturePro

## 📋 Descripción

Esta configuración permite crear automáticamente una aplicación nativa de macOS (`.app` bundle) cuando se construye el proyecto en modo `Release`.

## 🚀 Uso Rápido

### Opción 1: Script Automatizado
```bash
./scripts/build-macos-app.sh
```

### Opción 2: Tareas de VS Code
1. Abrir Command Palette (`Cmd+Shift+P`)
2. Buscar "Tasks: Run Task"
3. Seleccionar `build-macos-app`

### Opción 3: Comandos Manuales
```bash
# Limpiar build anterior (opcional)
rm -rf build

# Configurar para Release
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# Construir
cmake --build build --parallel

# La aplicación estará en: build/bin/SignaturePro.app
```

## 📁 Estructura Generada

```
build/bin/SignaturePro.app/
├── Contents/
│   ├── Info.plist          # Metadatos de la aplicación
│   ├── MacOS/
│   │   └── SignaturePro    # Ejecutable principal
│   └── Resources/          # Recursos (iconos, etc.)
│       └── signature.icns  # Icono de la aplicación
```

## 🔧 Configuración

### Archivo Info.plist
La configuración se encuentra en `resources/macos/Info.plist` y incluye:
- Identificador de bundle: `com.signaturepro.app`
- Versión: 1.0.0
- Compatibilidad con pantallas de alta resolución
- Categoría: Productividad
- macOS mínimo requerido: 10.15
- **Icono personalizado**: `signature.icns`

### Icono de la Aplicación
- **Archivo**: `resources/signature.icns`
- **Configuración automática**: Se copia al bundle en `Resources/`
- **Referencia**: Configurada en Info.plist como `CFBundleIconFile`

### CMakeLists.txt
La configuración de macOS se activa automáticamente cuando:
- Se ejecuta en macOS (`APPLE`)
- El tipo de build es `Release`

## 📦 Distribución

### Crear DMG
```bash
# Después del build
cd build
cpack
```

Esto generará un archivo `.dmg` listo para distribución.

### Tareas Disponibles en VS Code
- `build-macos-app`: Construye la aplicación completa
- `open-macos-app`: Abre la aplicación construida
- `configure`: Configura el proyecto (con selección de tipo)
- `build`: Construye sin configurar bundle
- `run`: Ejecuta desde terminal

## 🎯 Características

### ✅ Incluido
- Bundle nativo de macOS (.app)
- Info.plist personalizado
- **Icono personalizado** (`signature.icns`)
- Soporte para pantallas Retina
- Configuración automática de Release
- Generación de DMG con CPack
- Tareas de VS Code integradas

### 🔄 Próximas Mejoras
- ~~Icono personalizado~~ ✅ **IMPLEMENTADO**
- Firma de código
- Notarización para distribución
- Configuración de permisos específicos

## 🐛 Resolución de Problemas

### Error: "No se pudo crear SignaturePro.app"
- Verificar que wxWidgets esté instalado
- Verificar que se esté usando `CMAKE_BUILD_TYPE=Release`
- Revisar que el directorio `build` tenga permisos de escritura

### Error en CPack
- Asegurarse de estar en el directorio `build`
- Verificar que la aplicación se haya construido correctamente

## 📝 Notas Técnicas

- La aplicación solo se crea como bundle en builds `Release`
- En builds `Debug` se genera un ejecutable normal en `build/bin/app`
- El script automatizado siempre usa `Release`
- CPack está configurado para generar DMG comprimido (UDZO)
