# 🎨 GUÍA RÁPIDA - TEMA OSCURO

## 🚀 Inicio Rápido

```cpp
#include "theme.hpp"  // Incluir siempre

// Aplicar tema a ventana
Theme::Utils::ApplyPanelStyle(panel);

// Botones modernos (recomendado)
Theme::Utils::ApplyFlatPrimaryButton(button);
Theme::Utils::ApplyFlatSuccessButton(button);
Theme::Utils::ApplyFlatDangerButton(button);
```

## 🔧 Funciones Principales

### **Botones Planos (Sin Fondos Rectangulares)**
| Función | Color | Uso |
|---------|-------|-----|
| `ApplyFlatPrimaryButton` | Azul | Acciones principales |
| `ApplyFlatSuccessButton` | Verde | Aceptar, Guardar |
| `ApplyFlatDangerButton` | Rojo | Cancelar, Eliminar |
| `ApplyFlatWarningButton` | Ámbar | Limpiar, Reiniciar |
| `ApplyFlatInfoButton` | Cyan | Información |
| `ApplyFlatSecondaryButton` | Gris | Acciones secundarias |

### **Otros Elementos**
```cpp
// Títulos y texto
Theme::Utils::ApplyTitleStyle(titulo);
Theme::Utils::ApplyLabelStyle(etiqueta);

// Campos de entrada
Theme::Utils::ApplyInputStyleDark(input);

// Paneles
Theme::Utils::ApplyPanelStyle(panel);
```

## 📐 Espaciado

```cpp
// Usar constantes en lugar de números
sizer->Add(componente, 0, wxALL, Theme::Spacing::MEDIUM);  // 15px
sizer->Add(componente, 0, wxALL, Theme::Spacing::LARGE);   // 20px
sizer->Add(componente, 0, wxALL, Theme::Spacing::XLARGE);  // 25px
```

**Constantes disponibles:**
- `TINY` = 5px, `SMALL` = 10px, `MEDIUM` = 15px
- `LARGE` = 20px, `XLARGE` = 25px, `XXLARGE` = 30px

## 🏗️ Plantilla Nueva Ventana

```cpp
#include "theme.hpp"

void MiVentana::InitializeComponents() {
    // 1. Panel principal
    main_panel_ = new wxPanel(this);
    Theme::Utils::ApplyPanelStyle(main_panel_);
    
    // 2. Título
    auto titulo = new wxStaticText(main_panel_, wxID_ANY, "Mi Título");
    Theme::Utils::ApplyTitleStyle(titulo);
    
    // 3. Botón
    auto boton = new wxButton(main_panel_, wxID_ANY, "Mi Botón");
    Theme::Utils::ApplyFlatPrimaryButton(boton);
    
    // 4. Layout
    auto sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(titulo, 0, wxALL | wxCENTER, Theme::Spacing::LARGE);
    sizer->Add(boton, 0, wxALL | wxCENTER, Theme::Spacing::MEDIUM);
    main_panel_->SetSizer(sizer);
    
    // 5. Configuración final
    SetSize(600, 400);
    Center();
}
```

## 🎨 Colores Principales

```cpp
// Fondos
Theme::Colors::BACKGROUND_PRIMARY    // Fondo principal (32, 37, 43)
Theme::Colors::BACKGROUND_SECONDARY  // Fondo secundario (40, 44, 52)
Theme::Colors::BACKGROUND_CARD       // Fondo de campos (48, 54, 61)

// Texto
Theme::Colors::TEXT_PRIMARY          // Texto principal (blanco)
Theme::Colors::TEXT_SECONDARY        // Texto secundario (gris claro)
Theme::Colors::TEXT_MUTED           // Texto deshabilitado

// Botones (solo para referencia)
Theme::Colors::BUTTON_PRIMARY        // Azul (59, 130, 246)
Theme::Colors::BUTTON_SUCCESS        // Verde (34, 197, 94)
Theme::Colors::BUTTON_DANGER         // Rojo (239, 68, 68)
```

## ✅ Lista de Verificación

### **Para Nueva Ventana:**
- [ ] Incluir `#include "theme.hpp"`
- [ ] Aplicar `ApplyPanelStyle()` al panel principal
- [ ] Usar botones planos: `ApplyFlat*Button()`
- [ ] Aplicar estilos a títulos: `ApplyTitleStyle()`
- [ ] Usar constantes de espaciado del tema
- [ ] Aplicar estilo a campos: `ApplyInputStyleDark()`

### **Mejores Prácticas:**
- [ ] Un tipo de botón por función (azul=principal, verde=guardar, rojo=cancelar)
- [ ] Espaciado consistente con `Theme::Spacing::`
- [ ] Verificar contraste de colores
- [ ] Probar en diferentes tamaños de ventana

## 🔄 Cambios Globales

Para cambiar el estilo de todos los botones globalmente, editar solo `src/theme.hpp`:

```cpp
// Cambiar todas las funciones ApplyFlat*Button para usar otro estilo
inline void ApplyFlatPrimaryButton(wxButton* button) {
    // Cambiar implementación aquí afecta toda la aplicación
    ApplyFlatButtonStyle(button, Colors::BUTTON_PRIMARY);
}
```

¡Con esto tendrás una interfaz moderna y consistente! 🌟
