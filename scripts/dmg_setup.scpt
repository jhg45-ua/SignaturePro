-- Script AppleScript para configurar la apariencia del DMG
-- Este script se ejecuta cuando CPack crea el DMG

tell application "Finder"
    tell disk "SignaturePro Installer"
        open
        
        -- Configurar vista de iconos
        set current view of container window to icon view
        
        -- Configurar opciones de vista
        set toolbar visible of container window to false
        set statusbar visible of container window to false
        
        -- Configurar tamaño de ventana
        set the bounds of container window to {400, 100, 900, 400}
        
        -- Configurar vista de iconos
        set icon size of the icon view options of container window to 72
        set arrangement of the icon view options of container window to not arranged
        
        -- Posicionar iconos
        set position of item "SignaturePro.app" of container window to {150, 150}
        set position of item "Applications" of container window to {350, 150}
        
        -- Configurar etiquetas de iconos
        set label index of item "SignaturePro.app" of container window to 6
        
        close
        open
        
        -- Actualizar vista
        update without registering applications
        
        delay 2
    end tell
end tell
