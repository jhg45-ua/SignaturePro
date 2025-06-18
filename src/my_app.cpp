/**
 * IMPLEMENTACIÓN DE LA APLICACIÓN PRINCIPAL
 */

#include "my_app.hpp"
#include "my_frame.hpp"
#include "logger.hpp"

// Macro de wxWidgets que crea la aplicación principal
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    // Inicializar el sistema de logging
    Logger::Initialize();
    spdlog::info("Iniciando aplicación wxWidgets + SDL3");
    
    // Crear la ventana principal
    MyFrame* frame = new MyFrame();
    
    // Mostrar la ventana (hacer visible)
    frame->Show(true);
    
    // Retornar true indica que la inicialización fue exitosa
    return true;
}
