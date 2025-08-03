/**
 * IMPLEMENTACIÓN: APPLICATION ENTITY
 */

#include "application.hpp"
#include "../../config/logger.hpp" // Agregado para spdlog

namespace Domain {
    namespace Entities {
        
        Application::Application() 
            : title_("wxWidgets App"), 
              state_(AppState::INITIALIZING),
              initialized_(false) {
        }
        
        void Application::Initialize() {
            if (!initialized_) {
                // Cambiar el estado de la aplicación a RUNNING
                state_ = AppState::RUNNING;
                initialized_ = true;
            } else {
                // Registrar advertencia si ya está inicializada
                spdlog::warn("La aplicación ya estaba inicializada.");
            }
        }
        
        void Application::Shutdown() {
            if (initialized_) {
                // Cambiar el estado de la aplicación a SHUTTING_DOWN
                state_ = AppState::SHUTTING_DOWN;
                initialized_ = false;
            } else {
                // Registrar advertencia si ya estaba apagada
                spdlog::warn("La aplicación ya estaba apagada.");
            }
        }
        
        void Application::SetTitle(const std::string& title) {
            title_ = title;
        }
        
    } // namespace Entities
} // namespace Domain
