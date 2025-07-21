/**
 * USE CASE: INITIALIZE APPLICATION
 * 
 * Caso de uso para inicializar la aplicación.
 * Encapsula la lógica de negocio de inicialización.
 */

#pragma once

#include "../entities/application.hpp"
#include "../repositories/application_repository.hpp"
#include <memory>

namespace Domain {
    namespace UseCases {
        
        class InitializeApplicationUseCase {
        public:
            explicit InitializeApplicationUseCase(
                std::shared_ptr<Repositories::IApplicationRepository> repository);
            
            ~InitializeApplicationUseCase() = default;
            
            // Ejecutar el caso de uso
            bool Execute();
            
            // Obtener la aplicación inicializada
            std::shared_ptr<Entities::Application> GetApplication() const { return application_; }
            
        private:
            std::shared_ptr<Repositories::IApplicationRepository> repository_;
            std::shared_ptr<Entities::Application> application_;
        };
        
    } // namespace UseCases
} // namespace Domain
