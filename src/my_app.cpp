/**
 * IMPLEMENTACIÓN DE LA APLICACIÓN PRINCIPAL
 * Punto de entrada de la aplicación wxWidgets
 */

#include "my_app.hpp"
#include "controllers/app_controller.hpp"

// Macro de wxWidgets que crea la aplicación principal
wxIMPLEMENT_APP(MyApp);

MyApp::MyApp() : app_controller_(nullptr) {
}

MyApp::~MyApp() {
    // El destructor se encarga de limpiar automáticamente
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
