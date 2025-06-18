# 🏗️ Diagramas de Arquitectura - wxWidgets + SDL3

## 📊 Diagrama de Clases UML

```
┌─────────────────────────────────────┐
│              MyApp                  │
│         <<wxApp>>                   │
├─────────────────────────────────────┤
│ + OnInit() : bool                   │
└─────────────────┬───────────────────┘
                  │ creates
                  ▼
┌─────────────────────────────────────┐
│              MyFrame                │
│         <<wxFrame>>                 │
├─────────────────────────────────────┤
│ - sdl_manager_ : SDL3Manager*       │
│ - main_panel_ : wxPanel*            │
│ - main_sizer_ : wxBoxSizer*         │
│ - title_text_ : wxStaticText*       │
│ - info_text_ : wxStaticText*        │
│ - test_button_ : wxButton*          │
│ - exit_button_ : wxButton*          │
├─────────────────────────────────────┤
│ + MyFrame()                         │
│ + ~MyFrame()                        │
│ - InitializeComponents() : void     │
│ - CreateMenuSystem() : void         │
│ - CreateMainInterface() : void      │
│ - ConfigureLayout() : void          │
│ - OnHello(wxCommandEvent&) : void   │
│ - OnExit(wxCommandEvent&) : void    │
│ - OnAbout(wxCommandEvent&) : void   │
│ - OnClose(wxCloseEvent&) : void     │
└─────────────────┬───────────────────┘
                  │ uses
                  ▼
┌─────────────────────────────────────┐
│           SDL3Manager               │
├─────────────────────────────────────┤
│ - window_ : SDL_Window*             │
│ - renderer_ : SDL_Renderer*         │
│ - initialized_ : bool               │
├─────────────────────────────────────┤
│ + SDL3Manager()                     │
│ + ~SDL3Manager()                    │
│ + Initialize() : bool               │
│ + Cleanup() : void                  │
│ + IsInitialized() : bool const      │
│ + TestRendering() : bool            │
│ + GetLastError() : string const     │
└─────────────────────────────────────┘

┌─────────────────────────────────────┐
│              Logger                 │
│         <<static class>>            │
├─────────────────────────────────────┤
│ - default_logger_ : spdlog::logger* │
├─────────────────────────────────────┤
│ + Initialize() : void               │
│ + SetLevel(level_enum) : void       │
│ + GetDefault() : logger*            │
└─────────────────────────────────────┘

┌─────────────────────────────────────┐
│            Constants                │
│         <<namespace>>               │
├─────────────────────────────────────┤
│ + MenuIds::ID_Hello : int           │
│ + Window::DEFAULT_WIDTH : int       │
│ + Window::DEFAULT_HEIGHT : int      │
│ + Window::TITLE : char*             │
│ + SDL::WINDOW_WIDTH : int           │
│ + SDL::WINDOW_HEIGHT : int          │
│ + SDL::WINDOW_TITLE : char*         │
│ + Text::INFO_TEXT : char*           │
│ + Text::ABOUT_TEXT : char*          │
│ + Status::SDL_INIT_SUCCESS : char*  │
│ + Status::SDL_INIT_ERROR : char*    │
└─────────────────────────────────────┘
```

## 🔄 Diagrama de Secuencia - Inicialización

```
MyApp    MyFrame    SDL3Manager    Logger    wxWidgets
  │         │           │           │           │
  │ OnInit()│           │           │           │
  ├─────────┼───────────┼───────────┼───────────┤
  │         │           │Initialize()│           │
  │         │           │           └───────────┤
  │         │           │                       │
  │new MyFrame()        │           │           │
  ├─────────┐           │           │           │
  │         │ constructor│           │           │
  │         ├───────────┼───────────┼───────────┤
  │         │           │           │           │
  │         │ InitializeComponents() │           │
  │         ├───────────┼───────────┼───────────┤
  │         │           │           │           │
  │         │Initialize()│           │           │
  │         ├───────────┐           │           │
  │         │           │SDL_Init() │           │
  │         │           ├───────────┼───────────┤
  │         │           │           │           │
  │         │           │SDL_CreateWindow()     │
  │         │           ├───────────┼───────────┤
  │         │           │           │           │
  │         │           │SDL_CreateRenderer()   │
  │         │           ├───────────┼───────────┤
  │         │           │           │           │
  │         │           │return true│           │
  │         │           └───────────┼───────────┤
  │         │                       │           │
  │         │CreateMenuSystem()     │           │
  │         ├───────────┼───────────┼───────────┤
  │         │           │           │           │
  │         │CreateMainInterface()  │           │
  │         ├───────────┼───────────┼───────────┤
  │         │           │           │           │
  │         │ConfigureLayout()      │           │
  │         ├───────────┼───────────┼───────────┤
  │         │           │           │           │
  │Show(true)           │           │           │
  └─────────┼───────────┼───────────┼───────────┤
            │           │           │           │
```

