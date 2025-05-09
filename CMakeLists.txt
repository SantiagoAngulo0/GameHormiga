cmake_minimum_required(VERSION 3.20)
project(GameHormiga)

set(CMAKE_CXX_STANDARD 17)

# 1. Configuración de rutas (¡usa tu ruta exacta!)
set(SFML_PATH "C:/Users/santi/Downloads/librariesSFML/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1")
set(CMAKE_PREFIX_PATH "${SFML_PATH}")

# 2. Buscar SFML
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

# 3. Primero crea el ejecutable
add_executable(GameHormiga
        main.cpp
        Juego.cpp
        Ray.cpp

)

# 4. Luego configura los includes (¡AHORA SÍ!)
target_include_directories(GameHormiga PRIVATE
        "${SFML_PATH}/include"
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# 5. Vincula las librerías
target_link_libraries(GameHormiga
        sfml-graphics
        sfml-window
        sfml-system
)

# 6. Copia DLLs automáticamente (Solo Windows)
if(WIN32)
    add_custom_command(TARGET GameHormiga POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${SFML_PATH}/bin/"
            $<TARGET_FILE_DIR:GameHormiga>)
endif()