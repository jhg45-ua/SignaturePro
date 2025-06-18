// Archivo de cabeceras con todas las dependencias de wxWidgets y SDL3
#include "include.hpp"

/**
 * APLICACIÓN DE DEMOSTRACIÓN: wxWidgets + SDL3
 * 
 * Esta aplicación demuestra cómo integrar wxWidgets (GUI nativa) con SDL3 (renderizado).
 * wxWidgets proporciona la interfaz de usuario nativa mientras que SDL3 maneja
 * el renderizado de gráficos de alto rendimiento en segundo plano.
 */

// Clase principal de la aplicación wxWidgets
// Hereda de wxApp para crear una aplicación wxWidgets estándar
class MyApp : public wxApp {
public:
    // Función que se ejecuta al inicializar la aplicación
    virtual bool OnInit();
};

// Frame principal de la aplicación (ventana principal)
// Hereda de wxFrame para crear una ventana con menú, barra de estado, etc.
class MyFrame : public wxFrame {
public:
    // Constructor que inicializa la ventana
    MyFrame();
    
    // Manejadores de eventos (event handlers)
    void OnHello(wxCommandEvent& event);    // Maneja el botón "Hola"
    void OnExit(wxCommandEvent& event);     // Maneja el botón "Salir"
    void OnAbout(wxCommandEvent& event);    // Maneja el menú "Acerca de"
    void OnClose(wxCloseEvent& event);      // Maneja el cierre de la ventana
    
private:
    // Función privada para inicializar SDL3
    bool InitSDL();
    
    // Variables para el contexto de SDL3
    SDL_Window* sdl_window;      // Ventana SDL (oculta, solo para demostración)
    SDL_Renderer* sdl_renderer;  // Renderer SDL para gráficos
    
    // Macro de wxWidgets para declarar la tabla de eventos
    DECLARE_EVENT_TABLE()
};

// Identificadores únicos para los elementos del menú
// wxWidgets usa estos IDs para asociar eventos con elementos de la interfaz
enum {
    ID_Hello = 1  // ID personalizado para el botón/menú "Hola"
                 // wxID_EXIT y wxID_ABOUT ya están predefinidos en wxWidgets
};

// Tabla de eventos de wxWidgets
// Conecta eventos (clicks, teclas, etc.) con funciones manejadoras
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)  // Conecta ID_Hello con OnHello()
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)   // Conecta menú Salir con OnExit()
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)  // Conecta menú Acerca de con OnAbout()
    EVT_CLOSE(MyFrame::OnClose)             // Conecta evento de cierre con OnClose()
wxEND_EVENT_TABLE()

// Macro de wxWidgets que crea la aplicación principal
// Equivale a crear un main() y manejar el loop de eventos
wxIMPLEMENT_APP(MyApp);

/**
 * INICIALIZACIÓN DE LA APLICACIÓN
 * Esta función se ejecuta automáticamente cuando se inicia la aplicación
 */
bool MyApp::OnInit() {
    // Crear la ventana principal
    MyFrame *frame = new MyFrame();
    
    // Mostrar la ventana (hacer visible)
    frame->Show(true);
    
    // Retornar true indica que la inicialización fue exitosa
    return true;
}

/**
 * CONSTRUCTOR DEL FRAME PRINCIPAL
 * Aquí se configura toda la interfaz de usuario y se inicializa SDL3
 */
MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "wxWidgets + SDL3 Demo") {
    // Inicializar punteros SDL a nullptr por seguridad
    sdl_window = nullptr;
    sdl_renderer = nullptr;
    
    // === INICIALIZACIÓN DE SDL3 ===
    // Intentar inicializar SDL3 y mostrar el resultado en la barra de estado
    if (InitSDL()) {
        SetStatusText("SDL3 inicializado correctamente");
    } else {
        SetStatusText("Error al inicializar SDL3");
    }
    
    // === CREACIÓN DEL SISTEMA DE MENÚS ===
    
    // Crear menú "Archivo"
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hola...\tCtrl-H", "Mensaje de prueba");
    menuFile->AppendSeparator();  // Línea separadora
    menuFile->Append(wxID_EXIT);  // Opción "Salir" (predefinida)
    
    // Crear menú "Ayuda"
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT); // Opción "Acerca de" (predefinida)
    
    // Crear barra de menús y agregar los menús
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Archivo");  // & indica la letra de acceso rápido
    menuBar->Append(menuHelp, "&Ayuda");
    
    // Asignar la barra de menús a la ventana
    SetMenuBar(menuBar);
    
    // === BARRA DE ESTADO ===
    CreateStatusBar();  // Crear barra de estado en la parte inferior
    SetStatusText("¡Aplicación wxWidgets + SDL3 lista!");
    
    // === CREACIÓN DE LA INTERFAZ PRINCIPAL ===
    
    // Crear panel principal (contenedor para otros controles)
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    
    // Crear sizer vertical (administrador de layout)
    // Los sizers organizan automáticamente los elementos
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    // === TÍTULO PRINCIPAL ===
    wxStaticText* title = new wxStaticText(panel, wxID_ANY, 
        "Demostración wxWidgets + SDL3", 
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    
    // Configurar fuente del título (más grande y en negrita)
    wxFont titleFont = title->GetFont();
    titleFont.SetPointSize(16);           // Tamaño 16pt
    titleFont.SetWeight(wxFONTWEIGHT_BOLD); // Negrita
    title->SetFont(titleFont);
    
    // === TEXTO INFORMATIVO ===
    // Crear texto explicativo dinámico que incluye el estado de SDL3
    wxString infoText = 
        "Esta aplicación demuestra la integración de:\n"
        "• wxWidgets para interfaz nativa\n"
        "• SDL3 como backend de renderizado\n\n"
        "Estado de SDL3: ";
    
    // Agregar estado de SDL3 basado en si se inicializó correctamente
    infoText += (sdl_window ? "✓ Inicializado" : "✗ Error");
    
    // Crear control de texto estático para mostrar la información
    wxStaticText* info = new wxStaticText(panel, wxID_ANY, infoText,
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    
    // === BOTONES INTERACTIVOS ===
    wxButton* testBtn = new wxButton(panel, ID_Hello, "Prueba de Funcionalidad");
    wxButton* exitBtn = new wxButton(panel, wxID_EXIT, "Salir");
    
    // === ORGANIZACIÓN DEL LAYOUT ===
    // Agregar elementos al sizer con espaciado y alineación
    sizer->Add(title, 0, wxALL | wxCENTER, 20);     // Título con margen 20px
    sizer->Add(info, 0, wxALL | wxCENTER, 20);      // Info con margen 20px
    sizer->Add(testBtn, 0, wxALL | wxCENTER, 10);   // Botón test con margen 10px
    sizer->Add(exitBtn, 0, wxALL | wxCENTER, 10);   // Botón salir con margen 10px
    
    // Asignar el sizer al panel (esto hace que se organicen automáticamente)
    panel->SetSizer(sizer);
    
    // === CONFIGURACIÓN FINAL DE LA VENTANA ===
    SetSize(500, 400);  // Tamaño inicial: 500x400 píxeles
    Center();           // Centrar la ventana en la pantalla
}

/**
 * INICIALIZACIÓN DE SDL3
 * Esta función configura SDL3 para trabajar junto con wxWidgets
 * Retorna true si la inicialización fue exitosa, false en caso contrario
 */
bool MyFrame::InitSDL() {
    // Inicializar el subsistema de video de SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // Crear una ventana SDL (oculta, solo para demostración)
    // En una aplicación real, podrías integrar esta ventana en un panel wxWidgets
    sdl_window = SDL_CreateWindow("SDL3 Backend", 400, 300, SDL_WINDOW_HIDDEN);
    if (!sdl_window) {
        std::cerr << "Error al crear ventana SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // Crear renderer para operaciones de dibujo
    sdl_renderer = SDL_CreateRenderer(sdl_window, nullptr);
    if (!sdl_renderer) {
        std::cerr << "Error al crear renderer SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    
    std::cout << "SDL3 inicializado correctamente!" << std::endl;
    return true;
}

/**
 * MANEJADORES DE EVENTOS
 * Estas funciones se ejecutan cuando el usuario interactúa con la interfaz
 */

// Manejador del botón/menú "Salir"
void MyFrame::OnExit(wxCommandEvent& event) {
    Close(true);  // Cerrar la ventana permitiendo que OnClose() haga la limpieza
}

// Manejador del menú "Acerca de"
void MyFrame::OnAbout(wxCommandEvent& event) {
    // Mostrar cuadro de diálogo informativo
    wxMessageBox("Aplicación de demostración que combina wxWidgets con SDL3.\n\n"
                 "wxWidgets: Interfaz nativa profesional\n"
                 "SDL3: Backend de renderizado de alto rendimiento\n\n"
                 "Esta arquitectura es ideal para aplicaciones que requieren\n"
                 "GUI profesional con capacidades gráficas avanzadas.",
                 "Acerca de wxWidgets + SDL3",
                 wxOK | wxICON_INFORMATION);  // Botón OK + icono de información
}

// Manejador del botón "Prueba de Funcionalidad"
void MyFrame::OnHello(wxCommandEvent& event) {
    // Crear mensaje de estado del sistema
    std::string message = "✓ wxWidgets: Funcionando\n";
    
    // Probar funcionalidad de SDL3
    if (sdl_renderer) {
        // Realizar una operación básica de renderizado como prueba
        // Pintar la ventana SDL de rojo
        SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255);  // Rojo
        SDL_RenderClear(sdl_renderer);    // Limpiar con el color
        SDL_RenderPresent(sdl_renderer);  // Mostrar el resultado
        
        message += "✓ SDL3: Funcionando\n";
        message += "✓ Integración: Exitosa";
    } else {
        message += "✗ SDL3: Error\n";
        message += "⚠ Integración: Parcial";
    }
    
    // Mostrar resultado de la prueba
    wxMessageBox(message, "Test de Funcionalidad", wxOK | wxICON_INFORMATION);
}

// Manejador del evento de cierre de ventana
void MyFrame::OnClose(wxCloseEvent& event) {
    // === LIMPIEZA DE RECURSOS SDL3 ===
    // Es importante liberar los recursos de SDL3 antes de cerrar
    
    // Destruir renderer si existe
    if (sdl_renderer) {
        SDL_DestroyRenderer(sdl_renderer);
        sdl_renderer = nullptr;  // Evitar doble liberación
    }
    
    // Destruir ventana si existe
    if (sdl_window) {
        SDL_DestroyWindow(sdl_window);
        sdl_window = nullptr;    // Evitar doble liberación
    }
    
    // Finalizar SDL3 completamente
    SDL_Quit();
    
    // Destruir la ventana wxWidgets
    // Esto finaliza la aplicación
    Destroy();
}
