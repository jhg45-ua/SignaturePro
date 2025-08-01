/**
 * IMPLEMENTACIÓN: APPLICATION CONTROLLER (PRESENTATION)
 */

#include "application_controller.hpp"

namespace Presentation {
    namespace Controllers {
        
        ApplicationController::ApplicationController() : initialized_(false) {
            // Crear repositorio
            app_repository_ = std::make_shared<Data::Repositories::ApplicationRepository>();
            
            // Crear caso de uso
            initialize_use_case_ = std::make_unique<Domain::UseCases::InitializeApplicationUseCase>(app_repository_);
        }
        
        bool ApplicationController::Initialize() {
            if (initialized_) {
                return true;
            }
            
            // Ejecutar caso de uso de inicialización
            bool success = initialize_use_case_->Execute();
            if (success) {
                initialized_ = true;
            }
            
            return success;
        }
        
        void ApplicationController::Shutdown() {
            if (!initialized_) {
                return; // Ya se hizo shutdown o nunca se inicializó
            }
            
            try {
                auto app = GetApplication();
                if (app) {
                    app->Shutdown();
                    if (app_repository_) {
                        app_repository_->SaveApplicationState(*app);
                    }
                }
            } catch (const std::exception& e) {
                // Log error but continue with cleanup
                // No podemos usar logging aquí porque puede estar siendo destruido
            }
            
            initialized_ = false;
        }
        
        std::shared_ptr<Domain::Entities::Application> ApplicationController::GetApplication() const {
            if (initialize_use_case_) {
                return initialize_use_case_->GetApplication();
            }
            return nullptr;
        }
        
        void ApplicationController::SetApplicationTitle(const std::string& title) {
            auto app = GetApplication();
            if (app) {
                app->SetTitle(title);
                app_repository_->SaveApplicationState(*app);
            }
        }
        
    } // namespace Controllers
} // namespace Presentation
