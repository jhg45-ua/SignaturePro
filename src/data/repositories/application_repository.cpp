/**
 * IMPLEMENTACIÓN: APPLICATION REPOSITORY
 */

#include "application_repository.hpp"

namespace Data {
    namespace Repositories {
        
        ApplicationRepository::ApplicationRepository() : has_saved_state_(false) {
            // Cargar configuraciones por defecto
            configuration_store_["app_title"] = "wxWidgets App";
            configuration_store_["theme"] = "dark";
            configuration_store_["window_width"] = "1200";
            configuration_store_["window_height"] = "800";
        }
        
        bool ApplicationRepository::SaveApplicationState(const Domain::Entities::Application& app) {
            // Simular guardado del estado de la aplicación
            configuration_store_["app_title"] = app.GetTitle();
            configuration_store_["app_state"] = std::to_string(static_cast<int>(app.GetState()));
            has_saved_state_ = true;
            return true;
        }
        
        std::unique_ptr<Domain::Entities::Application> ApplicationRepository::LoadApplicationState() {
            if (!has_saved_state_) {
                return nullptr; // No hay estado guardado
            }
            
            auto app = std::make_unique<Domain::Entities::Application>();
            
            // Cargar configuraciones guardadas
            auto titleIt = configuration_store_.find("app_title");
            if (titleIt != configuration_store_.end()) {
                app->SetTitle(titleIt->second);
            }
            
            return app;
        }
        
        bool ApplicationRepository::SaveConfiguration(const std::string& key, const std::string& value) {
            configuration_store_[key] = value;
            return true;
        }
        
        std::string ApplicationRepository::LoadConfiguration(const std::string& key, const std::string& defaultValue) {
            auto it = configuration_store_.find(key);
            return (it != configuration_store_.end()) ? it->second : defaultValue;
        }
        
    } // namespace Repositories
} // namespace Data
