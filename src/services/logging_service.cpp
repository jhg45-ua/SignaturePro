/**
 * LOGGING SERVICE IMPLEMENTATION
 */

#include "logging_service.hpp"
#include "../core/logger.hpp"
#include <spdlog/spdlog.h>

LoggingService::LoggingService() : initialized_(false) {
}

LoggingService::~LoggingService() {
    if (initialized_) {
        spdlog::info("Cerrando servicio de logging");
    }
}

bool LoggingService::Initialize() {
    try {
        // Usar la funcionalidad existente del Logger
        Logger::Initialize();
        initialized_ = true;
        
        LogInfo("Servicio de logging inicializado correctamente");
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}

void LoggingService::LogInfo(const std::string& message) {
    if (initialized_) {
        spdlog::info(message);
    }
}

void LoggingService::LogWarning(const std::string& message) {
    if (initialized_) {
        spdlog::warn(message);
    }
}

void LoggingService::LogError(const std::string& message) {
    if (initialized_) {
        spdlog::error(message);
    }
}

void LoggingService::LogDebug(const std::string& message) {
    if (initialized_) {
        spdlog::debug(message);
    }
}

void LoggingService::SetLogLevel(int level) {
    if (initialized_) {
        spdlog::set_level(static_cast<spdlog::level::level_enum>(level));
    }
}
