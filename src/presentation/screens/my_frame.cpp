/**
 * IMPLEMENTACIÓN DEL FRAME PRINCIPAL
 */

#include "my_frame.hpp"
#include "second_frame.hpp"  // Incluir el header de la segunda ventana
#include "modal_dialog.hpp"  // Incluir el header del diálogo modal
#include "../../config/theme.hpp"         // Incluir el sistema de tema
#include "../../config/constants.hpp"
#include "../../config/logger.hpp"

// Incluir headers necesarios de wxWidgets
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/font.h>

// Tabla de eventos de wxWidgets
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(Constants::ID_Hello, MyFrame::OnHello)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_BUTTON(Constants::ID_Hello, MyFrame::OnHello)
    EVT_BUTTON(ID_OPEN_SECOND_PAGE, MyFrame::OnOpenSecondPage)
    EVT_BUTTON(ID_OPEN_MODAL_DIALOG, MyFrame::OnOpenModalDialog)
    EVT_BUTTON(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(Constants::ID_Help, MyFrame::OnHelp)
    EVT_CLOSE(MyFrame::OnClose)
wxEND_EVENT_TABLE()

MyFrame::MyFrame() 
    : wxFrame(nullptr, wxID_ANY, Constants::Window::TITLE),
      main_panel_(nullptr),
      main_sizer_(nullptr),
      title_text_(nullptr),
      info_text_(nullptr),
      test_button_(nullptr),
      second_page_button_(nullptr),
      modal_dialog_button_(nullptr),
      exit_button_(nullptr) {
    
    InitializeComponents();
}

MyFrame::~MyFrame() {
    // Las ventanas secundarias se destruyen automáticamente
    // cuando se destruye la ventana padre
    spdlog::info("Destruyendo ventana principal");
}

/**
 * Inicializa los componentes de la ventana principal.
 * Configura el sistema de menús, barra de estado y la interfaz principal.
 */
void MyFrame::InitializeComponents() {
    // Crear sistema de menús
    CreateMenuSystem();
    
    // Crear barra de estado
    CreateStatusBar();
    SetStatusText(Constants::Status::APP_READY);
    
    // Crear interfaz principal
    CreateMainInterface();
    
    // Configurar layout
    ConfigureLayout();
    
    // Configuración final de la ventana
    SetSize(Constants::Window::DEFAULT_WIDTH, Constants::Window::DEFAULT_HEIGHT);
    Center();
}

void MyFrame::CreateMenuSystem() {
    // Crear menú "Archivo"
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(Constants::ID_Hello, "&Hola...\tCtrl-H", "Mensaje de prueba");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    
    // Crear menú "Ayuda"
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT, "Acerca de...", "Acerca de la aplicación");
    menuHelp->Append(Constants::ID_Help, "Ayuda...\tF1", "Mostrar ayuda e información adicional");
    
    // Crear barra de menús y agregar los menús
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Archivo");
    menuBar->Append(menuHelp, "&Ayuda");
    
    // Asignar la barra de menús a la ventana
    SetMenuBar(menuBar);
}

