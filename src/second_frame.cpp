/**
 * IMPLEMENTACIÓN DE LA SEGUNDA VENTANA
 */

#include "second_frame.hpp"
#include "theme.hpp"
#include "logger.hpp"

// Incluir headers necesarios de wxWidgets
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/msgdlg.h>
#include <wx/font.h>

// Forward declaration para evitar dependencia circular
class MyFrame;

// Tabla de eventos de wxWidgets
wxBEGIN_EVENT_TABLE(SecondFrame, wxFrame)
    EVT_BUTTON(ID_BACK_TO_MAIN, SecondFrame::OnBackToMain)
    EVT_BUTTON(ID_SECOND_ACTION, SecondFrame::OnSecondPageAction)
    EVT_CLOSE(SecondFrame::OnClose)
wxEND_EVENT_TABLE()

SecondFrame::SecondFrame(wxWindow* parent) 
    : wxFrame(parent, wxID_ANY, "Segunda Página - Mi Aplicación"),
      main_panel_(nullptr),
      main_sizer_(nullptr),
      title_text_(nullptr),
      description_text_(nullptr),
      action_button_(nullptr),
      back_button_(nullptr),
      parent_window_(parent) {
    
    spdlog::info("Creando segunda ventana");
    InitializeComponents();
}

SecondFrame::~SecondFrame() {
    spdlog::info("Destruyendo segunda ventana");
}

void SecondFrame::InitializeComponents() {
    // Crear barra de estado
    CreateStatusBar();
    SetStatusText("Segunda página activa");
    
    // Crear interfaz
    CreateInterface();
    
    // Configurar layout
    ConfigureLayout();
    
    // Configuración final de la ventana
    SetMinSize(wxSize(600, 500));  // Tamaño mínimo más grande
    SetSize(600, 500);             // Tamaño inicial más grande
    Center();
    
    // Forzar actualización del layout
    Layout();
    Refresh();
}

void SecondFrame::CreateInterface() {
    // Crear panel principal con tema consistente
    main_panel_ = new wxPanel(this, wxID_ANY);
    main_panel_->SetBackgroundColour(Theme::Colors::BACKGROUND_PRIMARY);
    
    // Crear sizer vertical
    main_sizer_ = new wxBoxSizer(wxVERTICAL);
    
    // Crear título con estilo consistente
    title_text_ = new wxStaticText(main_panel_, wxID_ANY, 
        "🚀 Segunda Página", 
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    Theme::Utils::ApplyTitleStyle(title_text_, Theme::FontSizes::TITLE_LARGE);
    
    // Crear descripción con mejor formato
    description_text_ = new wxStaticText(main_panel_, wxID_ANY, 
        "Esta es una nueva ventana independiente.\n\n"
        "Aquí puedes agregar cualquier funcionalidad:\n\n"
        "• Formularios de entrada de datos\n"
        "• Gráficos y visualizaciones\n"
        "• Configuraciones de la aplicación\n"
        "• Herramientas adicionales\n"
        "• Y mucho más...",
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    
    description_text_->SetFont(Theme::Utils::CreateFont(Theme::FontSizes::BODY_LARGE));
    description_text_->SetForegroundColour(Theme::Colors::TEXT_SECONDARY);
    
    // Crear botones con estilo consistente
    action_button_ = new wxButton(main_panel_, ID_SECOND_ACTION, 
        "✨ Acción de Segunda Página", wxDefaultPosition, Theme::ComponentSizes::BUTTON_LARGE);
    back_button_ = new wxButton(main_panel_, ID_BACK_TO_MAIN, 
        "⬅ Volver a Principal", wxDefaultPosition, Theme::ComponentSizes::BUTTON_LARGE);
    
    // Aplicar estilos de botones planos (sin fondos rectangulares)
    Theme::Utils::ApplyFlatPrimaryButton(action_button_);
    Theme::Utils::ApplyFlatSecondaryButton(back_button_);
}

void SecondFrame::ConfigureLayout() {
    // Agregar elementos al sizer con espaciado y expansión
    main_sizer_->Add(title_text_, 0, wxALL | wxCENTER, 30);
    main_sizer_->Add(description_text_, 1, wxALL | wxCENTER | wxEXPAND, 20);
    main_sizer_->Add(action_button_, 0, wxALL | wxCENTER, 15);
    main_sizer_->Add(back_button_, 0, wxALL | wxCENTER, 15);
    
    // Asignar el sizer al panel y forzar layout
    main_panel_->SetSizer(main_sizer_);
    main_sizer_->SetSizeHints(main_panel_);  // Establecer hints de tamaño
    main_panel_->Layout();                   // Forzar layout del panel
}

// === MANEJADORES DE EVENTOS ===

void SecondFrame::OnBackToMain(wxCommandEvent& event) {
    spdlog::info("Usuario regresando a ventana principal");
    
    // Mostrar la ventana padre si existe
    if (parent_window_) {
        parent_window_->Show(true);
        parent_window_->Raise(); // Traer al frente
    }
    
    // Destruir esta ventana en lugar de solo cerrarla
    Destroy();
}

void SecondFrame::OnSecondPageAction(wxCommandEvent& event) {
    spdlog::info("Ejecutando acción específica de la segunda página");
    
    wxMessageBox("Esta es una acción específica de la segunda página.\n"
                 "Aquí puedes implementar cualquier funcionalidad que necesites:\n\n"
                 "• Procesar datos\n"
                 "• Abrir archivos\n"
                 "• Mostrar configuraciones\n"
                 "• Cualquier otra funcionalidad",
                 "Acción de Segunda Página",
                 wxOK | wxICON_INFORMATION);
}

void SecondFrame::OnClose(wxCloseEvent& event) {
    spdlog::info("Cerrando segunda ventana");
    
    // Mostrar la ventana padre cuando se cierre esta
    if (parent_window_) {
        parent_window_->Show(true);
        parent_window_->Raise();
    }
    
    // IMPORTANTE: No llamamos a event.Skip() aquí para tener control total
    // En su lugar, destruimos la ventana manualmente
    Destroy();
}
