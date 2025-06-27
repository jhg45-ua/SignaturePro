/**
 * SEGUNDA VENTANA/PÁGINA
 * 
 * Ejemplo de cómo crear una nueva ventana independiente
 * en la aplicación wxWidgets.
 */

#pragma once

#include <wx/wx.h>

class SecondFrame : public wxFrame {
    public:
        /**
         * Constructor que inicializa la segunda ventana
         */
        SecondFrame(wxWindow* parent);
        
        /**
         * Destructor
         */
        ~SecondFrame();
        
    private:
        // === MANEJADORES DE EVENTOS ===
        void OnClose(wxCloseEvent& event);
        void OnBackToMain(wxCommandEvent& event);
        void OnSecondPageAction(wxCommandEvent& event);
        
        // === MÉTODOS PRIVADOS ===
        void InitializeComponents();
        void CreateInterface();
        void ConfigureLayout();
        
        // === VARIABLES MIEMBRO ===
        wxPanel* main_panel_;
        wxBoxSizer* main_sizer_;
        wxStaticText* title_text_;
        wxStaticText* description_text_;
        wxButton* action_button_;
        wxButton* back_button_;
        
        // Referencia a la ventana padre (opcional)
        wxWindow* parent_window_;
        
        // IDs personalizados para esta ventana
        enum {
            ID_BACK_TO_MAIN = 2000,
            ID_SECOND_ACTION = 2001
        };
        
        // Macro de wxWidgets para declarar la tabla de eventos
        DECLARE_EVENT_TABLE()
};
