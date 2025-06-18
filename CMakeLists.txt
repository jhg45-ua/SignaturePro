cmake_minimum_required(VERSION 3.20)
project(wxWidgets_SDL3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SDL3 framework on macOS
find_library(SDL3_LIBRARY SDL3 REQUIRED)

# Find spdlog (installed via Homebrew)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SPDLOG REQUIRED spdlog)

# wxWidgets + SDL3 applications
find_package(wxWidgets REQUIRED COMPONENTS core base)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
    
    # Create wxWidgets simple demo
    add_executable(wxWidgets_Simple_Demo
        src/wxwidgets_simple.cpp
    )
    
    # Include directories for wxWidgets apps
    target_include_directories(wxWidgets_Simple_Demo PRIVATE 
        ${wxWidgets_INCLUDE_DIRS}
        ${SPDLOG_INCLUDE_DIRS}
        /Library/Frameworks/SDL3.framework/Headers
        /System/Library/Frameworks/SDL3.framework/Headers
    )
    
    # Link libraries for wxWidgets apps
    target_link_libraries(wxWidgets_Simple_Demo 
        ${wxWidgets_LIBRARIES}
        ${SDL3_LIBRARY}
        ${SPDLOG_LIBRARIES}
    )
    
    # Set output directory for wxWidgets apps
    set_target_properties(wxWidgets_Simple_Demo PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
    
    # Set compiler flags for wxWidgets
    target_compile_definitions(wxWidgets_Simple_Demo PRIVATE ${wxWidgets_DEFINITIONS})
    target_compile_options(wxWidgets_Simple_Demo PRIVATE ${wxWidgets_CXX_FLAGS})
    
    message(STATUS "wxWidgets found - wxWidgets applications will be built")
else()
    message(WARNING "wxWidgets not found - wxWidgets examples will not be built")
endif()
