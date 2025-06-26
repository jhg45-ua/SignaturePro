# 🍎 SignaturePro - Release para macOS

## 📋 Descripción General

SignaturePro es una aplicación de firma digital desarrollada con wxWidgets que se puede distribuir como una aplicación nativa de macOS (.app bundle) con instalador DMG profesional.

## 🎯 Características de la Release macOS

### ✅ Funcionalidades Implementadas
- **Bundle nativo de macOS** (.app) con todas las convenciones del sistema
- **Icono personalizado** (`signature.icns`) integrado automáticamente
- **Info.plist completo** con metadatos y configuración del sistema
- **DMG de distribución** con fondo personalizado y diseño profesional
- **Enlace a Applications** para instalación fácil tipo drag-and-drop
- **Versión 0.0.1** configurada en todo el sistema
- **Compatibilidad con Retina** y pantallas de alta resolución
- **Construcción automática** mediante scripts y tareas de VS Code

### 📦 Estructura del Bundle

```
SignaturePro.app/
├── Contents/
│   ├── Info.plist              # Metadatos y configuración
│   ├── MacOS/
│   │   └── SignaturePro        # Ejecutable principal
│   └── Resources/
│       └── signature.icns      # Icono personalizado
```

### 💿 Contenido del DMG

```
SignaturePro.dmg (montado)
├── SignaturePro.app            # Aplicación lista para usar
├── Applications (enlace)       # Enlace simbólico para instalación
└── .background/                # Imagen de fondo (oculta)
    └── dmg_background.png
```

## 🚀 Guía de Construcción

### Método 1: Script Automatizado (Recomendado)
```bash
# Construir aplicación completa
./scripts/build-macos-app.sh

# Solo crear DMG (si ya existe build)
./scripts/create-dmg.sh
```

### Método 2: Tareas de VS Code
1. Abrir Command Palette: `Cmd+Shift+P`
2. Buscar "Tasks: Run Task"
3. Opciones disponibles:
   - `build-macos-app`: Construir aplicación completa
   - `create-dmg`: Crear solo el DMG
   - `open-macos-app`: Abrir aplicación construida

### Método 3: Comandos Manuales
```bash
# Limpiar y configurar
rm -rf build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# Construir aplicación
cmake --build build --parallel

# Crear DMG
cd build && cpack
```

## ⚙️ Configuración Técnica

### CMakeLists.txt - Configuración Principal

La configuración automática se activa cuando:
- Se ejecuta en macOS (`APPLE`)
- El tipo de build es `Release`

#### Propiedades del Bundle:
```cmake
MACOSX_BUNDLE TRUE
MACOSX_BUNDLE_BUNDLE_NAME "SignaturePro"
MACOSX_BUNDLE_GUI_IDENTIFIER "com.signaturepro.app"
MACOSX_BUNDLE_BUNDLE_VERSION "0.0.1"
MACOSX_BUNDLE_ICON_FILE "signature.icns"
```

#### Configuración DMG:
```cmake
CPACK_GENERATOR "DragNDrop"
CPACK_PACKAGE_VERSION "0.0.1"
CPACK_DMG_VOLUME_NAME "SignaturePro"
CPACK_DMG_FORMAT "UDZO"
CPACK_DMG_BACKGROUND_IMAGE "resources/dmg_background.png"
```

### Info.plist - Metadatos de la Aplicación

Ubicación: `resources/macos/Info.plist`

Configuraciones clave:
- **Identificador**: `com.signaturepro.app`
- **Versión**: `0.0.1`
- **Icono**: `signature` (referencia a signature.icns)
- **Pantallas Retina**: Habilitado (`NSHighResolutionCapable`)
- **macOS mínimo**: 10.15
- **Categoría**: Productividad (`public.app-category.productivity`)

## 📁 Estructura de Archivos

### Archivos de Configuración
```
resources/
├── macos/
│   └── Info.plist              # Metadatos del bundle
├── signature.icns              # Icono de la aplicación
└── dmg_background.png          # Fondo del DMG

scripts/
├── build-macos-app.sh         # Script principal de construcción
└── create-dmg.sh              # Script dedicado para DMG

.vscode/
└── tasks.json                 # Tareas integradas de VS Code
```

### Archivos Generados
```
build/
├── bin/
│   └── SignaturePro.app       # Bundle de la aplicación
└── SignaturePro-0.0.1-Darwin.dmg  # Instalador DMG
```

## 📋 Información de Versión

### Versión Actual: 0.0.1

Esta versión está configurada en:
- `CMakeLists.txt` (líneas 79, 80, 81, 135)
- `resources/macos/Info.plist` (líneas 14, 17, 32)
- `scripts/create-dmg.sh` (líneas 37, 47)
- Nombre del archivo DMG generado

### Actualizar Versión

