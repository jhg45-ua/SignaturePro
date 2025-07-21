/**
 * IMPLEMENTACIÓN DEL LOGGER HELPER
 */

#include "logger.hpp"

// Inicialización de la variable estática
std::shared_ptr<spdlog::logger> Logger::default_logger_ = nullptr;

void Logger::Initialize() {
    // Crear logger con salida colorizada
    default_logger_ = spdlog::stdout_color_mt("wxWidgets_SDL3");
    spdlog::set_default_logger(default_logger_);
    
    // Configurar nivel por defecto
    spdlog::set_level(spdlog::level::debug);
    
    // Configurar patrón de salida
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");
    
    spdlog::info("Sistema de logging inicializado");
}

void Logger::SetLevel(spdlog::level::level_enum level) {
    if (default_logger_) {
        spdlog::set_level(level);
    }
}

std::shared_ptr<spdlog::logger> Logger::GetDefault() {
    return default_logger_;
}
