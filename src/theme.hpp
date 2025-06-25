/**
 * TEMA Y ESTILOS VISUALES
 * 
 * Constantes para mantener un diseño visual consistente
 * en toda la aplicación wxWidgets.
 */

#pragma once

#include <wx/colour.h>
#include <wx/font.h>

namespace Theme {
    // === COLORES PRINCIPALES ===
    namespace Colors {
        // Colores de fondo - Tema Oscuro
        const wxColour BACKGROUND_PRIMARY(32, 37, 43);         // Fondo principal oscuro
        const wxColour BACKGROUND_SECONDARY(40, 44, 52);       // Fondo secundario
        const wxColour BACKGROUND_CARD(48, 54, 61);            // Fondo de tarjetas/campos
        const wxColour BACKGROUND_DARKER(24, 28, 33);          // Fondo más oscuro
        
        // Colores de texto - Tema Oscuro
        const wxColour TEXT_PRIMARY(248, 249, 250);            // Texto principal (blanco suave)
        const wxColour TEXT_SECONDARY(173, 181, 189);          // Texto secundario (gris claro)
        const wxColour TEXT_MUTED(134, 142, 150);              // Texto deshabilitado
        const wxColour TEXT_ACCENT(129, 140, 248);             // Texto de acento (azul claro)
        
        // Colores de botones - Tema Oscuro Moderno
        const wxColour BUTTON_SUCCESS(34, 197, 94);            // Verde brillante
        const wxColour BUTTON_SUCCESS_HOVER(22, 163, 74);      // Verde más oscuro para hover
        const wxColour BUTTON_DANGER(239, 68, 68);             // Rojo brillante
        const wxColour BUTTON_DANGER_HOVER(220, 38, 38);       // Rojo más oscuro para hover
        const wxColour BUTTON_PRIMARY(59, 130, 246);           // Azul brillante
        const wxColour BUTTON_PRIMARY_HOVER(37, 99, 235);      // Azul más oscuro para hover
        const wxColour BUTTON_WARNING(245, 158, 11);           // Amarillo/naranja
        const wxColour BUTTON_WARNING_HOVER(217, 119, 6);      // Naranja más oscuro para hover
        const wxColour BUTTON_INFO(14, 165, 233);              // Cyan brillante
        const wxColour BUTTON_INFO_HOVER(2, 132, 199);         // Cyan más oscuro para hover
        const wxColour BUTTON_SECONDARY(75, 85, 99);           // Gris oscuro
        const wxColour BUTTON_SECONDARY_HOVER(55, 65, 81);     // Gris más oscuro para hover
        
        // Colores de texto en botones
        const wxColour BUTTON_TEXT_LIGHT(255, 255, 255);       // Texto blanco
        const wxColour BUTTON_TEXT_DARK(17, 24, 39);           // Texto muy oscuro
        
        // Colores de acento - Tema Oscuro
        const wxColour ACCENT_PRIMARY(99, 102, 241);           // Púrpura-azul
        const wxColour ACCENT_SUCCESS(16, 185, 129);           // Verde esmeralda
        const wxColour ACCENT_WARNING(245, 158, 11);           // Ámbar
        const wxColour BORDER_COLOR(75, 85, 99);               // Bordes grises
        const wxColour BORDER_LIGHT(107, 114, 128);            // Bordes más claros
        
        // Colores adicionales para tema oscuro
        const wxColour HOVER_OVERLAY(255, 255, 255, 10);       // Overlay para hover
        const wxColour SELECTION_BG(59, 130, 246, 30);         // Fondo de selección
    }
    
    // === TAMAÑOS DE FUENTE ===
    namespace FontSizes {
        const int TITLE_LARGE = 24;        // Títulos principales
        const int TITLE_MEDIUM = 20;       // Títulos secundarios
        const int TITLE_SMALL = 16;        // Subtítulos
        const int BODY_LARGE = 14;         // Texto principal grande
        const int BODY_NORMAL = 12;        // Texto normal
        const int BODY_SMALL = 10;         // Texto pequeño
        const int BUTTON = 11;             // Texto de botones
        const int LABEL = 12;              // Etiquetas de formulario
    }
    
    // === ESPACIADO ===
    namespace Spacing {
        const int TINY = 5;               // Espaciado muy pequeño
        const int SMALL = 10;             // Espaciado pequeño
        const int MEDIUM = 15;            // Espaciado medio
        const int LARGE = 20;             // Espaciado grande
        const int XLARGE = 25;            // Espaciado muy grande
        const int XXLARGE = 30;           // Espaciado máximo
    }
    
