/**
 * IMPLEMENTACIÓN DEL SDL3 MANAGER
 */

#include "sdl3_manager.hpp"
#include "logger.hpp"
#include "constants.hpp"

SDL3Manager::SDL3Manager() 
    : window_(nullptr), renderer_(nullptr), initialized_(false) {
}

SDL3Manager::~SDL3Manager() {
    Cleanup();
}

bool SDL3Manager::Initialize() {
    spdlog::info("Inicializando SDL3...");
    
    // Inicializar el subsistema de video de SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        spdlog::error("Error al inicializar SDL: {}", SDL_GetError());
        return false;
    }
    
    // Crear ventana SDL (oculta, solo para demostración)
    window_ = SDL_CreateWindow(
        Constants::SDL::WINDOW_TITLE,
        Constants::SDL::WINDOW_WIDTH,
        Constants::SDL::WINDOW_HEIGHT,
        SDL_WINDOW_HIDDEN
    );
    
    if (!window_) {
        spdlog::error("Error al crear ventana SDL: {}", SDL_GetError());
        SDL_Quit();
        return false;
    }
    
    // Crear renderer para operaciones de dibujo
    renderer_ = SDL_CreateRenderer(window_, nullptr);
    if (!renderer_) {
        spdlog::error("Error al crear renderer SDL: {}", SDL_GetError());
        SDL_DestroyWindow(window_);
        window_ = nullptr;
        SDL_Quit();
        return false;
    }
    
    initialized_ = true;
    spdlog::info("SDL3 inicializado correctamente!");
    return true;
}

void SDL3Manager::Cleanup() {
    if (!initialized_) {
        return;
    }
    
    spdlog::info("Limpiando recursos SDL3...");
    
    // Destruir renderer si existe
    if (renderer_) {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
        spdlog::debug("SDL renderer destruido");
    }
    
    // Destruir ventana si existe
    if (window_) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
        spdlog::debug("SDL window destruida");
    }
    
    // Finalizar SDL3 completamente
    SDL_Quit();
    initialized_ = false;
    spdlog::info("SDL3 finalizado correctamente");
}

bool SDL3Manager::IsInitialized() const {
    return initialized_ && renderer_ != nullptr;
}

bool SDL3Manager::TestRendering() {
    if (!IsInitialized()) {
        spdlog::warn("SDL3 no está inicializado para la prueba de renderizado");
        return false;
    }
    
    spdlog::debug("Probando renderizado SDL3...");
    
    // Realizar una operación básica de renderizado como prueba
    // Pintar la ventana SDL de rojo
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);  // Rojo
    SDL_RenderClear(renderer_);    // Limpiar con el color
    SDL_RenderPresent(renderer_);  // Mostrar el resultado
    
    spdlog::info("Prueba de SDL3 exitosa");
    return true;
}

std::string SDL3Manager::GetLastError() const {
    const char* error = SDL_GetError();
    return error ? std::string(error) : std::string("Sin error");
}