Para cambiar la versión, modificar en estos archivos:
1. **CMakeLists.txt**: 
   - `MACOSX_BUNDLE_BUNDLE_VERSION`
   - `MACOSX_BUNDLE_SHORT_VERSION_STRING`
   - `MACOSX_BUNDLE_LONG_VERSION_STRING`
   - `CPACK_PACKAGE_VERSION`

2. **Info.plist**:
   - `CFBundleVersion`
   - `CFBundleShortVersionString`
   - `CFBundleGetInfoString`

3. **Scripts**: Actualizar referencias al nombre del DMG

## 🎨 Personalización Visual

### Icono de la Aplicación
- **Archivo**: `resources/signature.icns`
- **Formato**: ICNS (formato nativo de macOS)
- **Tamaños**: Múltiples resoluciones (16x16 hasta 1024x1024)
- **Aplicación automática**: Se copia al bundle en cada build

### Fondo del DMG
- **Archivo**: `resources/dmg_background.png`
- **Dimensiones recomendadas**: 500x300 píxeles
- **Contenido sugerido**: Logo, versión, instrucciones de instalación
- **Aplicación**: Automática durante la creación del DMG

## 📤 Distribución

### Para Desarrolladores
```bash
# Crear release completa
./scripts/build-macos-app.sh

# El archivo DMG estará en:
build/SignaturePro-0.0.1-Darwin.dmg
```

### Para Usuarios Finales

#### Instalación desde DMG:
1. **Descargar** el archivo `SignaturePro-0.0.1-Darwin.dmg`
2. **Hacer doble clic** para montar el DMG
3. **Arrastrar** `SignaturePro.app` a la carpeta `Applications`
4. **Listo** - La aplicación estará disponible en Launchpad

#### Ejecución:
- Desde **Launchpad**: Buscar "SignaturePro"
- Desde **Finder**: Applications → SignaturePro
- Desde **Spotlight**: `Cmd+Space` → "SignaturePro"

## 🔧 Resolución de Problemas

### Error: "No se pudo crear SignaturePro.app"
**Causas posibles:**
- wxWidgets no instalado o no encontrado
- No se está usando `CMAKE_BUILD_TYPE=Release`
- Permisos insuficientes en directorio `build`

**Solución:**
```bash
# Verificar wxWidgets
brew install wxwidgets

# Limpiar y reconstruir
rm -rf build
./scripts/build-macos-app.sh
```

### Error: "DMG no se puede abrir o está dañado"
**Causas posibles:**
- DMG corrupto durante la creación
- Falta imagen de fondo

**Solución:**
```bash
# Recrear DMG
cd build
rm -f *.dmg
cpack
```

### Aplicación no se ejecuta
**Causas posibles:**
- Dependencias faltantes
- macOS demasiado antiguo
- Problemas de permisos/firma

**Solución:**
```bash
# Verificar dependencias
otool -L build/bin/SignaturePro.app/Contents/MacOS/SignaturePro

# Verificar compatibilidad
# Mínimo requerido: macOS 10.15
```

## 🔄 Desarrollo Futuro

### Próximas Mejoras Planificadas
- [ ] **Firma de código** con certificado de desarrollador
- [ ] **Notarización** para distribución sin advertencias
- [ ] **Instalador PKG** como alternativa al DMG
- [ ] **Actualizaciones automáticas** con Sparkle framework
- [ ] **Sandbox** para mayor seguridad
- [ ] **Traducción** del instalador a múltiples idiomas

### Mejoras de UX
- [ ] **Animación** del icono durante la instalación
- [ ] **Verificación** de integridad post-instalación
- [ ] **Desinstalador** automático
- [ ] **Preferencias** de sistema integradas

## 📚 Referencias Técnicas

### Documentación Apple
- [Bundle Programming Guide](https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/)
- [Information Property List Key Reference](https://developer.apple.com/library/archive/documentation/General/Reference/InfoPlistKeyReference/)
- [Icon Design Guidelines](https://developer.apple.com/design/human-interface-guidelines/macos/icons-and-images/app-icon/)

### Herramientas Utilizadas
- **CMake**: Sistema de construcción multiplataforma
- **CPack**: Generador de paquetes integrado con CMake
- **wxWidgets**: Framework GUI multiplataforma
- **spdlog**: Biblioteca de logging
- **VS Code**: Entorno de desarrollo integrado

---

## 🎉 Conclusión

La configuración de release para macOS de SignaturePro proporciona una experiencia completa y profesional que cumple con todas las convenciones y expectativas del ecosistema Apple. La aplicación se distribuye como un bundle nativo `.app` con icono personalizado, metadatos completos y un instalador DMG con diseño profesional.

El proceso de construcción está completamente automatizado y puede ejecutarse con un solo comando, generando tanto la aplicación como el instalador listo para distribución.

**Versión actual**: 0.0.1  
**Última actualización**: Junio 26, 2025  
**Estado**: ✅ Completamente funcional y listo para distribución
