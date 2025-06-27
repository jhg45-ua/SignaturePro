/**
 * FRAME PRINCIPAL
 * 
 * Ventana principal de la aplicación que contiene todos los controles
 * de la interfaz de usuario y maneja los eventos.
 */

#pragma once

#include <wx/wx.h>
// Declaración adelantada para evitar dependencia circular
class SecondFrame;
class ModalDialog;

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
        void OnOpenSecondPage(wxCommandEvent& event); // Abre la segunda página
        void OnOpenModalDialog(wxCommandEvent& event); // Abre el diálogo modal
        
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
        wxButton* second_page_button_;  // Nuevo botón para segunda página
        wxButton* modal_dialog_button_; // Nuevo botón para diálogo modal
        wxButton* exit_button_;
        
        // IDs personalizados
        enum {
            ID_OPEN_SECOND_PAGE = 1000,
            ID_OPEN_MODAL_DIALOG = 1001
        };
        
        // Macro de wxWidgets para declarar la tabla de eventos
        DECLARE_EVENT_TABLE()
};