    // === TAMAÑOS DE COMPONENTES ===
    namespace ComponentSizes {
        // Botones
        const wxSize BUTTON_NORMAL(115, 42);
        const wxSize BUTTON_LARGE(140, 45);
        const wxSize BUTTON_SMALL(90, 35);
        
        // Campos de entrada
        const wxSize INPUT_NORMAL(420, 38);
        const wxSize INPUT_LARGE(450, 42);
        const wxSize INPUT_SMALL(300, 35);
        
        // Ventanas
        const wxSize DIALOG_SMALL(400, 300);
        const wxSize DIALOG_MEDIUM(500, 400);
        const wxSize DIALOG_LARGE(600, 500);
        const wxSize WINDOW_MEDIUM(700, 500);
        const wxSize WINDOW_LARGE(800, 600);
    }
    
    // === FUNCIONES DE UTILIDAD ===
    namespace Utils {
        // Crear fuente con peso específico
        inline wxFont CreateFont(int size, wxFontWeight weight = wxFONTWEIGHT_NORMAL) {
            return wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight);
        }
        
        // Crear fuente bold
        inline wxFont CreateBoldFont(int size) {
            return CreateFont(size, wxFONTWEIGHT_BOLD);
        }
        
        // Aplicar estilo de botón mejorado sin fondos rectangulares marcados
        inline void ApplyButtonStyle(wxButton* button, const wxColour& bgColor, const wxColour& textColor, int fontSize = FontSizes::BUTTON) {
            if (button) {
                // Usar un color de fondo más sutil o transparente
                button->SetBackgroundColour(Colors::BACKGROUND_PRIMARY);
                button->SetForegroundColour(textColor);
                button->SetFont(CreateBoldFont(fontSize));
                
                // Aplicar estilos específicos por plataforma para mejor apariencia
                #ifdef __WXMSW__
                    // En Windows, usar estilo flat
                    button->SetWindowStyleFlag(button->GetWindowStyleFlag() | wxBORDER_NONE);
                #elif defined(__WXGTK__)
                    // En GTK, usar borde mínimo
                    button->SetWindowStyleFlag(button->GetWindowStyleFlag() | wxBORDER_SIMPLE);
                #elif defined(__WXMAC__)
                    // En macOS, usar estilo nativo
                    button->SetWindowStyleFlag(button->GetWindowStyleFlag() | wxBORDER_NONE);
                #endif
                
                // Forzar refresh para aplicar cambios
                button->Refresh();
            }
        }
        
        // Aplicar estilo de botón con borde sutil en lugar de fondo sólido
        inline void ApplySubtleButtonStyle(wxButton* button, const wxColour& accentColor, const wxColour& textColor, int fontSize = FontSizes::BUTTON) {
            if (button) {
                // Usar el fondo del panel como base
                button->SetBackgroundColour(Colors::BACKGROUND_PRIMARY);
                button->SetForegroundColour(accentColor);  // Color del texto como acento
                button->SetFont(CreateBoldFont(fontSize));
                
                // Aplicar bordes mínimos
                #ifdef __WXMSW__
                    button->SetWindowStyleFlag(wxBU_EXACTFIT | wxBORDER_NONE);
                #else
                    button->SetWindowStyleFlag(wxBORDER_SIMPLE);
                #endif
                
                button->Refresh();
            }
        }
        
        // Aplicar estilo de botón con efecto elevado
        inline void ApplyElevatedButtonStyle(wxButton* button, const wxColour& bgColor, const wxColour& textColor, int fontSize = FontSizes::BUTTON) {
            if (button) {
                ApplyButtonStyle(button, bgColor, textColor, fontSize);
                
                // Aplicar un color ligeramente más claro para simular elevación
                wxColour elevatedBg = wxColour(
                    std::min(255, (int)(bgColor.Red() * 1.1)), 
                    std::min(255, (int)(bgColor.Green() * 1.1)), 
                    std::min(255, (int)(bgColor.Blue() * 1.1))
                );
                button->SetBackgroundColour(elevatedBg);
            }
        }
        
        // Aplicar estilo de etiqueta
        inline void ApplyLabelStyle(wxStaticText* label, const wxColour& textColor = Colors::TEXT_SECONDARY, int fontSize = FontSizes::LABEL, bool bold = true) {
            if (label) {
                label->SetForegroundColour(textColor);
                label->SetFont(bold ? CreateBoldFont(fontSize) : CreateFont(fontSize));
            }
        }
        
