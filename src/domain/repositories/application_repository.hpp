/**
 * REPOSITORY INTERFACE: APPLICATION REPOSITORY
 * 
 * Define el contrato para el manejo de datos de la aplicación.
 * Implementación de Clean Architecture - capa Domain.
 */

#pragma once

#include "../entities/application.hpp"
#include <memory>

namespace Domain {
    namespace Repositories {
        
        class IApplicationRepository {
        public:
            virtual ~IApplicationRepository() = default;
            
            // Operaciones de persistencia
            virtual bool SaveApplicationState(const Entities::Application& app) = 0;
            virtual std::unique_ptr<Entities::Application> LoadApplicationState() = 0;
            
            // Configuraciones
            virtual bool SaveConfiguration(const std::string& key, const std::string& value) = 0;
            virtual std::string LoadConfiguration(const std::string& key, const std::string& defaultValue = "") = 0;
        };
        
    } // namespace Repositories
} // namespace Domain
