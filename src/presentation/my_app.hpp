/**
 * APLICACIÓN PRINCIPAL
 * 
 * Clase principal que hereda de wxApp y maneja la inicialización
 * y ciclo de vida de la aplicación.
 */

#pragma once

#include <wx/wx.h>
#include <memory>

// Forward declaration
class AppController;

class MyApp : public wxApp {
public:
    MyApp();
    ~MyApp();
    
    /**
     * Función que se ejecuta al inicializar la aplicación
     * @return true si la inicialización fue exitosa
     */
    virtual bool OnInit() override;

private:
    std::unique_ptr<AppController> app_controller_;
};
