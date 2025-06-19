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
        static const char* TITLE = "wxWidgets App";
    }
    
    // === CONFIGURACIÓN DE FUENTES ===
    namespace Fonts {
        static const int TITLE_SIZE = 16;
    }
    
    // === TEXTOS DE LA INTERFAZ ===
    namespace Text {
        static const char* INFO_TEXT = 
            "Esta aplicación demuestra las capacidades de wxWidgets:\n"
            "• Interfaz nativa multiplataforma\n"
            "• Sistema de eventos robusto\n"
            "• Componentes profesionales\n\n"
            "¡Aplicación lista para usar!";
            
        static const char* ABOUT_TEXT = 
            "Aplicación de demostración con wxWidgets.\n\n"
            "wxWidgets: Framework GUI multiplataforma\n"
            "- Interfaz nativa en cada sistema operativo\n"
            "- Amplia colección de controles\n"
            "- Sistema de eventos potente\n\n"
            "Ideal para aplicaciones de escritorio profesionales.";
            
        static const char* ABOUT_TITLE = "Acerca de wxWidgets App";
        static const char* TEST_TITLE = "Test de Funcionalidad";
    }
    
    // === MENSAJES DE STATUS ===
    namespace Status {
        static const char* APP_READY = "¡Aplicación wxWidgets lista!";
        static const char* COMPONENTS_OK = "✓ Todos los componentes funcionando";
        static const char* TEST_SUCCESS = "✓ Prueba exitosa";
    }
}
