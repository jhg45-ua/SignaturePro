# 🏗️ Diagramas de Arquitectura - Aplicación wxWidgets Modular

## 📊 Diagrama de Clases UML

```mermaid
classDiagram
    class MyApp {
        <<wxApp>>
        +OnInit() bool
    }
    
    class MyFrame {
        <<wxFrame>>
        -main_panel_ : wxPanel*
        -main_sizer_ : wxBoxSizer*
        -title_text_ : wxStaticText*
        -info_text_ : wxStaticText*
        -test_button_ : wxButton*
        -exit_button_ : wxButton*
        +MyFrame()
        +~MyFrame()
        -InitializeComponents() void
        -CreateMenuSystem() void
        -CreateMainInterface() void
        -ConfigureLayout() void
        -OnHello(wxCommandEvent&) void
        -OnExit(wxCommandEvent&) void
        -OnAbout(wxCommandEvent&) void
        -OnClose(wxCloseEvent&) void
    }
    
    class Logger {
        <<static class>>
        -default_logger_ : spdlog::logger*
        +Initialize() void
        +SetLevel(level_enum) void
        +GetDefault() logger*
    }
    
    class Constants {
        <<namespace>>
        +ID_Hello : int
        +Window::DEFAULT_WIDTH : int
        +Window::DEFAULT_HEIGHT : int
        +Window::TITLE : char*
        +Text::INFO_TEXT : char*
        +Text::ABOUT_TEXT : char*
        +Status::APP_READY : char*
        +Status::APP_CLOSING : char*
    }
    
    MyApp --> MyFrame : creates
    MyFrame --> Logger : uses
    MyFrame --> Constants : uses
```

## 🔄 Diagrama de Secuencia - Inicialización

```mermaid
sequenceDiagram
    participant Main as main.cpp
    participant App as MyApp
    participant Frame as MyFrame
    participant Logger as Logger
    participant wx as wxWidgets
    
    Main->>wx: wxIMPLEMENT_APP(MyApp)
    wx->>App: OnInit()
    App->>Logger: Initialize()
    Logger-->>App: Ready
    App->>Frame: new MyFrame()
    Frame->>Frame: InitializeComponents()
    Frame->>Frame: CreateMenuSystem()
    Frame->>Frame: CreateMainInterface()
    Frame->>Frame: ConfigureLayout()
    Frame->>wx: Show(true)
    wx-->>Main: Application Running
```
## 📱 Diagrama de Estados - MyFrame

```mermaid
stateDiagram-v2
    [*] --> Constructor
    Constructor --> Initializing: InitializeComponents()
    Initializing --> MenuCreation: CreateMenuSystem()
    MenuCreation --> InterfaceCreation: CreateMainInterface()
    InterfaceCreation --> LayoutConfig: ConfigureLayout()
    LayoutConfig --> Ready: Show()
    Ready --> EventHandling: User Interaction
    EventHandling --> Ready: Event Processed
    EventHandling --> Closing: OnClose()
    Closing --> [*]: Destructor
```

## 🎯 Diagrama de Interacciones - Evento OnHello

```mermaid
sequenceDiagram
    participant User as Usuario
    participant Frame as MyFrame
    participant Logger as Logger
    participant Dialog as wxMessageBox
    
    User->>Frame: Click Button / Menu
    Frame->>Logger: info("Ejecutando prueba...")
    Frame->>Frame: Build Message
    Frame->>Dialog: wxMessageBox()
    Dialog-->>User: Show Dialog
    User->>Dialog: OK
    Dialog-->>Frame: Dialog Closed
    Frame->>Logger: info("Prueba completada")
```
     │        ## 🏛️ Arquitectura por Capas

