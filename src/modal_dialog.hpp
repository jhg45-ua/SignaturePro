/**
 * DIÁLOGO MODAL
 * 
 * Ejemplo de cómo crear una ventana modal que bloquea
 * la interacción con la ventana principal hasta que se cierre.
 */

#pragma once

#include <wx/wx.h>
#include <wx/dialog.h>

class ModalDialog : public wxDialog {
    public:
        /**
         * Constructor que inicializa el diálogo modal
         */
        ModalDialog(wxWindow* parent);
        
        /**
         * Destructor
         */
        ~ModalDialog();
        
        // Métodos para obtener datos del diálogo
        wxString GetUserName() const;
        wxString GetUserEmail() const;
        int GetSelectedOption() const;
        
    private:
        // === MANEJADORES DE EVENTOS ===
        void OnOK(wxCommandEvent& event);
        void OnCancel(wxCommandEvent& event);
        void OnApply(wxCommandEvent& event);
        void OnReset(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        
        // === MÉTODOS PRIVADOS ===
        void InitializeComponents();
        void CreateInterface();
        void ConfigureLayout();
        void ResetFields();
        bool ValidateInput();
        
        // === VARIABLES MIEMBRO ===
        wxPanel* main_panel_;
        wxBoxSizer* main_sizer_;
        wxBoxSizer* form_sizer_;
        wxBoxSizer* button_sizer_;
        
        // Controles del formulario
        wxStaticText* title_text_;
        wxStaticText* name_label_;
        wxTextCtrl* name_input_;
        wxStaticText* email_label_;
        wxTextCtrl* email_input_;
        wxStaticText* option_label_;
        wxChoice* option_choice_;
        wxCheckBox* terms_checkbox_;
        
        // Botones
        wxButton* ok_button_;
        wxButton* cancel_button_;
        wxButton* apply_button_;
        wxButton* reset_button_;
        
        // IDs personalizados para este diálogo
        enum {
            ID_APPLY = 3000,
            ID_RESET = 3001
        };
        
        // Macro de wxWidgets para declarar la tabla de eventos
        DECLARE_EVENT_TABLE()
};
