/**
 * APPLICATION CONTROLLER
 * 
 * Controlador principal que maneja la lógica de la aplicación
 * y coordina entre las vistas y servicios.
 */

#pragma once

#include <memory>
#include <wx/wx.h>

// Forward declarations
class MyFrame;
class LoggingService;

class AppController {
public:
    AppController();
    ~AppController();
    
    // Inicialización de la aplicación
    bool Initialize();
    
    // Creación de la ventana principal
    void CreateMainWindow();
    
    // Gestión del ciclo de vida
    void Shutdown();
    
    // Getters para los servicios
    std::shared_ptr<LoggingService> GetLoggingService() const { return logging_service_; }

private:
    // Servicios
    std::shared_ptr<LoggingService> logging_service_;
    
    // Vista principal
    std::unique_ptr<MyFrame> main_frame_;
    
    // Métodos privados de inicialización
    void InitializeServices();
};