void MyFrame::CreateMainInterface() {
    // Crear panel principal con tema consistente
    main_panel_ = new wxPanel(this, wxID_ANY);
    main_panel_->SetBackgroundColour(Theme::Colors::BACKGROUND_PRIMARY);
    
    // Crear sizer vertical
    main_sizer_ = new wxBoxSizer(wxVERTICAL);
    
    // Crear título principal con estilo consistente
    title_text_ = new wxStaticText(main_panel_, wxID_ANY, 
        "📱 Aplicación wxWidgets", 
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    Theme::Utils::ApplyTitleStyle(title_text_, Theme::FontSizes::TITLE_LARGE);
    
    // Crear texto informativo
    info_text_ = new wxStaticText(main_panel_, wxID_ANY, Constants::Text::INFO_TEXT,
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    info_text_->SetFont(Theme::Utils::CreateFont(Theme::FontSizes::BODY_LARGE));
    info_text_->SetForegroundColour(Theme::Colors::TEXT_SECONDARY);
    
    // Crear botones con estilo consistente
    test_button_ = new wxButton(main_panel_, Constants::ID_Hello, "🔧 Prueba de Funcionalidad",
                               wxDefaultPosition, Theme::ComponentSizes::BUTTON_LARGE);
    second_page_button_ = new wxButton(main_panel_, ID_OPEN_SECOND_PAGE, "🚀 Abrir Segunda Página",
                                      wxDefaultPosition, Theme::ComponentSizes::BUTTON_LARGE);
    modal_dialog_button_ = new wxButton(main_panel_, ID_OPEN_MODAL_DIALOG, "📝 Abrir Diálogo Modal",
                                       wxDefaultPosition, Theme::ComponentSizes::BUTTON_LARGE);
    exit_button_ = new wxButton(main_panel_, wxID_EXIT, "❌ Salir",
                               wxDefaultPosition, Theme::ComponentSizes::BUTTON_LARGE);
    
    // Aplicar estilos de botones planos (sin fondos rectangulares)
    Theme::Utils::ApplyFlatInfoButton(test_button_);
    Theme::Utils::ApplyFlatPrimaryButton(second_page_button_);
    Theme::Utils::ApplyFlatSuccessButton(modal_dialog_button_);
    Theme::Utils::ApplyFlatDangerButton(exit_button_);
}

void MyFrame::ConfigureLayout() {
    // Agregar elementos al sizer con espaciado consistente del tema
    main_sizer_->Add(title_text_, 0, wxALL | wxCENTER, Theme::Spacing::XXLARGE);
    main_sizer_->Add(info_text_, 0, wxALL | wxCENTER, Theme::Spacing::LARGE);
    main_sizer_->Add(test_button_, 0, wxALL | wxCENTER, Theme::Spacing::MEDIUM);
    main_sizer_->Add(second_page_button_, 0, wxALL | wxCENTER, Theme::Spacing::MEDIUM);
    main_sizer_->Add(modal_dialog_button_, 0, wxALL | wxCENTER, Theme::Spacing::MEDIUM);
    main_sizer_->Add(exit_button_, 0, wxALL | wxCENTER, Theme::Spacing::MEDIUM);
    
    // Asignar el sizer al panel
    main_panel_->SetSizer(main_sizer_);
    
    // Forzar actualización del layout
    main_panel_->Layout();
}

// === MANEJADORES DE EVENTOS ===

void MyFrame::OnExit(wxCommandEvent& event) {
    spdlog::info("Usuario solicitó cerrar la aplicación");
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox(Constants::Text::ABOUT_TEXT,
                 Constants::Text::ABOUT_TITLE,
                 wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHelp(wxCommandEvent& event) {
    wxMessageBox(Constants::Text::HELP_MSG,
                 "Ayuda",
                 wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event) {
    spdlog::info("Ejecutando prueba de funcionalidad del sistema");
    
    std::string message = "✓ wxWidgets: Funcionando perfectamente\n";
    message += "✓ Interfaz: Totalmente funcional\n";
    message += "✓ Eventos: Sistema operativo\n";
    message += "✓ Aplicación: Lista para usar";
    
    wxMessageBox(message, Constants::Text::TEST_TITLE, wxOK | wxICON_INFORMATION);
}

void MyFrame::OnClose(wxCloseEvent& event) {
    spdlog::info("Cerrando aplicación - iniciando limpieza de recursos");
    
    // Las ventanas secundarias se destruyen automáticamente
    // cuando se destruye la ventana padre
    
    // Aceptar el evento de cierre y permitir que la ventana se cierre
    event.Skip();
    spdlog::info("Aplicación cerrada exitosamente");
}

void MyFrame::OnOpenSecondPage(wxCommandEvent& event) {
    spdlog::info("Usuario solicitó abrir la segunda página");
    
    // Siempre crear una nueva instancia de la segunda ventana
    // Esto evita problemas con punteros colgantes
    SecondFrame* new_second_frame = new SecondFrame(this);
    new_second_frame->Show(true);
    spdlog::info("Nueva segunda ventana creada y mostrada");
}

void MyFrame::OnOpenModalDialog(wxCommandEvent& event) {
    spdlog::info("Usuario solicitó abrir el diálogo modal");
    
    // Crear el diálogo modal
    ModalDialog dialog(this);
    
    // Mostrar el diálogo de forma modal (bloquea la ventana principal)
    int result = dialog.ShowModal();
    
    // Procesar el resultado según lo que haya hecho el usuario
    if (result == wxID_OK) {
        // Usuario hizo clic en "Aceptar"
        wxString name = dialog.GetUserName();
        wxString email = dialog.GetUserEmail();
        int option = dialog.GetSelectedOption();
        
        wxString optionText;
        switch(option) {
            case 0: optionText = "Usuario Regular"; break;
            case 1: optionText = "Usuario Premium"; break;
            case 2: optionText = "Administrador"; break;
            case 3: optionText = "Desarrollador"; break;
            default: optionText = "Desconocido"; break;
        }
        
        spdlog::info("Datos del usuario recibidos - Nombre: {}, Email: {}, Tipo: {}", 
                     name.ToStdString(), email.ToStdString(), optionText.ToStdString());
        
        // Mostrar confirmación con los datos recibidos
        wxString message = "✅ Configuración guardada exitosamente!\n\n";
        message += "📝 Datos recibidos:\n";
        message += "• Nombre: " + name + "\n";
        message += "• Email: " + email + "\n";
        message += "• Tipo: " + optionText + "\n\n";
        message += "Los datos han sido procesados correctamente.";
        
        wxMessageBox(message, "Configuración Completada", 
                     wxOK | wxICON_INFORMATION);
        
        // Aquí podrías guardar los datos en un archivo, base de datos, etc.
        
    } else if (result == wxID_CANCEL) {
        // Usuario canceló o cerró el diálogo
        spdlog::info("Usuario canceló el diálogo modal");
        // wxMessageBox("Configuración cancelada.", "Cancelado", wxOK | wxICON_INFORMATION);
    }
    
    spdlog::info("Diálogo modal cerrado");
}
