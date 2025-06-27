/**
 * IMPLEMENTACIÓN: APPLICATION REPOSITORY
 * 
 * Implementación concreta del repositorio de aplicación.
 * Capa de Data - maneja persistencia y fuentes de datos.
 */

#pragma once

#include "../../domain/repositories/application_repository.hpp"
#include <map>
#include <string>

namespace Data {
    namespace Repositories {
        
        class ApplicationRepository : public Domain::Repositories::IApplicationRepository {
        public:
            ApplicationRepository();
            ~ApplicationRepository() override = default;
            
            // Implementación de la interfaz
            bool SaveApplicationState(const Domain::Entities::Application& app) override;
            std::unique_ptr<Domain::Entities::Application> LoadApplicationState() override;
            
            bool SaveConfiguration(const std::string& key, const std::string& value) override;
            std::string LoadConfiguration(const std::string& key, const std::string& defaultValue = "") override;
            
        private:
            // Simulación de almacenamiento en memoria
            // En una aplicación real, esto sería base de datos, archivos, etc.
            std::map<std::string, std::string> configuration_store_;
            bool has_saved_state_;
        };
        
    } // namespace Repositories
} // namespace Data
