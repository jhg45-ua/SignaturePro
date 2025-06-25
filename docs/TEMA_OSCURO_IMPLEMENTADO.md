# 🌙 TEMA OSCURO - APLICACIÓN WXWIDGETS

## ✅ Resumen

Aplicación wxWidgets con **tema oscuro moderno** implementado en todas las ventanas.

## 🎨 Colores Principales

- **Fondo**: Gris oscuro `(32, 37, 43)`
- **Texto**: Blanco/gris claro para máximo contraste
- **Botones**: Colores vibrantes (azul, verde, rojo, ámbar)

## 🏗️ Sistema de Tema

**Archivo**: `src/theme.hpp`
- Colores centralizados
- Funciones para aplicar estilos automáticamente
- Consistencia en toda la aplicación

## 📱 Ventanas Incluidas

1. **Ventana Principal** - Navegación con 4 botones
2. **Segunda Ventana** - Página independiente  
3. **Diálogo Modal** - Formulario con validación

## 🔧 Botones Modernos

**Estilo actual**: Botones planos sin fondos rectangulares
- Solo texto colorido sobre fondo transparente
- Aspecto limpio y moderno
- Mejor integración visual
- Funciones especializadas: `ApplyFlatPrimaryButton()`, `ApplyFlatSuccessButton()`, etc.

## 🎯 Beneficios

- ✅ Menos fatiga visual
- ✅ Apariencia profesional moderna
- ✅ Fácil mantenimiento (código centralizado)
- ✅ Compatible con todas las plataformas
- ✅ Botones sin fondos rectangulares distractores

## 🚀 Cómo Usar

```cpp
#include "theme.hpp"

// Aplicar tema a ventana
Theme::Utils::ApplyPanelStyle(panel);

// Botones planos modernos
Theme::Utils::ApplyFlatPrimaryButton(button);
Theme::Utils::ApplyFlatSuccessButton(button);
Theme::Utils::ApplyFlatDangerButton(button);
```
