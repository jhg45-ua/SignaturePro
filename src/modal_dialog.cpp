/**
 * IMPLEMENTACIÓN DEL DIÁLOGO MODAL
 */

#include "modal_dialog.hpp"
#include "theme.hpp"
#include "logger.hpp"

// Incluir headers necesarios de wxWidgets
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/msgdlg.h>
#include <wx/font.h>
#include <wx/regex.h>
#include <wx/statbox.h>
#include <wx/statbox.h>

// Tabla de eventos de wxWidgets
wxBEGIN_EVENT_TABLE(ModalDialog, wxDialog)
    EVT_BUTTON(wxID_OK, ModalDialog::OnOK)
    EVT_BUTTON(wxID_CANCEL, ModalDialog::OnCancel)
    EVT_BUTTON(ID_APPLY, ModalDialog::OnApply)
    EVT_BUTTON(ID_RESET, ModalDialog::OnReset)
    EVT_CLOSE(ModalDialog::OnClose)
wxEND_EVENT_TABLE()

ModalDialog::ModalDialog(wxWindow* parent) 
    : wxDialog(parent, wxID_ANY, "📝 Configuración de Usuario", 
               wxDefaultPosition, wxDefaultSize, 
               wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER),
      main_panel_(nullptr),
      main_sizer_(nullptr),
      form_sizer_(nullptr),
      button_sizer_(nullptr),
      title_text_(nullptr),
      name_label_(nullptr),
      name_input_(nullptr),
      email_label_(nullptr),
      email_input_(nullptr),
      option_label_(nullptr),
      option_choice_(nullptr),
      terms_checkbox_(nullptr),
      ok_button_(nullptr),
      cancel_button_(nullptr),
      apply_button_(nullptr),
      reset_button_(nullptr) {
    
    spdlog::info("Creando diálogo modal");
    InitializeComponents();
}

ModalDialog::~ModalDialog() {
    spdlog::info("Destruyendo diálogo modal");
}

void ModalDialog::InitializeComponents() {
    // Crear interfaz
    CreateInterface();
    
    // Configurar layout
    ConfigureLayout();
    
    // Configuración final del diálogo
    SetMinSize(wxSize(800, 650));  // Más alto para mejor espaciado
    SetSize(800, 650);
    Center();
    
    // Establecer foco inicial en el primer campo
    name_input_->SetFocus();
    
    // Forzar actualización del layout
    Layout();
    Refresh();
}

