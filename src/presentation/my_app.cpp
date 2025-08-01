/**
 * IMPLEMENTACIÓN DE LA APLICACIÓN PRINCIPAL
 * Punto de entrada de la aplicación wxWidgets siguiendo Clean Architecture
 */

#include "my_app.hpp"
#include "../controllers/app_controller.hpp"

MyApp::MyApp() : app_controller_(nullptr) {
}

MyApp::~MyApp() {
    // Limpiar explícitamente el controlador antes de la destrucción automática
    if (app_controller_) {
        app_controller_->Shutdown();
        app_controller_.reset();
    }
}

bool MyApp::OnInit() {
    // Crear el controlador principal de la aplicación
    app_controller_ = std::make_unique<AppController>();
    
    // Inicializar el controlador
    if (!app_controller_->Initialize()) {
        return false;
    }
    
    // Crear y mostrar la ventana principal
    app_controller_->CreateMainWindow();
    
    return true;
}

int MyApp::OnExit() {
    // Hacer cleanup explícito antes de que wxWidgets limpie sus recursos
    if (app_controller_) {
        app_controller_->Shutdown();
        app_controller_.reset();
    }
    
    return wxApp::OnExit();
}
