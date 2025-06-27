/**
 * IMPLEMENTACIÓN: APPLICATION ENTITY
 */

#include "application.hpp"

namespace Domain {
    namespace Entities {
        
        Application::Application() 
            : title_("wxWidgets App"), 
              state_(AppState::INITIALIZING),
              initialized_(false) {
        }
        
        void Application::Initialize() {
            if (!initialized_) {
                state_ = AppState::RUNNING;
                initialized_ = true;
            }
        }
        
        void Application::Shutdown() {
            if (initialized_) {
                state_ = AppState::SHUTTING_DOWN;
                initialized_ = false;
            }
        }
        
        void Application::SetTitle(const std::string& title) {
            title_ = title;
        }
        
    } // namespace Entities
} // namespace Domain
