/**
 * APLICACIÓN PRINCIPAL
 * 
 * Clase principal que hereda de wxApp y maneja la inicialización
 * y ciclo de vida de la aplicación.
 */

#pragma once

#include <wx/wx.h>

class MyApp : public wxApp {
    public:
        /**
         * Función que se ejecuta al inicializar la aplicación
         * @return true si la inicialización fue exitosa
         */
        virtual bool OnInit() override;
};
