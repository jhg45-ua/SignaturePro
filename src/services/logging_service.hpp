/**
 * LOGGING SERVICE
 * 
 * Servicio centralizado para el manejo de logs en la aplicación.
 * Encapsula la funcionalidad de spdlog.
 */

#pragma once

#include <string>
#include <memory>

class LoggingService {
public:
    LoggingService();
    ~LoggingService();
    
    // Inicialización del servicio
    bool Initialize();
    
    // Métodos de logging
    void LogInfo(const std::string& message);
    void LogWarning(const std::string& message);
    void LogError(const std::string& message);
    void LogDebug(const std::string& message);
    
    // Configuración
    void SetLogLevel(int level);
    
private:
    bool initialized_;
};
