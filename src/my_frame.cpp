/**
 * IMPLEMENTACIÓN DEL FRAME PRINCIPAL
 */

#include "my_frame.hpp"
#include "constants.hpp"
#include "logger.hpp"

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
    EVT_BUTTON(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_CLOSE(MyFrame::OnClose)
wxEND_EVENT_TABLE()

MyFrame::MyFrame() 
    : wxFrame(nullptr, wxID_ANY, Constants::Window::TITLE),
      main_panel_(nullptr),
      main_sizer_(nullptr),
      title_text_(nullptr),
      info_text_(nullptr),
      test_button_(nullptr),
      exit_button_(nullptr) {
    
    InitializeComponents();
}

MyFrame::~MyFrame() {
    // Destructor simplificado sin SDL3
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
    menuHelp->Append(wxID_ABOUT);
    
    // Crear barra de menús y agregar los menús
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Archivo");
    menuBar->Append(menuHelp, "&Ayuda");
    
    // Asignar la barra de menús a la ventana
    SetMenuBar(menuBar);
}

void MyFrame::CreateMainInterface() {
    // Crear panel principal
    main_panel_ = new wxPanel(this, wxID_ANY);
    
    // Crear sizer vertical
    main_sizer_ = new wxBoxSizer(wxVERTICAL);
    
    // Crear título principal
    title_text_ = new wxStaticText(main_panel_, wxID_ANY, 
        "Aplicación wxWidgets", 
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    
    // Configurar fuente del título
    wxFont titleFont = title_text_->GetFont();
    titleFont.SetPointSize(Constants::Fonts::TITLE_SIZE);
    titleFont.SetWeight(wxFONTWEIGHT_BOLD);
    title_text_->SetFont(titleFont);
    
    // Crear texto informativo
    info_text_ = new wxStaticText(main_panel_, wxID_ANY, Constants::Text::INFO_TEXT,
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    
    // Crear botones
    test_button_ = new wxButton(main_panel_, Constants::ID_Hello, "Prueba de Funcionalidad");
    exit_button_ = new wxButton(main_panel_, wxID_EXIT, "Salir");
}

void MyFrame::ConfigureLayout() {
    // Agregar elementos al sizer con espaciado y alineación
    main_sizer_->Add(title_text_, 0, wxALL | wxCENTER, 20);
    main_sizer_->Add(info_text_, 0, wxALL | wxCENTER, 20);
    main_sizer_->Add(test_button_, 0, wxALL | wxCENTER, 10);
    main_sizer_->Add(exit_button_, 0, wxALL | wxCENTER, 10);
    
    // Asignar el sizer al panel
    main_panel_->SetSizer(main_sizer_);
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
    
    // Aceptar el evento de cierre y permitir que la ventana se cierre
    event.Skip();
    spdlog::info("Aplicación cerrada exitosamente");
}
