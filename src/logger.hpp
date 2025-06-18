/**
 * LOGGER HELPER
 * 
 * Clase auxiliar para la configuración y manejo del sistema de logging
 * usando spdlog. Centraliza la configuración del logger.
 */

#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class Logger {
public:
    /**
     * Inicializa el sistema de logging con configuración por defecto
     */
    static void Initialize();
    
    /**
     * Configura el nivel de logging
     * @param level Nivel de logging (debug, info, warn, error)
     */
    static void SetLevel(spdlog::level::level_enum level);
    
    /**
     * Obtiene el logger por defecto
     * @return Referencia al logger por defecto
     */
    static std::shared_ptr<spdlog::logger> GetDefault();

private:
    static std::shared_ptr<spdlog::logger> default_logger_;
};
