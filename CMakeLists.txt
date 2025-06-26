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
        src/second_frame.cpp     # Segunda ventana/página
        src/modal_dialog.cpp     # Diálogo modal
        src/logger.cpp           # Sistema de logging
        # Nota: theme.hpp es solo headers, no necesita compilación
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
    
    # === CONFIGURACIÓN ESPECÍFICA PARA MACOS ===
    # Configurar bundle de aplicación para macOS en builds Release
    if(APPLE AND CMAKE_BUILD_TYPE STREQUAL "Release")
        set_target_properties(app PROPERTIES
            MACOSX_BUNDLE TRUE                             # Crear bundle de macOS (.app)
            MACOSX_BUNDLE_BUNDLE_NAME "SignaturePro"       # Nombre de la aplicación
            MACOSX_BUNDLE_GUI_IDENTIFIER "com.signaturepro.app"  # Identificador único
            MACOSX_BUNDLE_BUNDLE_VERSION "1.0"             # Versión del bundle
            MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0"       # Versión corta
            MACOSX_BUNDLE_LONG_VERSION_STRING "1.0.0"      # Versión completa
            MACOSX_BUNDLE_COPYRIGHT "© 2025 SignaturePro"  # Copyright
            MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/resources/macos/Info.plist"  # Info.plist personalizado
            MACOSX_BUNDLE_ICON_FILE "signature.icns"       # Archivo de icono
            OUTPUT_NAME "SignaturePro"                     # Nombre del ejecutable
        )
        
        # Copiar el icono al bundle
        set(ICON_FILE "${CMAKE_SOURCE_DIR}/resources/signature.icns")
        set_source_files_properties(${ICON_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
        target_sources(app PRIVATE ${ICON_FILE})
        
        # Mensaje informativo
        message(STATUS "🍎 Configurando bundle de macOS para Release")
        message(STATUS "   📄 Usando Info.plist: ${CMAKE_SOURCE_DIR}/resources/macos/Info.plist")
        message(STATUS "   🎨 Usando icono: ${ICON_FILE}")
    endif()
    
    # === CONFIGURACIÓN DE COMPILACIÓN ===
    # Aplicar definiciones y flags específicos de wxWidgets
    target_compile_definitions(app PRIVATE ${wxWidgets_DEFINITIONS})
    target_compile_options(app PRIVATE ${wxWidgets_CXX_FLAGS})
    
    # === MENSAJE DE CONFIRMACIÓN ===
    message(STATUS "✅ wxWidgets encontrado - La aplicación será construida")
    message(STATUS "   📦 app - Aplicación wxWidgets")
    
    # === INFORMACIÓN ESPECÍFICA PARA MACOS ===
    if(APPLE AND CMAKE_BUILD_TYPE STREQUAL "Release")
        message(STATUS "")
        message(STATUS "🍎 CONFIGURACIÓN MACOS ACTIVADA:")
        message(STATUS "   • Bundle: SignaturePro.app será creado en build/bin/")
        message(STATUS "   • Para crear DMG: usar 'cpack' después del build")
        message(STATUS "   • Ubicación: ${CMAKE_BINARY_DIR}/bin/SignaturePro.app")
    endif()
else()
    # === MENSAJE DE ADVERTENCIA ===
    message(WARNING "⚠️  wxWidgets no encontrado - La aplicación no será construida")
endif()

# ==========================================
# CONFIGURACIÓN DE EMPAQUETADO (CPACK)
# ==========================================

# === CPACK PARA MACOS ===
# Configuración para crear instaladores/DMG en macOS
if(APPLE)
    set(CPACK_GENERATOR "DragNDrop")                    # Crear archivo DMG
    set(CPACK_PACKAGE_NAME "SignaturePro")             # Nombre del paquete
    set(CPACK_PACKAGE_VERSION "1.0.0")                 # Versión
    set(CPACK_PACKAGE_VENDOR "SignaturePro Team")      # Desarrollador
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Aplicación de firma digital") # Descripción
    set(CPACK_DMG_VOLUME_NAME "SignaturePro Installer") # Nombre del volumen DMG
    set(CPACK_DMG_FORMAT "UDZO")                        # Formato comprimido
    
    # Incluir CPack para habilitar la creación de paquetes
    include(CPack)
    
    message(STATUS "📦 CPack configurado para crear DMG en macOS")
    message(STATUS "   Usar: 'cpack' para generar el instalador")
endif()
