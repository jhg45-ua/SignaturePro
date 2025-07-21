# 🔧 Solución de Problemas Comunes

## Problemas de Configuración

### IntelliSense no funciona

**Síntomas:**
- Errores de inclusión de archivos
- Macros no reconocidas
- Funciones de wxWidgets no encontradas

**Solución:**
1. Regenerar `compile_commands.json`:
   ```bash
   cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
   ```

2. Verificar rutas en `c_cpp_properties.json`:
   - Rutas de wxWidgets (verificar con `wx-config --cppflags`)
   - Rutas de spdlog (`/opt/homebrew/Cellar/spdlog/*/include`)

### Errores de Compilación

**Error: spdlog not found**
```bash
# macOS (Homebrew)
brew install spdlog

# Ubuntu/Debian
sudo apt install libspdlog-dev

# Windows (vcpkg)
vcpkg install spdlog
```

**Error: wxWidgets not found**
```bash
# macOS (Homebrew)
brew install wxwidgets

# Ubuntu/Debian
sudo apt install libwxgtk3.2-dev

# Windows
# Descargar desde https://www.wxwidgets.org/downloads/
```

### Problemas de Ejecución

**Error: Biblioteca no encontrada en runtime**
```bash
# macOS - Verificar rutas de bibliotecas
otool -L build/bin/app

# Linux - Verificar rutas
ldd build/bin/app

# Configurar DYLD_LIBRARY_PATH (macOS) o LD_LIBRARY_PATH (Linux) si es necesario
```

## Problemas de Desarrollo

### Tema no se aplica correctamente

**Verificar:**
1. Llamadas a `ApplyDarkTheme()` en todos los componentes
2. Orden de aplicación (después de crear el widget)
3. Refresh de la ventana después de aplicar tema

### Logging no funciona

**Verificar:**
1. Inicialización del logger en `MyApp::OnInit()`
2. Nivel de log configurado correctamente
3. Permisos de escritura en directorio de logs

### Problemas de Distribución macOS

**Aplicación no se ejecuta después de crear .app**

1. Verificar permisos:
   ```bash
   chmod +x build/bin/SignaturePro.app/Contents/MacOS/SignaturePro
   ```

2. Verificar Info.plist:
   ```bash
   plutil -lint build/bin/SignaturePro.app/Contents/Info.plist
   ```

3. Verificar firmas (si es necesario):
   ```bash
   codesign -s "Developer ID Application" build/bin/SignaturePro.app
   ```

## Configuración de Desarrollo

### VS Code no reconoce archivos CMake

**Instalar extensiones recomendadas:**
- C/C++ Extension Pack
- CMake Tools
- CMake Language Support

### Debugging no funciona

**Verificar configuración en `.vscode/launch.json`:**
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug App",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/bin/app",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "build"
        }
    ]
}
```

## Recursos Útiles

### Comandos de Diagnóstico

```bash
# Verificar versiones
cmake --version
wx-config --version
pkg-config --modversion spdlog

# Verificar configuración wxWidgets
wx-config --cppflags
wx-config --libs

# Información del sistema (macOS)
system_profiler SPDeveloperToolsDataType

# Verificar dependencias
./scripts/project-info.sh
```

### Enlaces de Referencia

- [wxWidgets Documentation](https://docs.wxwidgets.org/)
- [spdlog GitHub](https://github.com/gabime/spdlog)
- [CMake Documentation](https://cmake.org/cmake/help/latest/)
- [VS Code C++ Documentation](https://code.visualstudio.com/docs/languages/cpp)