        // Aplicar estilo de título
        inline void ApplyTitleStyle(wxStaticText* title, int fontSize = FontSizes::TITLE_MEDIUM, const wxColour& textColor = Colors::TEXT_PRIMARY) {
            if (title) {
                title->SetForegroundColour(textColor);
                title->SetFont(CreateBoldFont(fontSize));
            }
        }
        
        // Aplicar estilo de campo de entrada
        inline void ApplyInputStyle(wxTextCtrl* input, int fontSize = FontSizes::BODY_NORMAL) {
            if (input) {
                input->SetBackgroundColour(Colors::BACKGROUND_CARD);
                input->SetFont(CreateFont(fontSize));
            }
        }
        
        // Aplicar estilo de selector
        inline void ApplyChoiceStyle(wxChoice* choice, int fontSize = FontSizes::BODY_NORMAL) {
            if (choice) {
                choice->SetBackgroundColour(Colors::BACKGROUND_CARD);
                choice->SetForegroundColour(Colors::TEXT_PRIMARY);
                choice->SetFont(CreateFont(fontSize));
            }
        }
        
        // Aplicar estilo de panel principal
        inline void ApplyPanelStyle(wxPanel* panel) {
            if (panel) {
                panel->SetBackgroundColour(Colors::BACKGROUND_PRIMARY);
            }
        }
        
        // Aplicar estilo de checkbox para tema oscuro
        inline void ApplyCheckboxStyle(wxCheckBox* checkbox, int fontSize = FontSizes::BODY_NORMAL) {
            if (checkbox) {
                checkbox->SetForegroundColour(Colors::TEXT_SECONDARY);
                checkbox->SetFont(CreateFont(fontSize));
                checkbox->SetBackgroundColour(Colors::BACKGROUND_PRIMARY);
            }
        }
        
        // Aplicar estilo de entrada con mejor contraste para tema oscuro
        inline void ApplyInputStyleDark(wxTextCtrl* input, int fontSize = FontSizes::BODY_NORMAL) {
            if (input) {
                input->SetBackgroundColour(Colors::BACKGROUND_CARD);
                input->SetForegroundColour(Colors::TEXT_PRIMARY);
                input->SetFont(CreateFont(fontSize));
            }
        }
        
        // Aplicar estilo completo de ventana oscura
        inline void ApplyDarkWindowStyle(wxWindow* window) {
            if (window) {
                window->SetBackgroundColour(Colors::BACKGROUND_PRIMARY);
                window->SetForegroundColour(Colors::TEXT_PRIMARY);
            }
        }
        
        // === FUNCIONES ESPECIALIZADAS PARA BOTONES SUTILES ===
        
        // Aplicar estilo de botón con tipo específico (sutil, sin rectangulos marcados)
        inline void ApplyPrimaryButtonStyle(wxButton* button) {
            ApplySubtleButtonStyle(button, Colors::BUTTON_PRIMARY, Colors::BUTTON_PRIMARY, FontSizes::BUTTON);
        }
        
        inline void ApplySuccessButtonStyle(wxButton* button) {
            ApplySubtleButtonStyle(button, Colors::BUTTON_SUCCESS, Colors::BUTTON_SUCCESS, FontSizes::BUTTON);
        }
        
        inline void ApplyDangerButtonStyle(wxButton* button) {
            ApplySubtleButtonStyle(button, Colors::BUTTON_DANGER, Colors::BUTTON_DANGER, FontSizes::BUTTON);
        }
        
        inline void ApplyWarningButtonStyle(wxButton* button) {
            ApplySubtleButtonStyle(button, Colors::BUTTON_WARNING, Colors::BUTTON_WARNING, FontSizes::BUTTON);
        }
        
        inline void ApplyInfoButtonStyle(wxButton* button) {
            ApplySubtleButtonStyle(button, Colors::BUTTON_INFO, Colors::BUTTON_INFO, FontSizes::BUTTON);
        }
        
        inline void ApplySecondaryButtonStyle(wxButton* button) {
            ApplySubtleButtonStyle(button, Colors::TEXT_SECONDARY, Colors::TEXT_SECONDARY, FontSizes::BUTTON);
        }
        
