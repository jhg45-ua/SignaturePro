# SignaturePro - Clean Architecture wxWidgets

Una aplicación profesional que implementa **Clean Architecture** con wxWidgets, demostrando las mejores prácticas para desarrollar interfaces gráficas nativas multiplataforma.

## 📚 Documentación Disponible

| Archivo | Propósito | Audiencia |
|---------|-----------|-----------|
| **[📖 Documentación Técnica](DOCUMENTACION_COMPLETA.md)** | Clean Architecture completa y componentes del sistema | Desarrolladores |
| **[🛠️ Guía de Desarrollo](GUIA_DESARROLLO.md)** | Flujo de desarrollo y mejores prácticas | Desarrolladores activos |
| **[🔧 Solución de Problemas](SOLUCION_PROBLEMAS.md)** | Problemas comunes y soluciones | Todos |
| **[🚀 Release macOS](RELEASE_MACOS.md)** | Distribución para macOS (.app y DMG) | DevOps/Release |
| **[📊 Resumen Ejecutivo](RESUMEN_EJECUTIVO.md)** | Análisis de valor empresarial y Clean Architecture | Gestores/Directivos |

## 🏗️ Arquitectura

Implementa **Clean Architecture** de Robert C. Martin con separación clara de responsabilidades:

- **🎯 Domain Layer** - Entidades y casos de uso puros
- **💾 Data Layer** - Repositorios y modelos de datos
- **🎨 Presentation Layer** - Controladores de coordinación
- **🖥️ UI Layer** - Interfaz wxWidgets nativa

## 🚀 Inicio Rápido

### Requisitos
- **wxWidgets 3.2.8+**
- **CMake 3.16+**
- **Compilador C++17**
- **spdlog** (para logging)

### Compilación y Ejecución

```bash
# 1. Configurar proyecto
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# 2. Compilar
cmake --build build --parallel

# 3. Ejecutar
./build/bin/app
```

### Usando VS Code
El proyecto incluye tareas predefinidas:
- `configure` - Configurar el proyecto CMake
- `build` - Compilar la aplicación
- `run` - Ejecutar la aplicación
- `build-macos-app` - Crear aplicación macOS (.app)

## 📁 Estructura Clean Architecture

```
src/
├── main.cpp                         # Punto de entrada
├── domain/                         # 🎯 DOMAIN LAYER
│   ├── entities/                   # Entidades de negocio
│   ├── repositories/               # Interfaces de repositorios
│   └── usecases/                   # Casos de uso
├── data/                          # 💾 DATA LAYER
│   ├── models/                    # Modelos de datos (DTOs)
│   └── repositories/              # Implementaciones
├── presentation/                  # 🎨 PRESENTATION LAYER
│   ├── my_app.hpp/cpp            # Aplicación principal
│   └── controllers/              # Controladores de presentación
├── ui/                           # 🖥️ UI LAYER
│   ├── my_frame.hpp/cpp          # Ventana principal
│   ├── second_frame.hpp/cpp      # Segunda ventana
│   └── modal_dialog.hpp/cpp      # Diálogo modal
├── controllers/                  # 🔗 BRIDGE CONTROLLERS
├── services/                     # 🔧 SERVICES
└── core/                        # ⚙️ CORE UTILITIES
```

## ✨ Características

- **🏛️ Clean Architecture** - Separación de capas y responsabilidades claras
- **🎨 Tema Oscuro Moderno** - Interfaz profesional con colores consistentes
- **🪟 Navegación Multi-ventana** - Ventana principal, segunda ventana y diálogos
- **📊 Sistema de Logging** - Logging robusto con spdlog
- **🏗️ Arquitectura Modular** - Código organizado y mantenible
- **📱 Interfaz Nativa** - Componentes nativos del sistema operativo
- **🛠️ Build Automatizado** - Scripts para CMake y distribución macOS

## 📖 Documentación

### 📚 Archivos Principales

| Archivo | Propósito | Audiencia |
|---------|-----------|-----------|
| **[📖 Documentación Técnica](DOCUMENTACION_COMPLETA.md)** | Clean Architecture y componentes del sistema | Desarrolladores |
| **[🏗️ Clean Architecture Implementación](CLEAN_ARCHITECTURE_IMPLEMENTATION.md)** | Guía detallada de la arquitectura aplicada | Arquitectos/Desarrolladores Senior |
| **[� Diagramas Clean Architecture](CLEAN_ARCHITECTURE_DIAGRAMS.md)** | Diagramas visuales de la arquitectura | Todos los niveles técnicos |
| **[�🛠️ Guía de Desarrollo](GUIA_DESARROLLO.md)** | Flujo de desarrollo y mejores prácticas | Desarrolladores activos |
| **[🔧 Solución de Problemas](SOLUCION_PROBLEMAS.md)** | Problemas comunes y soluciones | Todos |
| **[🚀 Release macOS](RELEASE_MACOS.md)** | Distribución para macOS (.app y DMG) | DevOps/Release |
| **[📊 Resumen Ejecutivo](RESUMEN_EJECUTIVO.md)** | Análisis de valor empresarial y Clean Architecture | Gestores/Directivos |

### 🗺️ Flujo de Lectura Recomendado

**Para Nuevos Desarrolladores:**
1. **README.md** (este archivo) - Configuración inicial y conceptos básicos
2. **[DOCUMENTACION_COMPLETA.md](DOCUMENTACION_COMPLETA.md)** - Arquitectura completa y implementación
3. **[GUIA_DESARROLLO.md](GUIA_DESARROLLO.md)** - Flujo de trabajo y herramientas

**Para Arquitectos/Líderes Técnicos:**
1. **[DOCUMENTACION_COMPLETA.md](DOCUMENTACION_COMPLETA.md)** - Visión arquitectónica completa
2. **[RESUMEN_EJECUTIVO.md](RESUMEN_EJECUTIVO.md)** - Valor empresarial

**Para Solucionar Problemas:**
- **[SOLUCION_PROBLEMAS.md](SOLUCION_PROBLEMAS.md)** - Primera parada para errores

**Para Distribución:**
- **[RELEASE_MACOS.md](RELEASE_MACOS.md)** - Creación de releases y DMG

**Para Gestión:**
- **[RESUMEN_EJECUTIVO.md](RESUMEN_EJECUTIVO.md)** - Valor técnico, ROI y arquitectura empresarial

## 🤝 Contribuir

1. Fork del repositorio
2. Crear rama feature (`git checkout -b feature/nueva-caracteristica`)
3. Commit cambios (`git commit -am 'Add nueva característica'`)
4. Push a la rama (`git push origin feature/nueva-caracteristica`)
5. Crear Pull Request

## 📄 Licencia

Este proyecto está bajo la licencia [Apache 2.0](../LICENSE).