## 📱 Diagrama de Estados - SDL3Manager

```
         ┌─────────────┐
         │ Constructor │
         │ Executed    │
         └──────┬──────┘
                │
                ▼
         ┌─────────────┐
         │    Not      │
         │ Initialized │
         └──────┬──────┘
                │ Initialize()
                ▼
         ┌─────────────┐    Initialize()
         │             │◄───────────────┐
         │ Initializing│                │
         │             │                │
         └──────┬──────┘                │
                │                       │
                ▼                       │
         ┌─────────────┐                │
    ┌────┤ SDL_Init()  │                │
    │    │   Failed    │                │
    │    └─────────────┘                │
    │                                   │
    │    ┌─────────────┐                │
    └────►Create Window│                │
         │   Failed    │                │
         └─────────────┘                │
                                        │
         ┌─────────────┐                │
    ┌────►Create Render│                │
    │    │   Failed    │                │
    │    └─────────────┘                │
    │                                   │
    │    ┌─────────────┐                │
    │    │             │   Error        │
    └────┤    Error    ├────────────────┘
         │    State    │
         └─────────────┘
                
         ┌─────────────┐
         │             │ TestRendering()
         │ Initialized │◄────────────────┐
         │    Ready    │                 │
         └──────┬──────┘                 │
                │                       │
                ▼                       │
         ┌─────────────┐                │
         │ Rendering   │                │
         │   Active    ├────────────────┘
         └──────┬──────┘
                │ Cleanup() or Destructor
                ▼
         ┌─────────────┐
         │   Cleanup   │
         │  Complete   │
         └─────────────┘
```

## 🎯 Diagrama de Interacciones - Evento OnHello

```
    User         MyFrame      SDL3Manager      Logger       Dialog
     │             │              │             │            │
     │ Click Button│              │             │            │
     ├─────────────►              │             │            │
     │             │              │             │            │
     │             │ OnHello()    │             │            │
     │             ├──────────────┼─────────────►            │
     │             │              │             │ "Ejecutando│
     │             │              │             │ prueba..." │
     │             │              │             │            │
     │             │TestRendering()│             │            │
     │             ├──────────────►             │            │
     │             │              │             │            │
     │             │              │IsInitialized()           │
     │             │              ├─────────────┼────────────┤
     │             │              │             │            │
     │             │              │ return true │            │
     │             │              ├─────────────┼────────────┤
     │             │              │             │            │
     │             │              │SDL_SetRenderDrawColor()  │
     │             │              ├─────────────┼────────────┤
     │             │              │             │            │
     │             │              │SDL_RenderClear()         │
     │             │              ├─────────────┼────────────┤
     │             │              │             │            │
     │             │              │SDL_RenderPresent()       │
     │             │              ├─────────────┼────────────┤
     │             │              │             │            │
     │             │              │Log Success  │            │
     │             │              ├─────────────►            │
     │             │              │             │ "Prueba    │
     │             │              │             │ exitosa"   │
     │             │              │ return true │            │
     │             │              ├─────────────┼────────────┤
     │             │ return true  │             │            │
     │             │◄─────────────┤             │            │
     │             │              │             │            │
     │             │Build Message │             │            │
     │             ├──────────────┼─────────────┼────────────┤
     │             │              │             │            │
     │             │wxMessageBox()│             │            │
     │             ├──────────────┼─────────────┼────────────►
     │             │              │             │            │ Show Dialog
     │◄────────────┼──────────────┼─────────────┼────────────┤ "✓ wxWidgets:
     │ Dialog      │              │             │            │  Funcionando
     │ Visible     │              │             │            │  ✓ SDL3:
     │             │              │             │            │  Funcionando
     │             │              │             │            │  ✓ Integración:
     │             │              │             │            │  Exitosa"
```