        // Aplicar estilo de botón con borde sutil
        inline void ApplyOutlinedButtonStyle(wxButton* button, const wxColour& borderColor, const wxColour& textColor) {
            if (button) {
                button->SetBackgroundColour(Colors::BACKGROUND_SECONDARY);
                button->SetForegroundColour(textColor);
                button->SetFont(CreateBoldFont(FontSizes::BUTTON));
                
                // En algunos sistemas, podemos aplicar un borde
                #ifdef __WXGTK__
                    // En GTK, podemos usar un estilo de borde
                    button->SetWindowStyleFlag(button->GetWindowStyleFlag() | wxBORDER_SIMPLE);
                #endif
                
                button->Refresh();
            }
        }
        
        // === FUNCIÓN AVANZADA PARA BOTONES CON MEJOR APARIENCIA ===
        
        // Aplicar estilo de botón con gradiente sutil y mejor contraste
        inline void ApplyPremiumButtonStyle(wxButton* button, const wxColour& baseColor, const wxColour& textColor) {
            if (button) {
                // Crear un color ligeramente más brillante para el efecto "elevado"
                wxColour brightColor = wxColour(
                    std::min(255, baseColor.Red() + 15),
                    std::min(255, baseColor.Green() + 15), 
                    std::min(255, baseColor.Blue() + 15)
                );
                
                button->SetBackgroundColour(brightColor);
                button->SetForegroundColour(textColor);
                button->SetFont(CreateBoldFont(FontSizes::BUTTON));
                
                // Aplicar padding interno si está disponible
                #ifdef __WXMSW__
                    button->SetWindowStyleFlag(button->GetWindowStyleFlag() | wxBU_EXACTFIT);
                #endif
                
                // Forzar actualización
                button->Refresh();
                button->Update();
            }
        }
        
        // Crear un botón con estilo completo en una sola función
        inline wxButton* CreateStyledButton(wxWindow* parent, int id, const wxString& label, 
                                          const wxColour& bgColor, const wxColour& textColor,
                                          const wxPoint& pos = wxDefaultPosition,
                                          const wxSize& size = ComponentSizes::BUTTON_NORMAL) {
            wxButton* button = new wxButton(parent, id, label, pos, size);
            ApplyPremiumButtonStyle(button, bgColor, textColor);
            return button;
        }
        
        // === BOTONES PLANOS MODERNOS (SIN FONDOS RECTANGULARES) ===
        
        // Aplicar estilo de botón plano moderno
        inline void ApplyFlatButtonStyle(wxButton* button, const wxColour& textColor, int fontSize = FontSizes::BUTTON) {
            if (button) {
                // Fondo transparente/igual al panel
                button->SetBackgroundColour(Colors::BACKGROUND_PRIMARY);
                button->SetForegroundColour(textColor);
                button->SetFont(CreateBoldFont(fontSize));
                
                // Remover bordes y efectos 3D
                #ifdef __WXMSW__
                    button->SetWindowStyleFlag(wxBU_EXACTFIT | wxBORDER_NONE);
                #elif defined(__WXGTK__)
                    button->SetWindowStyleFlag(wxBORDER_NONE);
                #elif defined(__WXMAC__)
                    button->SetWindowStyleFlag(wxBORDER_NONE);
                #endif
                
                button->Refresh();
            }
        }
        
        // Funciones especializadas para botones planos
        inline void ApplyFlatPrimaryButton(wxButton* button) {
            ApplyFlatButtonStyle(button, Colors::BUTTON_PRIMARY, FontSizes::BUTTON);
        }
        
        inline void ApplyFlatSuccessButton(wxButton* button) {
            ApplyFlatButtonStyle(button, Colors::BUTTON_SUCCESS, FontSizes::BUTTON);
        }
        
        inline void ApplyFlatDangerButton(wxButton* button) {
            ApplyFlatButtonStyle(button, Colors::BUTTON_DANGER, FontSizes::BUTTON);
        }
        
        inline void ApplyFlatWarningButton(wxButton* button) {
            ApplyFlatButtonStyle(button, Colors::BUTTON_WARNING, FontSizes::BUTTON);
        }
        
        inline void ApplyFlatInfoButton(wxButton* button) {
            ApplyFlatButtonStyle(button, Colors::BUTTON_INFO, FontSizes::BUTTON);
        }
        
        inline void ApplyFlatSecondaryButton(wxButton* button) {
            ApplyFlatButtonStyle(button, Colors::TEXT_SECONDARY, FontSizes::BUTTON);
        }
    }
}
