/**
 * EJEMPLO DE USO DE COMPONENTES MODULARES
 * 
 * Este archivo demuestra cómo usar los componentes modulares
 * creados para construir aplicaciones personalizadas.
 */

#include "logger.hpp"
#include "constants.hpp"
#include <iostream>
#include <string>


// Ejemplo de uso de constantes centralizadas
void ejemplo_constantes() {
    std::cout << "\n=== EJEMPLO: Constantes Centralizadas ===" << std::endl;
    
    std::cout << "Título de ventana: " << Constants::Window::TITLE << std::endl;
    std::cout << "Tamaño por defecto: " << Constants::Window::DEFAULT_WIDTH 
              << "x" << Constants::Window::DEFAULT_HEIGHT << std::endl;
    std::cout << "Texto informativo: " << Constants::Text::INFO_TEXT << std::endl;
}

// Ejemplo de configuración de logging personalizada
void ejemplo_logging_personalizado() {
    std::cout << "\n=== EJEMPLO: Logging Personalizado ===" << std::endl;
    
    // Inicializar con configuración personalizada
    Logger::Initialize();
    Logger::SetLevel(spdlog::level::debug);
    
    // Usar diferentes niveles de logging
    spdlog::debug("Mensaje de debug");
    spdlog::info("Mensaje informativo");
    spdlog::warn("Mensaje de advertencia");
    spdlog::error("Mensaje de error");
}

// Función principal para demostrar el uso
int main() {
    std::cout << "🎯 DEMOSTRACIÓN DE COMPONENTES MODULARES" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    // Ejecutar ejemplos
    ejemplo_constantes();
    ejemplo_logging_personalizado();
    
    std::cout << "\n✅ Demostración completada exitosamente!" << std::endl;
    std::cout << "💡 Los componentes modulares pueden ser reutilizados" << std::endl;
    std::cout << "   en cualquier proyecto que necesite estas funcionalidades." << std::endl;
    
    return 0;
}

/*
COMPILACIÓN DE ESTE EJEMPLO:

Para compilar este ejemplo independientemente:

g++ -std=c++17 \
    ejemplo_uso_modular.cpp \
    logger.cpp \
    sdl3_manager.cpp \
    -lSDL3 \
    -lspdlog \
    -o ejemplo_modular

O agregar al CMakeLists.txt:

add_executable(ejemplo_modular
    src/ejemplo_uso_modular.cpp
    src/logger.cpp
    src/sdl3_manager.cpp
)

target_link_libraries(ejemplo_modular 
    ${SDL3_LIBRARY}
    ${SPDLOG_LIBRARIES}
)
*/
