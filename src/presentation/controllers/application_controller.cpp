/**
 * IMPLEMENTACIÓN: APPLICATION CONTROLLER (PRESENTATION)
 */

#include "application_controller.hpp"
#include <iostream> // Agregado para std::cerr y std::endl

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

            try {
                // Ejecutar caso de uso de inicialización
                bool success = initialize_use_case_->Execute();
                if (success) {
                    initialized_ = true;
                }
                return success;
            } catch (const std::exception& e) {
                // Manejo de errores: registrar excepción
                std::cerr << "Error durante la inicialización: " << e.what() << std::endl;
                return false;
            }
        }

        void ApplicationController::Shutdown() {
            if (initialized_) {
                try {
                    auto app = GetApplication();
                    if (app) {
                        app->Shutdown();
                        app_repository_->SaveApplicationState(*app);
                    }
                    initialized_ = false;
                } catch (const std::exception& e) {
                    // Manejo de errores: registrar excepción
                    std::cerr << "Error durante el apagado: " << e.what() << std::endl;
                }
            }
        }

        std::shared_ptr<Domain::Entities::Application> ApplicationController::GetApplication() const {
            try {
                if (initialize_use_case_) {
                    return initialize_use_case_->GetApplication();
                }
            } catch (const std::exception& e) {
                // Manejo de errores: registrar excepción
                std::cerr << "Error al obtener la aplicación: " << e.what() << std::endl;
            }
            return nullptr;
        }

        void ApplicationController::SetApplicationTitle(const std::string& title) {
            try {
                auto app = GetApplication();
                if (app) {
                    app->SetTitle(title);
                    app_repository_->SaveApplicationState(*app);
                }
            } catch (const std::exception& e) {
                // Manejo de errores: registrar excepción
                std::cerr << "Error al establecer el título de la aplicación: " << e.what() << std::endl;
            }
        }

    } // namespace Controllers
} // namespace Presentation
