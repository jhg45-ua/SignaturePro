/**
 * APPLICATION CONTROLLER IMPLEMENTATION
 */

#include "app_controller.hpp"
#include "../ui/my_frame.hpp"
#include "../services/logging_service.hpp"
#include "../core/logger.hpp"

AppController::AppController() 
    : logging_service_(nullptr), main_frame_(nullptr) {
}

AppController::~AppController() {
    Shutdown();
}

bool AppController::Initialize() {
    try {
        // Inicializar servicios
        InitializeServices();
        
        // Log de inicialización exitosa
        if (logging_service_) {
            logging_service_->LogInfo("AppController inicializado correctamente");
        }
        
        return true;
    } catch (const std::exception& e) {
        if (logging_service_) {
            logging_service_->LogError("Error inicializando AppController: " + std::string(e.what()));
        }
        return false;
    }
}

void AppController::CreateMainWindow() {
    try {
        // Crear la ventana principal
        main_frame_ = std::make_unique<MyFrame>();
        
        if (main_frame_) {
            main_frame_->Show(true);
            
            if (logging_service_) {
                logging_service_->LogInfo("Ventana principal creada y mostrada");
            }
        }
    } catch (const std::exception& e) {
        if (logging_service_) {
            logging_service_->LogError("Error creando ventana principal: " + std::string(e.what()));
        }
    }
}

void AppController::Shutdown() {
    if (logging_service_) {
        logging_service_->LogInfo("Cerrando aplicación...");
    }
    
    // Limpiar recursos
    main_frame_.reset();
    logging_service_.reset();
}

void AppController::InitializeServices() {
    // Inicializar servicio de logging
    logging_service_ = std::make_shared<LoggingService>();
    if (logging_service_) {
        logging_service_->Initialize();
    }
}
