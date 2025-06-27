/**
 * DATA MODEL: APPLICATION CONFIG
 * 
 * Modelo de datos para la configuración de la aplicación.
 * Usado para serialización/deserialización.
 */

#pragma once

#include <string>
#include <map>

namespace Data {
    namespace Models {
        
        struct ApplicationConfigModel {
            std::string title;
            int window_width;
            int window_height;
            std::string theme;
            bool maximized;
            
            // Constructor con valores por defecto
            ApplicationConfigModel() 
                : title("wxWidgets App"),
                  window_width(1200),
                  window_height(800),
                  theme("dark"),
                  maximized(false) {
            }
            
            // Convertir a mapa para almacenamiento
            std::map<std::string, std::string> ToMap() const;
            
            // Crear desde mapa
            static ApplicationConfigModel FromMap(const std::map<std::string, std::string>& data);
        };
        
    } // namespace Models
} // namespace Data