```mermaid
graph TB
    subgraph "� CAPA DE PRESENTACIÓN"
        A[MyFrame] --> B[wxMenuBar]
        A --> C[wxPanel]
        A --> D[wxButton]
        A --> E[wxStaticText]
        A --> F[wxSizer]
    end
    
    subgraph "🧠 CAPA DE LÓGICA"
        G[MyApp] --> H[Event Handlers]
        G --> I[Application Logic]
        G --> J[Control Flow]
    end
    
    subgraph "🔧 CAPA DE SERVICIOS"
        K[Logger] --> L[Logging Service]
        M[Constants] --> N[Config Service]
    end
    
    subgraph "🏗️ CAPA DE INFRAESTRUCTURA"
        O[wxWidgets] --> P[GUI Framework]
        Q[spdlog] --> R[Logging API]
        S[System] --> T[OS Services]
    end
    
    A --> G
    G --> K
    G --> M
    K --> Q
    M --> S
    O --> S
```

## 🔗 Diagrama de Dependencias

```mermaid
graph TD
    A[main.cpp] --> B[my_app.hpp]
    B --> C[my_app.cpp]
    C --> D[my_frame.hpp]
    D --> E[my_frame.cpp]
    E --> F[constants.hpp]
    E --> G[logger.hpp]
    G --> H[logger.cpp]
    H --> I[spdlog]
    E --> J[wxWidgets]
    
    style A fill:#e1f5fe
    style B fill:#f3e5f5
    style C fill:#f3e5f5
    style D fill:#e8f5e8
    style E fill:#e8f5e8
    style F fill:#fff3e0
    style G fill:#fff3e0
    style H fill:#fff3e0
    style I fill:#ffebee
    style J fill:#ffebee
```

## 📈 Flujo de Datos

```mermaid
graph TD
    A[👤 Usuario] -->|Input Events| B[MyFrame]
    B -->|Event Processing| C[Event Handlers]
    C -->|Log Actions| D[Logger]
    C -->|Show Dialogs| E[wxMessageBox]
    C -->|Update UI| F[UI Components]
    F -->|Visual Feedback| A
    D -->|Log Output| G[Console/File]
    
    style A fill:#e3f2fd
    style B fill:#f1f8e9
    style C fill:#fff3e0
    style D fill:#fce4ec
    style E fill:#f3e5f5
    style F fill:#e8f5e8
    style G fill:#ffebee
```

## 🔄 Diagrama de Flujo Completo de la Aplicación

```mermaid
flowchart TD
    subgraph "🚀 Inicio de Aplicación"
        A[main.cpp] --> B[wxIMPLEMENT_APP]
        B --> C[MyApp::OnInit]
    end
    
    subgraph "🔧 Inicialización de Servicios"
        C --> D[Logger::Initialize]
        D --> E[spdlog Configuration]
    end
    
    subgraph "🎨 Creación de UI"
        C --> F[new MyFrame]
        F --> G[MyFrame Constructor]
        G --> H[InitializeComponents]
        H --> I[CreateMenuSystem]
        H --> J[CreateMainInterface]
        H --> K[ConfigureLayout]
    end
    
    subgraph "🎯 Aplicación Lista"
        K --> L[Show Window]
        L --> M[Event Loop Started]
    end
    
    subgraph "⚡ Manejo de Eventos"
        M --> N{User Interaction}
        N -->|Menu Click| O[OnHello/OnAbout]
        N -->|Button Click| P[OnHello/OnExit]
        N -->|Window Close| Q[OnClose]
        
        O --> R[Log Action]
        P --> R
        Q --> R
        
        R --> S[Update UI]
        S --> M
    end
    
    subgraph "🔚 Cierre de Aplicación"
        Q --> T[Cleanup Resources]
        T --> U[Application Exit]
    end
    
    style A fill:#e3f2fd
    style E fill:#fce4ec
    style L fill:#e8f5e8
    style M fill:#fff3e0
    style U fill:#ffebee
```

---

**🎯 Estos diagramas muestran la estructura completa y las interacciones de la aplicación wxWidgets**
