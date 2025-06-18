/**
 * ARCHIVO DE CABECERAS PRINCIPAL
 * 
 * Este archivo centraliza todas las dependencias necesarias para
 * la aplicación wxWidgets + SDL3. Incluye:
 * - Headers básicos de wxWidgets para GUI nativa
 * - Headers específicos para controles y layouts
 * - SDL3 para renderizado de gráficos
 * - Librerías estándar de C++
 */

// === HEADERS PRINCIPALES DE WXWIDGETS ===
#include <wx/wx.h>          // Core de wxWidgets (App, Frame, eventos básicos)

// === CONTROLES Y LAYOUTS ===
#include <wx/panel.h>       // Panel contenedor
#include <wx/sizer.h>       // Administradores de layout (BoxSizer, etc.)
#include <wx/stattext.h>    // Texto estático (labels, títulos)
#include <wx/button.h>      // Botones interactivos

// === SISTEMA DE MENÚS ===
#include <wx/menu.h>        // Menús y barras de menú
#include <wx/menuitem.h>    // Items individuales de menú

// === DIÁLOGOS Y FUENTES ===
#include <wx/msgdlg.h>      // Cuadros de diálogo (MessageBox)
#include <wx/font.h>        // Configuración de fuentes

// === RENDERIZADO GRÁFICO ===
#include <SDL3/SDL.h>       // SDL3 para gráficos de alto rendimiento

// === LOGGING ===
#include <spdlog/spdlog.h>  // Sistema de logging moderno
#include <spdlog/sinks/stdout_color_sinks.h>  // Salida colorizada a consola

// === LIBRERÍAS ESTÁNDAR ===
#include <iostream>         // Para entrada/salida de consola