# ==========================================
# CONFIGURACIÓN PRINCIPAL DEL PROYECTO
# ==========================================
# Sistema de construcción CMake para aplicación wxWidgets
# Aplicación GUI nativa multiplataforma

cmake_minimum_required(VERSION 3.20)  # Versión mínima de CMake requerida
project(wxWidgets_App)                # Nombre del proyecto

# === CONFIGURACIÓN DEL ESTÁNDAR C++ ===
set(CMAKE_CXX_STANDARD 17)            # Usar C++17 para características modernas
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Hacer obligatorio el estándar especificado
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Generar compile_commands.json para IDEs

# ==========================================
# BÚSQUEDA Y CONFIGURACIÓN DE DEPENDENCIAS
# ==========================================

# === SPDLOG (LOGGING) ===
# Buscar spdlog para logging (instalado vía Homebrew)
find_package(PkgConfig REQUIRED)          # PkgConfig necesario para spdlog
pkg_check_modules(SPDLOG REQUIRED spdlog) # Configurar spdlog

# ==========================================
# CONFIGURACIÓN DE APLICACIONES WXWIDGETS
# ==========================================

# === BÚSQUEDA DE WXWIDGETS ===
# Buscar wxWidgets con componentes core (ventanas, eventos) y base (utilidades)
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Si wxWidgets se encuentra correctamente, proceder con la configuración
if(wxWidgets_FOUND)
    # Incluir configuración automática de wxWidgets
    include(${wxWidgets_USE_FILE})
    
    # === CREACIÓN DE EJECUTABLES ===
    
    # Aplicación wxWidgets
    add_executable(app
        src/main.cpp      # Punto de entrada
        src/my_app.cpp           # Clase aplicación principal
        src/my_frame.cpp         # Clase frame principal
        src/logger.cpp           # Sistema de logging
    )
    
    # === DIRECTORIOS DE INCLUSIÓN ===
    # Configurar rutas donde buscar archivos de cabecera (.h/.hpp)
    
    # Directorios para el ejecutable
    set(COMMON_INCLUDE_DIRS
        ${wxWidgets_INCLUDE_DIRS}                        # Headers de wxWidgets
        ${SPDLOG_INCLUDE_DIRS}                          # Headers de spdlog
        src/                                            # Headers locales del proyecto
    )
    
    target_include_directories(app PRIVATE ${COMMON_INCLUDE_DIRS})
    
    # === ENLAZADO DE LIBRERÍAS ===
    # Vincular todas las librerías necesarias al ejecutable
    
    # Librerías necesarias
    set(COMMON_LIBRARIES
        ${wxWidgets_LIBRARIES}  # Librerías de wxWidgets (GUI nativa)
        ${SPDLOG_LIBRARIES}     # spdlog (sistema de logging)
    )
    
    target_link_libraries(app ${COMMON_LIBRARIES})
    
    # === CONFIGURACIÓN DE SALIDA ===
    # Definir directorio donde se generará el ejecutable
    set_target_properties(app PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin  # Ejecutable en /build/bin/
    )
    
    # === CONFIGURACIÓN DE COMPILACIÓN ===
    # Aplicar definiciones y flags específicos de wxWidgets
    target_compile_definitions(app PRIVATE ${wxWidgets_DEFINITIONS})
    target_compile_options(app PRIVATE ${wxWidgets_CXX_FLAGS})
    
    # === MENSAJE DE CONFIRMACIÓN ===
    message(STATUS "✅ wxWidgets encontrado - La aplicación será construida")
    message(STATUS "   📦 app - Aplicación wxWidgets")
else()
    # === MENSAJE DE ADVERTENCIA ===
    message(WARNING "⚠️  wxWidgets no encontrado - La aplicación no será construida")
endif()
