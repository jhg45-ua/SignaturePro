# SignaturePro - Aplicación wxWidgets

Una aplicación de demostración que muestra las mejores prácticas para desarrollar interfaces gráficas nativas multiplataforma con wxWidgets.

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

## 📁 Estructura del Proyecto

```
SignaturePro/
├── src/                    # Código fuente
│   ├── my_app.cpp/hpp     # Aplicación principal
│   ├── controllers/       # Controladores
│   ├── core/             # Componentes core (logger, constantes)
│   ├── services/         # Servicios
│   └── ui/               # Componentes de interfaz
├── resources/            # Recursos (iconos, archivos)
├── scripts/             # Scripts de construcción
└── docs/               # Documentación
```

## ✨ Características

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
| **[📖 Documentación Técnica](DOCUMENTACION_COMPLETA.md)** | Arquitectura y componentes del sistema | Desarrolladores |
| **[🛠️ Guía de Desarrollo](GUIA_DESARROLLO.md)** | Flujo de desarrollo y mejores prácticas | Desarrolladores activos |
| **[🔧 Solución de Problemas](SOLUCION_PROBLEMAS.md)** | Problemas comunes y soluciones | Todos |
| **[🚀 Release macOS](RELEASE_MACOS.md)** | Distribución para macOS (.app y DMG) | DevOps/Release |
| **[📊 Resumen Ejecutivo](RESUMEN_EJECUTIVO.md)** | Análisis de valor y métricas del proyecto | Gestores/Directivos |

### 🗺️ Flujo de Lectura Recomendado

**Para Nuevos Desarrolladores:**
1. **README.md** (este archivo) - Configuración inicial y conceptos básicos
2. **[GUIA_DESARROLLO.md](GUIA_DESARROLLO.md)** - Flujo de trabajo y herramientas
3. **[DOCUMENTACION_COMPLETA.md](DOCUMENTACION_COMPLETA.md)** - Arquitectura detallada

**Para Solucionar Problemas:**
- **[SOLUCION_PROBLEMAS.md](SOLUCION_PROBLEMAS.md)** - Primera parada para errores

**Para Distribución:**
- **[RELEASE_MACOS.md](RELEASE_MACOS.md)** - Creación de releases y DMG

**Para Gestión:**
- **[RESUMEN_EJECUTIVO.md](RESUMEN_EJECUTIVO.md)** - Valor técnico y ROI del proyecto

## 🤝 Contribuir

1. Fork del repositorio
2. Crear rama feature (`git checkout -b feature/nueva-caracteristica`)
3. Commit cambios (`git commit -am 'Add nueva característica'`)
4. Push a la rama (`git push origin feature/nueva-caracteristica`)
5. Crear Pull Request

## 📄 Licencia

Este proyecto está bajo la licencia [Apache 2.0](../LICENSE).
