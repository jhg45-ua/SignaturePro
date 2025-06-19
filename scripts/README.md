# 🛠️ Scripts de Automatización - Proyecto wxWidgets

## 📋 **Scripts Disponibles**

Esta carpeta contiene scripts de automatización para el proyecto wxWidgets, diseñados para funcionar correctamente con zsh y evitar problemas con caracteres especiales.

### 🔨 **build.sh** - Compilación
```bash
./scripts/build.sh
```

**Funcionalidad**:
- ✅ Compila la aplicación usando CMake y make
- ✅ Compilación paralela para mejor rendimiento  
- ✅ Información detallada del progreso
- ✅ Verificación de archivos generados
- ✅ Mensajes de estado claros

**Salida típica**:
```
🔨 Compilando aplicación wxWidgets con make...
=============================================
[ 80%] Building CXX object...
[100%] Linking CXX executable...
✅ Compilación exitosa con make!
📁 Archivos generados: ...
```

### 🚀 **run.sh** - Ejecución
```bash
./scripts/run.sh
```

**Funcionalidad**:
- ✅ Verifica existencia del ejecutable
- ✅ Ejecuta la aplicación wxWidgets
- ✅ Mensajes informativos
- ✅ Manejo de errores

**Salida típica**:
```
🚀 Ejecutando aplicación wxWidgets...
====================================
✅ Ejecutable encontrado
📱 Iniciando aplicación...
```

### 📊 **project-info.sh** - Información del Proyecto
```bash
./scripts/project-info.sh
```

**Funcionalidad**:
- ✅ Cuenta archivos fuente
- ✅ Calcula líneas de código
- ✅ Muestra tamaño del ejecutable
- ✅ Fecha de última compilación

**Salida típica**:
```
📊 Información del Proyecto wxWidgets
=================================
📁 Archivos fuente: 9
📏 Líneas de código: 157 total
🔧 Tamaño del ejecutable: 1.5M
⏱️  Última compilación: Jun 19 13:07:23 2025
```

## 🔧 **Integración con VS Code**

Estos scripts están integrados con las tareas de VS Code en `.vscode/tasks.json`:

- **build** → `./scripts/build.sh`
- **run** → `./scripts/run.sh` 
- **project-info** → `./scripts/project-info.sh`

## ⚡ **Ventajas de los Scripts**

### 🛡️ **Compatibilidad con zsh**
- Evita problemas con caracteres especiales
- Manejo correcto de comillas y espacios
- Funciona en todas las configuraciones de terminal

### 📱 **Mejor UX**  
- Mensajes informativos con emojis
- Información detallada del progreso
- Manejo de errores claro

### 🔧 **Mantenibilidad**
- Fácil modificación sin tocar tasks.json
- Reutilizables desde línea de comandos
- Documentación integrada

## 🔒 **Permisos**

Los scripts tienen permisos de ejecución configurados:
```bash
chmod +x scripts/*.sh
```

## 📚 **Uso Manual**

También puedes ejecutar los scripts directamente:

```bash
# Compilar
./scripts/build.sh

# Ejecutar aplicación  
./scripts/run.sh

# Ver información del proyecto
./scripts/project-info.sh
```

---

**🎯 Scripts optimizados para desarrollo eficiente - Junio 2025**
