/**
 * ENTIDAD: APPLICATION STATE
 * 
 * Representa el estado de la aplicación en el dominio.
 * Esta entidad encapsula la lógica de negocio central.
 */

#pragma once

#include <string>
#include <memory>

namespace Domain {
    namespace Entities {
        
        enum class AppState {
            INITIALIZING,
            RUNNING,
            SHUTTING_DOWN,
            ERROR
        };
        
        class Application {
        public:
            Application();
            ~Application() = default;
            
            // Getters
            const std::string& GetTitle() const { return title_; }
            AppState GetState() const { return state_; }
            bool IsInitialized() const { return initialized_; }
            
            // Business logic
            void Initialize();
            void Shutdown();
            void SetTitle(const std::string& title);
            
        private:
            std::string title_;
            AppState state_;
            bool initialized_;
        };
        
    } // namespace Entities
} // namespace Domain
