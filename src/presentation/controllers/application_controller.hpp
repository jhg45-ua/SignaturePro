/**
 * PRESENTATION CONTROLLER: APPLICATION CONTROLLER
 * 
 * Controlador que coordina la lógica de presentación
 * con los casos de uso del dominio.
 */

#pragma once

#include "../../domain/usecases/initialize_application.hpp"
#include "../../data/repositories/application_repository.hpp"
#include <memory>

namespace Presentation {
    namespace Controllers {
        
        class ApplicationController {
        public:
            ApplicationController();
            ~ApplicationController() = default;
            
            // Inicialización y configuración
            bool Initialize();
            void Shutdown();
            
            // Getters para la lógica de presentación
            std::shared_ptr<Domain::Entities::Application> GetApplication() const;
            
            // Acciones de la aplicación
            void SetApplicationTitle(const std::string& title);
            
        private:
            // Repositorios
            std::shared_ptr<Data::Repositories::ApplicationRepository> app_repository_;
            
            // Casos de uso
            std::unique_ptr<Domain::UseCases::InitializeApplicationUseCase> initialize_use_case_;
            
            // Estado
            bool initialized_;
        };
        
    } // namespace Controllers
} // namespace Presentation
