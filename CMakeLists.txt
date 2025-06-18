# ==========================================
# CONFIGURACIÓN PRINCIPAL DEL PROYECTO
# ==========================================
# Sistema de construcción CMake para aplicación wxWidgets + SDL3
# Integra GUI nativa (wxWidgets) con renderizado de alto rendimiento (SDL3)

cmake_minimum_required(VERSION 3.20)  # Versión mínima de CMake requerida
project(wxWidgets_SDL3)               # Nombre del proyecto

# === CONFIGURACIÓN DEL ESTÁNDAR C++ ===
set(CMAKE_CXX_STANDARD 17)            # Usar C++17 para características modernas
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Hacer obligatorio el estándar especificado
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Generar compile_commands.json para IDEs

# ==========================================
# BÚSQUEDA Y CONFIGURACIÓN DE DEPENDENCIAS
# ==========================================

# === SDL3 FRAMEWORK (macOS) ===
# Buscar el framework SDL3 instalado en el sistema macOS
find_library(SDL3_LIBRARY SDL3 REQUIRED)

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
    
    # Aplicación modular (arquitectura separada)
    add_executable(wxWidgets_Modular_Demo
        src/main_modular.cpp      # Punto de entrada modular
        src/my_app.cpp           # Clase aplicación principal
        src/my_frame.cpp         # Clase frame principal
        src/sdl3_manager.cpp     # Manager de SDL3
        src/logger.cpp           # Sistema de logging
    )
    
    # NOTA: La versión original monolítica se movió a archive/ como referencia
    
    # === DIRECTORIOS DE INCLUSIÓN ===
    # Configurar rutas donde buscar archivos de cabecera (.h/.hpp)
    
    # Directorios comunes para el ejecutable modular
    set(COMMON_INCLUDE_DIRS
        ${wxWidgets_INCLUDE_DIRS}                        # Headers de wxWidgets
        ${SPDLOG_INCLUDE_DIRS}                          # Headers de spdlog
        /Library/Frameworks/SDL3.framework/Headers      # SDL3 (Homebrew)
        /System/Library/Frameworks/SDL3.framework/Headers # SDL3 (Sistema)
        src/                                            # Headers locales del proyecto
    )
    
    target_include_directories(wxWidgets_Modular_Demo PRIVATE ${COMMON_INCLUDE_DIRS})
    
    # === ENLAZADO DE LIBRERÍAS ===
    # Vincular todas las librerías necesarias al ejecutable modular
    
    # Librerías necesarias
    set(COMMON_LIBRARIES
        ${wxWidgets_LIBRARIES}  # Librerías de wxWidgets (GUI nativa)
        ${SDL3_LIBRARY}         # SDL3 framework (renderizado)
        ${SPDLOG_LIBRARIES}     # spdlog (sistema de logging)
    )
    
    target_link_libraries(wxWidgets_Modular_Demo ${COMMON_LIBRARIES})
    
    # === CONFIGURACIÓN DE SALIDA ===
    # Definir directorio donde se generará el ejecutable
    set_target_properties(wxWidgets_Modular_Demo PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin  # Ejecutable en /build/bin/
    )
    
    # === CONFIGURACIÓN DE COMPILACIÓN ===
    # Aplicar definiciones y flags específicos de wxWidgets
    target_compile_definitions(wxWidgets_Modular_Demo PRIVATE ${wxWidgets_DEFINITIONS})
    target_compile_options(wxWidgets_Modular_Demo PRIVATE ${wxWidgets_CXX_FLAGS})
    
    # === MENSAJE DE CONFIRMACIÓN ===
    message(STATUS "✅ wxWidgets encontrado - La aplicación modular será construida")
    message(STATUS "   📦 wxWidgets_Modular_Demo - Versión con arquitectura modular")
else()
    # === MENSAJE DE ADVERTENCIA ===
    message(WARNING "⚠️  wxWidgets no encontrado - Los ejemplos wxWidgets no serán construidos")
endif()
