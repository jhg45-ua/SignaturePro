# 🛠️ Guía de Desarrollo

## Flujo de Desarrollo Rápido

### 1. Configurar Entorno

```bash
# Instalar dependencias (macOS)
brew install wxwidgets cmake spdlog

# Configurar proyecto
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

### 2. Compilar y Ejecutar

```bash
# Compilar
cmake --build build --parallel

# Ejecutar
./build/bin/app
```

### 3. Desarrollo en VS Code

**Tareas disponibles:**
- `Ctrl+Shift+P` → "Tasks: Run Task" → Seleccionar tarea
- `configure` - Configurar CMake
- `build` - Compilar proyecto
- `run` - Ejecutar aplicación
- `clean` - Limpiar build

### 4. Añadir Nuevas Características

#### Nueva Pantalla UI:
1. Crear archivos `.hpp/.cpp` en `src/presentation/screens/`
2. Heredar de `wxFrame` o `wxDialog`
3. Aplicar tema oscuro usando `theme.hpp`

#### Nuevo Servicio:
1. Crear archivos en `src/services/`
2. Registrar en controlador principal

#### Nuevo Controlador:
1. Crear archivos en `src/controllers/`
2. Conectar con servicios y UI

## Tema Oscuro

```cpp
// src/config/theme.hpp
void ApplyDarkTheme(wxButton* button) {
    button->SetBackgroundColour(DARK_BUTTON_BG);
    button->SetForegroundColour(DARK_TEXT_PRIMARY);
}
```

**Colores**: `#2b2b2b` (fondo), `#ffffff` (texto), `#404040` (botones)

## Debugging y Logging

```cpp
Logger::Info("Acción completada exitosamente");
Logger::Warning("Advertencia de configuración");
Logger::Error("Error crítico");
```

**VS Code Debugging**: F5 para iniciar, configurar breakpoints

## Distribución macOS

```bash
# Crear aplicación .app
./scripts/build-macos-app.sh

# Crear DMG
./scripts/create-dmg.sh
```

## Mejores Prácticas

- Usar RAII para gestión de recursos
- Aplicar tema oscuro consistentemente  
- Centralizar configuraciones en `constants.hpp`
- Mantener separación de responsabilidades UI/lógica

## Estructura del Proyecto

### Capas de Clean Architecture

```
📁 src/
├── 🎯 domain/          # Lógica de negocio pura
├── 💾 data/            # Repositorios e implementaciones
├── 🎨 presentation/    # Controladores y pantallas
│   ├── controllers/    # Coordinadores
│   └── screens/        # Componentes visuales (frames/dialogs)
├── 🎛️ controllers/     # Puentes legacy
├── 🔧 services/        # Servicios de aplicación
└── ⚙️ config/          # Configuración y utilidades
```

### Añadir Configuraciones

Para centralizar configuraciones:
1. Añadir constantes en `src/config/constants.hpp`
2. Actualizar temas en `src/config/theme.hpp` 
3. Configurar logging en `src/config/logger.hpp`