void ModalDialog::CreateInterface() {
    // Crear panel principal con tema oscuro
    main_panel_ = new wxPanel(this, wxID_ANY);
    Theme::Utils::ApplyPanelStyle(main_panel_);
    
    // Crear sizers
    main_sizer_ = new wxBoxSizer(wxVERTICAL);
    form_sizer_ = new wxBoxSizer(wxVERTICAL);
    button_sizer_ = new wxBoxSizer(wxHORIZONTAL);
    
    // === TÍTULO CON ESTILO OSCURO ===
    title_text_ = new wxStaticText(main_panel_, wxID_ANY, 
        "⚙️ Configuración de Usuario",
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    Theme::Utils::ApplyTitleStyle(title_text_, Theme::FontSizes::TITLE_LARGE);
    
    // === FORMULARIO CON ESTILO OSCURO ===
    
    // Campo Nombre
    name_label_ = new wxStaticText(main_panel_, wxID_ANY, "👤 Nombre completo *");
    Theme::Utils::ApplyLabelStyle(name_label_);
    
    name_input_ = new wxTextCtrl(main_panel_, wxID_ANY, "", 
                                wxDefaultPosition, Theme::ComponentSizes::INPUT_NORMAL);
    name_input_->SetHint("Ingresa tu nombre completo aquí...");
    Theme::Utils::ApplyInputStyleDark(name_input_);
    
    // Campo Email
    email_label_ = new wxStaticText(main_panel_, wxID_ANY, "📧 Correo electrónico *");
    Theme::Utils::ApplyLabelStyle(email_label_);
    
    email_input_ = new wxTextCtrl(main_panel_, wxID_ANY, "", 
                                 wxDefaultPosition, Theme::ComponentSizes::INPUT_NORMAL);
    email_input_->SetHint("ejemplo@correo.com");
    Theme::Utils::ApplyInputStyleDark(email_input_);
    
    // Campo Opción
    option_label_ = new wxStaticText(main_panel_, wxID_ANY, "🎯 Tipo de usuario *");
    Theme::Utils::ApplyLabelStyle(option_label_);
    
    option_choice_ = new wxChoice(main_panel_, wxID_ANY, 
                                 wxDefaultPosition, Theme::ComponentSizes::INPUT_NORMAL);
    option_choice_->Append("👤 Usuario Regular");
    option_choice_->Append("⭐ Usuario Premium");
    option_choice_->Append("👑 Administrador");
    option_choice_->Append("🛠️ Desarrollador");
    option_choice_->SetSelection(0);
    Theme::Utils::ApplyChoiceStyle(option_choice_);
    
    // Checkbox términos
    terms_checkbox_ = new wxCheckBox(main_panel_, wxID_ANY, 
        "✅ Acepto los términos y condiciones de uso");
    Theme::Utils::ApplyCheckboxStyle(terms_checkbox_);
    
    // === BOTONES CON ESTILO OSCURO ===
    ok_button_ = new wxButton(main_panel_, wxID_OK, "✅ Aceptar", 
                             wxDefaultPosition, Theme::ComponentSizes::BUTTON_NORMAL);
    cancel_button_ = new wxButton(main_panel_, wxID_CANCEL, "❌ Cancelar", 
                                 wxDefaultPosition, Theme::ComponentSizes::BUTTON_NORMAL);
    apply_button_ = new wxButton(main_panel_, ID_APPLY, "📝 Aplicar", 
                                wxDefaultPosition, Theme::ComponentSizes::BUTTON_NORMAL);
    reset_button_ = new wxButton(main_panel_, ID_RESET, "🔄 Limpiar", 
                                wxDefaultPosition, Theme::ComponentSizes::BUTTON_NORMAL);
    
    // Aplicar estilos de botones planos (sin fondos rectangulares)
    Theme::Utils::ApplyFlatSuccessButton(ok_button_);
    Theme::Utils::ApplyFlatDangerButton(cancel_button_);
    Theme::Utils::ApplyFlatPrimaryButton(apply_button_);
    Theme::Utils::ApplyFlatWarningButton(reset_button_);
}

void ModalDialog::ConfigureLayout() {
    // === SECCIÓN DE FORMULARIO CON MEJOR ESPACIADO ===
    // Agregar elementos al formulario con mejor espaciado
    form_sizer_->Add(name_label_, 0, wxLEFT | wxRIGHT | wxTOP, 15);
    form_sizer_->Add(name_input_, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 15);
    
    form_sizer_->Add(email_label_, 0, wxLEFT | wxRIGHT | wxTOP, 15);
    form_sizer_->Add(email_input_, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 15);
    
    form_sizer_->Add(option_label_, 0, wxLEFT | wxRIGHT | wxTOP, 15);
    form_sizer_->Add(option_choice_, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 15);
    
    // Espaciador antes del checkbox
    form_sizer_->AddSpacer(20);
    
    form_sizer_->Add(terms_checkbox_, 0, wxLEFT | wxRIGHT | wxBOTTOM, 15);
    
    // === SECCIÓN DE BOTONES CON MEJOR DISTRIBUCIÓN ===
    // Agregar botones al sizer de botones con mejor espaciado
    button_sizer_->Add(ok_button_, 0, wxALL, 8);
    button_sizer_->Add(apply_button_, 0, wxALL, 8);
    button_sizer_->Add(reset_button_, 0, wxALL, 8);
    button_sizer_->Add(cancel_button_, 0, wxALL, 8);
    
    // === COMPOSICIÓN PRINCIPAL ===
    // Agregar todo al sizer principal con mejor espaciado
    main_sizer_->Add(title_text_, 0, wxALL | wxCENTER, 25);
    
    // Crear un panel con borde para el formulario
    wxStaticBoxSizer* form_box = new wxStaticBoxSizer(wxVERTICAL, main_panel_, "Información del Usuario");
    form_box->Add(form_sizer_, 1, wxEXPAND | wxALL, 10);
    
    main_sizer_->Add(form_box, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 20);
    main_sizer_->Add(button_sizer_, 0, wxCENTER | wxALL, 20);
    
    // Asignar el sizer al panel
    main_panel_->SetSizer(main_sizer_);
    
    // Crear sizer para el diálogo y agregar el panel
    wxBoxSizer* dialog_sizer = new wxBoxSizer(wxVERTICAL);
    dialog_sizer->Add(main_panel_, 1, wxEXPAND);
    SetSizer(dialog_sizer);
    
    // Establecer proporciones y forzar layout
    main_sizer_->SetSizeHints(main_panel_);
    main_panel_->Layout();
}

// === MANEJADORES DE EVENTOS ===

void ModalDialog::OnOK(wxCommandEvent& event) {
    spdlog::info("Usuario hizo clic en Aceptar");
    
    if (ValidateInput()) {
        // Si la validación es exitosa, cerrar con resultado OK
        EndModal(wxID_OK);
    }
}

void ModalDialog::OnCancel(wxCommandEvent& event) {
    spdlog::info("Usuario canceló el diálogo");
    EndModal(wxID_CANCEL);
}

void ModalDialog::OnApply(wxCommandEvent& event) {
    spdlog::info("Usuario hizo clic en Aplicar");
    
    if (ValidateInput()) {
        wxMessageBox("Configuración aplicada exitosamente.\n"
                     "Nombre: " + GetUserName() + "\n"
                     "Email: " + GetUserEmail() + "\n"
                     "Tipo: " + option_choice_->GetStringSelection(),
                     "Configuración Aplicada",
                     wxOK | wxICON_INFORMATION);
    }
}

void ModalDialog::OnReset(wxCommandEvent& event) {
    spdlog::info("Usuario solicitó limpiar los campos");
    ResetFields();
}

void ModalDialog::OnClose(wxCloseEvent& event) {
    spdlog::info("Cerrando diálogo modal");
    EndModal(wxID_CANCEL);
}

// === MÉTODOS PÚBLICOS ===

wxString ModalDialog::GetUserName() const {
    return name_input_->GetValue().Trim();
}

wxString ModalDialog::GetUserEmail() const {
    return email_input_->GetValue().Trim();
}

int ModalDialog::GetSelectedOption() const {
    return option_choice_->GetSelection();
}

// === MÉTODOS PRIVADOS ===

void ModalDialog::ResetFields() {
    name_input_->SetValue("");
    email_input_->SetValue("");
    option_choice_->SetSelection(0);
    terms_checkbox_->SetValue(false);
    name_input_->SetFocus();
}

bool ModalDialog::ValidateInput() {
    wxString name = GetUserName();
    wxString email = GetUserEmail();
    
    // Validar nombre
    if (name.IsEmpty()) {
        wxMessageBox("Por favor, ingresa tu nombre completo.", 
                     "Nombre requerido", wxOK | wxICON_WARNING);
        name_input_->SetFocus();
        return false;
    }
    
    if (name.Length() < 2) {
        wxMessageBox("El nombre debe tener al menos 2 caracteres.", 
                     "Nombre muy corto", wxOK | wxICON_WARNING);
        name_input_->SetFocus();
        return false;
    }
    
    // Validar email
    if (email.IsEmpty()) {
        wxMessageBox("Por favor, ingresa tu correo electrónico.", 
                     "Email requerido", wxOK | wxICON_WARNING);
        email_input_->SetFocus();
        return false;
    }
    
    // Validación básica de email con regex
    wxRegEx emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.IsValid() || !emailRegex.Matches(email)) {
        wxMessageBox("Por favor, ingresa un correo electrónico válido.", 
                     "Email inválido", wxOK | wxICON_WARNING);
        email_input_->SetFocus();
        return false;
    }
    
    // Validar términos y condiciones
    if (!terms_checkbox_->GetValue()) {
        wxMessageBox("Debes aceptar los términos y condiciones para continuar.", 
                     "Términos requeridos", wxOK | wxICON_WARNING);
        return false;
    }
    
    return true;
}
