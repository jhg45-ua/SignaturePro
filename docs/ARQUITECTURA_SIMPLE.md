# 🏗️ Arquitectura Simplificada - SignaturePro

## 📂 Nueva Estructura de Directorios

```
src/
├── main.cpp                    # Punto de entrada
├── my_app.hpp/cpp             # Aplicación principal wxWidgets
│
├── ui/                        # 🎨 UI LAYER - Interfaces de usuario
│   ├── my_frame.hpp/cpp       # Ventana principal
│   ├── second_frame.hpp/cpp   # Segunda ventana
│   └── modal_dialog.hpp/cpp   # Diálogo modal
│
├── controllers/               # 🎮 CONTROLLER LAYER - Lógica de control
│   └── app_controller.hpp/cpp # Controlador principal de la aplicación
│
├── services/                  # ⚙️ SERVICE LAYER - Lógica de negocio
│   └── logging_service.hpp/cpp # Servicio de logging centralizado
│
└── core/                      # 🔧 CORE LAYER - Utilidades base
    ├── constants.hpp          # Constantes de la aplicación
    ├── theme.hpp              # Configuración de tema visual
    ├── logger.hpp/cpp         # Sistema de logging base
    └── (futuros archivos base)
```

## 🎯 Principios de la Arquitectura

### **1. Separación en Capas**
- **UI Layer**: Solo manejo de interfaz wxWidgets
- **Controller Layer**: Coordinación entre UI y servicios
- **Service Layer**: Lógica de negocio y operaciones
- **Core Layer**: Utilidades, constantes y funciones base

### **2. Flujo de Datos**
```
UI ↔ Controller ↔ Services ↔ Core
```

### **3. Responsabilidades**

#### 🎨 **UI Layer**
- Renderizado de interfaces
- Manejo de eventos de usuario
- Presentación de datos

#### 🎮 **Controller Layer**
- Coordinación entre capas
- Gestión del ciclo de vida
- Manejo de la navegación

#### ⚙️ **Service Layer**
- Lógica de negocio
- Operaciones con datos
- Servicios reutilizables

#### 🔧 **Core Layer**
- Constantes y configuración
- Utilidades compartidas
- Funciones base

## 🚀 Ventajas de esta Arquitectura

1. **Mantenibilidad**: Código organizado en capas claras
2. **Testabilidad**: Servicios y controladores fáciles de probar
3. **Escalabilidad**: Fácil agregar nuevos componentes
4. **Reutilización**: Servicios compartidos entre vistas
5. **Simplicidad**: Arquitectura fácil de entender y seguir

## 📋 Próximos Pasos

1. **Agregar más servicios** según necesidades
2. **Crear controladores específicos** para cada vista
3. **Implementar servicios de datos** (archivos, configuración)
4. **Agregar utilidades** en core según se requieran

## 🔧 Compilación

La aplicación se compila igual que antes:

```bash
# Configurar
cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release

# Compilar
cmake --build build --parallel

# Ejecutar
./build/bin/app
```
