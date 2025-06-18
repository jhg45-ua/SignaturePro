/**
 * CONSTANTES Y ENUMERACIONES
 * 
 * Este archivo centraliza todas las constantes, IDs y enumeraciones
 * utilizadas en la aplicación para facilitar el mantenimiento.
 */

#pragma once

namespace Constants {
    // === IDS DE ELEMENTOS DE LA INTERFAZ ===
    enum MenuIds {
        ID_Hello = 1  // ID personalizado para el botón/menú "Hola"
                     // wxID_EXIT y wxID_ABOUT ya están predefinidos en wxWidgets
    };
    
    // === CONFIGURACIÓN DE VENTANA ===
    namespace Window {
        static const int DEFAULT_WIDTH = 500;
        static const int DEFAULT_HEIGHT = 400;
        static const char* TITLE = "wxWidgets + SDL3 Demo";
    }
    
    // === CONFIGURACIÓN DE SDL ===
    namespace SDL {
        static const int WINDOW_WIDTH = 400;
        static const int WINDOW_HEIGHT = 300;
        static const char* WINDOW_TITLE = "SDL3 Backend";
    }
    
    // === CONFIGURACIÓN DE FUENTES ===
    namespace Fonts {
        static const int TITLE_SIZE = 16;
    }
    
    // === TEXTOS DE LA INTERFAZ ===
    namespace Text {
        static const char* INFO_TEXT = 
            "Esta aplicación demuestra la integración de:\n"
            "• wxWidgets para interfaz nativa\n"
            "• SDL3 como backend de renderizado\n\n"
            "Estado de SDL3: ";
            
        static const char* ABOUT_TEXT = 
            "Aplicación de demostración que combina wxWidgets con SDL3.\n\n"
            "wxWidgets: Interfaz nativa profesional\n"
            "SDL3: Backend de renderizado de alto rendimiento\n\n"
            "Esta arquitectura es ideal para aplicaciones que requieren\n"
            "GUI profesional con capacidades gráficas avanzadas.";
            
        static const char* ABOUT_TITLE = "Acerca de wxWidgets + SDL3";
        static const char* TEST_TITLE = "Test de Funcionalidad";
    }
    
    // === MENSAJES DE STATUS ===
    namespace Status {
        static const char* SDL_INIT_SUCCESS = "SDL3 inicializado correctamente";
        static const char* SDL_INIT_ERROR = "Error al inicializar SDL3";
        static const char* APP_READY = "¡Aplicación wxWidgets + SDL3 lista!";
        static const char* SDL_STATUS_OK = "✓ Inicializado";
        static const char* SDL_STATUS_ERROR = "✗ Error";
    }
}
