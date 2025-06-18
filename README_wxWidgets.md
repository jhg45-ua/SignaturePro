# wxWidgets + SDL3 - Aplicación de Producción

## Descripción

Este proyecto demuestra cómo integrar **wxWidgets** con **SDL3** para crear aplicaciones de producción profesionales que combinen:

- **GUI nativa y profesional** (wxWidgets)
- **Renderizado de alto rendimiento** (SDL3)
- **Look & Feel nativo** del sistema operativo
- **Controles avanzados** para aplicaciones serias

## Características

### 🎨 Interfaz Profesional
- Menús nativos del sistema
- Barras de herramientas con iconos
- Barra de estado con información
- Panels con splitters redimensionables
- Controles nativos (sliders, botones, etc.)

### 🚀 Renderizado de Alto Rendimiento
- Renderizado SDL3 embebido en panel wxWidgets
- Animaciones fluidas a 60 FPS
- Aceleración por hardware
- Renderizado directo sin overhead adicional

### 💼 Funcionalidades de Producción
- Sistema de archivos (Nuevo/Abrir/Guardar)
- Controles interactivos en tiempo real
- Información de estado y feedback
- Arquitectura escalable y mantenible

### 📝 Sistema de Logging Profesional
- **spdlog** integrado para logging moderno
- Logs colorizados en consola
- Niveles de logging configurables (debug, info, warn, error)
- Formato de timestamps profesional
- Fácil integración con sistemas de monitoreo

## Instalación de Dependencias

### macOS (Homebrew)
```bash
# Instalar wxWidgets
brew install wxwidgets

# SDL3 debería estar ya instalado
brew install sdl3  # Si no lo tienes

# Instalar spdlog para logging profesional
brew install spdlog
```

### Linux (Ubuntu/Debian)
```bash
# wxWidgets
sudo apt-get install libwxgtk3.0-gtk3-dev

# SDL3 (compilar desde fuente o usar PPA)
# Ver: https://github.com/libsdl-org/SDL
```

### Windows
1. Descargar wxWidgets desde: https://www.wxwidgets.org/
2. Compilar o usar binarios precompilados
3. Instalar SDL3 development libraries

## Compilación

### Método 1: Script automatizado (macOS)
```bash
./build_wxwidgets.sh
```

### Método 2: Manual
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

## Ejecución

```bash
cd build
./bin/wxWidgets_SDL3_App
```

## Estructura de la Aplicación

```
MainFrame (wxWidgets)
├── MenuBar (Archivo, Vista, Ayuda)
├── ToolBar (Iconos de acciones)
├── StatusBar (Información de estado)
└── SplitterWindow
    ├── ControlPanel (Controles wxWidgets)
    │   ├── Sliders de velocidad y color
    │   ├── Botones de acción
    │   └── Información de la app
    └── SDLPanel (Renderizado SDL3)
        ├── Animación de rectángulo
        ├── Elementos gráficos
        └── Timer de 60 FPS
```

## Ventajas de esta Arquitectura

### vs Otras Soluciones GUI
- ✅ **GUI nativa** del sistema operativo
- ✅ **Mejor para aplicaciones comerciales**
- ✅ **Widgets más sofisticados** (tablas, árboles, etc.)
- ✅ **Mejor accesibilidad**
- ✅ **Internacionalización completa**

### vs GUI puras
- ✅ **Renderizado de alto rendimiento** para visualización
- ✅ **Flexibilidad total** en el área de render
- ✅ **Aceleración por hardware**
- ✅ **Compatible con engines gráficos**

## Casos de Uso Ideales

- **Editores de contenido** (imágenes, 3D, video)
- **Herramientas CAD/CAM**
- **Aplicaciones científicas** con visualización
- **Simuladores y visualizadores**
- **Herramientas de desarrollo**
- **Aplicaciones multimedia**

## Extensiones Posibles

### Integración con OpenGL
```cpp
// En lugar de SDL_Renderer, usar OpenGL context
SDL_GLContext gl_context = SDL_GL_CreateContext(sdl_window);
// Renderizar con OpenGL directamente
```

### Múltiples viewports SDL
```cpp
// Crear múltiples paneles SDL en la misma aplicación
class MultiViewFrame : public wxFrame {
    SDLPanel* viewport1;
    SDLPanel* viewport2;
    SDLPanel* viewport3;
};
```

### Integración con bibliotecas 3D
- **OpenGL** para renderizado 3D avanzado
- **Vulkan** para máximo rendimiento
- **Metal** en macOS para optimización nativa

## Comparación con Otras Soluciones

| Característica | wxWidgets+SDL3 | Qt+SDL3 | FLTK+SDL3 | GTK+SDL3 |
|----------------|----------------|---------|-----------|----------|
| GUI Nativa | ✅ | ✅ | ⚠️ | ✅ |
| Facilidad | ⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐ |
| Rendimiento | ⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐ |
| Widgets Avanzados | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐ |
| Tamaño | ⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐ |
| Multiplataforma | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐ |

## Licencia

Este es un proyecto de ejemplo. wxWidgets usa licencia wxWindows (similar a LGPL), SDL3 usa licencia Zlib.

## Referencias

- [wxWidgets Documentation](https://docs.wxwidgets.org/)
- [SDL3 Documentation](https://wiki.libsdl.org/SDL3/)
- [wxWidgets Tutorial](https://docs.wxwidgets.org/trunk/page_tutorials.html)
