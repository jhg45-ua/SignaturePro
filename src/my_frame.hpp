/**
 * FRAME PRINCIPAL
 * 
 * Ventana principal de la aplicación que contiene todos los controles
 * de la interfaz de usuario y maneja los eventos.
 */

#pragma once

#include <wx/wx.h>

class MyFrame : public wxFrame {
    public:
        /**
         * Constructor que inicializa la ventana
         */
        MyFrame();
        
        /**
         * Destructor
         */
        ~MyFrame();
        
    private:
        // === MANEJADORES DE EVENTOS ===
        void OnHello(wxCommandEvent& event);    // Maneja el botón "Hola"
        void OnExit(wxCommandEvent& event);     // Maneja el botón "Salir"
        void OnAbout(wxCommandEvent& event);    // Maneja el menú "Acerca de"
        void OnHelp(wxCommandEvent& event);     // Maneja el menú "Ayuda"
        void OnClose(wxCloseEvent& event);      // Maneja el cierre de la ventana
        
        // === MÉTODOS PRIVADOS DE INICIALIZACIÓN ===
        void InitializeComponents();  // Inicializa los componentes de la UI
        void CreateMenuSystem();      // Crea el sistema de menús
        void CreateMainInterface();   // Crea la interfaz principal
        void ConfigureLayout();       // Configura el layout y los sizers
        
        // === VARIABLES MIEMBRO ===
        // Controles de la interfaz
        wxPanel* main_panel_;
        wxBoxSizer* main_sizer_;
        wxStaticText* title_text_;
        wxStaticText* info_text_;
        wxButton* test_button_;
        wxButton* exit_button_;
        
        // Macro de wxWidgets para declarar la tabla de eventos
        DECLARE_EVENT_TABLE()
};
