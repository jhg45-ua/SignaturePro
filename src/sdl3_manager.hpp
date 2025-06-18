/**
 * SDL3 MANAGER
 * 
 * Clase que encapsula toda la funcionalidad relacionada con SDL3,
 * incluyendo inicialización, limpieza y operaciones básicas de renderizado.
 */

#pragma once

#include <SDL3/SDL.h>
#include <string>

class SDL3Manager {
public:
    /**
     * Constructor
     */
    SDL3Manager();
    
    /**
     * Destructor - limpia automáticamente los recursos
     */
    ~SDL3Manager();
    
    /**
     * Inicializa SDL3 y crea la ventana y renderer
     * @return true si la inicialización fue exitosa
     */
    bool Initialize();
    
    /**
     * Limpia todos los recursos de SDL3
     */
    void Cleanup();
    
    /**
     * Verifica si SDL3 está inicializado correctamente
     * @return true si está inicializado
     */
    bool IsInitialized() const;
    
    /**
     * Realiza una prueba básica de renderizado
     * @return true si la prueba fue exitosa
     */
    bool TestRendering();
    
    /**
     * Obtiene el último error de SDL3
     * @return String con el mensaje de error
     */
    std::string GetLastError() const;

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    bool initialized_;
    
    // Deshabilitar copia y asignación
    SDL3Manager(const SDL3Manager&) = delete;
    SDL3Manager& operator=(const SDL3Manager&) = delete;
};
