/**
 * APPLICATION CONTROLLER IMPLEMENTATION
 */

#include "app_controller.hpp"
#include "../presentation/screens/my_frame.hpp"
#include "../services/logging_service.hpp"
#include "../config/logger.hpp"
#include "../presentation/controllers/application_controller.hpp"

AppController::AppController() 
    : logging_service_(nullptr), main_frame_(nullptr), presentation_controller_(nullptr) {
}

AppController::~AppController() {
    Shutdown();
}

bool AppController::Initialize() {
    try {
        // Inicializar servicios
        InitializeServices();
        
        // Inicializar controlador de presentación (Clean Architecture)
        presentation_controller_ = std::make_unique<Presentation::Controllers::ApplicationController>();
        if (!presentation_controller_->Initialize()) {
            throw std::runtime_error("Error inicializando controlador de presentación");
        }
        
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
        // Obtener información de la aplicación desde el dominio
        std::string windowTitle = "wxWidgets App";
        if (presentation_controller_) {
            auto app = presentation_controller_->GetApplication();
            if (app) {
                windowTitle = app->GetTitle();
            }
        }
        
        // Crear la ventana principal
        main_frame_ = std::make_unique<MyFrame>();
        
        if (main_frame_) {
            // Configurar título desde el dominio
            main_frame_->SetTitle(windowTitle);
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
    
    // Cerrar controlador de presentación
    if (presentation_controller_) {
        presentation_controller_->Shutdown();
        presentation_controller_.reset();
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