## 🏛️ Arquitectura por Capas

```
┌─────────────────────────────────────────────────────────────┐
│                    CAPA DE PRESENTACIÓN                     │
│                      (User Interface)                       │
├─────────────────────────────────────────────────────────────┤
│  MyFrame  │  wxMenuBar  │  wxPanel  │  wxButton  │  etc.   │
│           │             │           │            │         │
│  ┌─────────────┐ ┌─────────────┐ ┌─────────────┐          │
│  │   Menús     │ │  Controles  │ │   Layout    │          │
│  │   Nativos   │ │  wxWidgets  │ │  Managers   │          │
│  └─────────────┘ └─────────────┘ └─────────────┘          │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                     CAPA DE LÓGICA                         │
│                   (Business Logic)                         │
├─────────────────────────────────────────────────────────────┤
│           MyApp          │        Event Handlers          │
│                          │                                │
│  ┌─────────────┐ ┌─────────────┐ ┌─────────────┐          │
│  │ Application │ │   Events    │ │   Control   │          │
│  │    Logic    │ │  Routing    │ │    Flow     │          │
│  └─────────────┘ └─────────────┘ └─────────────┘          │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                   CAPA DE SERVICIOS                        │
│                   (Service Layer)                          │
├─────────────────────────────────────────────────────────────┤
│  SDL3Manager  │    Logger     │   Constants   │  Utils    │
│               │               │               │           │
│  ┌─────────────┐ ┌─────────────┐ ┌─────────────┐          │
│  │ Rendering   │ │  Logging    │ │    Config   │          │
│  │  Service    │ │   Service   │ │   Service   │          │
│  └─────────────┘ └─────────────┘ └─────────────┘          │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                  CAPA DE INFRAESTRUCTURA                   │
│                  (Infrastructure Layer)                    │
├─────────────────────────────────────────────────────────────┤
│   wxWidgets   │     SDL3      │   spdlog    │   System    │
│               │               │             │             │
│  ┌─────────────┐ ┌─────────────┐ ┌─────────────┐          │
│  │    GUI      │ │  Graphics   │ │   Logging   │          │
│  │ Framework   │ │    API      │ │    API      │          │
│  └─────────────┘ └─────────────┘ └─────────────┘          │
└─────────────────────────────────────────────────────────────┘
```

## 🔗 Diagrama de Dependencias

```
         main_modular.cpp
                │
                ▼
            include.hpp
                │
       ┌────────┼────────┐
       ▼        ▼        ▼
   my_app.hpp  my_frame.hpp  constants.hpp
       │        │               │
       ▼        ▼               ▼
   my_app.cpp  my_frame.cpp   (header-only)
              │        │
              ▼        ▼
      sdl3_manager.hpp  logger.hpp
              │              │
              ▼              ▼
      sdl3_manager.cpp   logger.cpp
              │              │
              ▼              ▼
            SDL3          spdlog
```

## 📈 Flujo de Datos

```
┌─────────────┐    User Input    ┌─────────────┐
│             ├─────────────────► │             │
│    User     │                  │   MyFrame   │
│             │◄─────────────────┤             │
└─────────────┘   Visual Feedback└──────┬──────┘
                                         │
                                         ▼
                                  ┌─────────────┐
                                  │             │
                                  │Event Handler│
                                  │             │
                                  └──────┬──────┘
                                         │
                                         ▼
                                  ┌─────────────┐
                                  │             │
                                  │SDL3Manager  │
                                  │             │
                                  └──────┬──────┘
                                         │
                                         ▼
                                  ┌─────────────┐
                                  │             │
                                  │    SDL3     │
                                  │   System    │
                                  └──────┬──────┘
                                         │
                                         ▼
                                  ┌─────────────┐
                                  │             │
                                  │  Hardware   │
                                  │  Graphics   │
                                  └─────────────┘
```

---

**🎯 Estos diagramas muestran la estructura completa y las interacciones de la aplicación modular wxWidgets + SDL3**
