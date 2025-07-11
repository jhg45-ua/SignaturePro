/**
 * IMPLEMENTACIÓN DE LA APLICACIÓN PRINCIPAL
 */

#include "my_app.hpp"
#include "my_frame.hpp"
#include "logger.hpp"

bool MyApp::OnInit() {
    // Inicializar el sistema de logging
    Logger::Initialize();
    spdlog::info("Iniciando aplicación wxWidgets");
    
    // Crear la ventana principal
    MyFrame* frame = new MyFrame();
    
    // Mostrar la ventana (hacer visible)
    frame->Show(true);
    
    // Retornar true indica que la inicialización fue exitosa
    return true;
}
