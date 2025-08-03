/**
 * IMPLEMENTACIÓN: INITIALIZE APPLICATION USE CASE
 */

#include "initialize_application.hpp"
#include "../../config/logger.hpp" // Agregado para spdlog

namespace Domain {
    namespace UseCases {
        
        InitializeApplicationUseCase::InitializeApplicationUseCase(
            std::shared_ptr<Repositories::IApplicationRepository> repository)
            : repository_(repository), application_(nullptr) {
        }
        
        bool InitializeApplicationUseCase::Execute() {
            try {
                // Intentar cargar estado existente
                application_ = repository_->LoadApplicationState();

                // Si no existe, crear nueva aplicación
                if (!application_) {
                    application_ = std::make_shared<Entities::Application>();
                }

                // Inicializar la aplicación
                application_->Initialize();

                // Guardar el estado
                return repository_->SaveApplicationState(*application_);

            } catch (const std::exception& e) {
                // Manejo de errores: registrar excepción
                spdlog::error("Error durante la inicialización de la aplicación: {}", e.what());
                return false;
            } catch (...) {
                // Manejo de errores genéricos
                spdlog::error("Error desconocido durante la inicialización de la aplicación");
                return false;
            }
        }
        
    } // namespace UseCases
} // namespace Domain
