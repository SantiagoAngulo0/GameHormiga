cmake_minimum_required(VERSION 3.30)
project(GameHormiga)

set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Users/s4m976/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(GameHormiga main.cpp
        Juego.h
        Juego.cpp
        Ray.cpp
        Ray.h
        PuertaEscenario.cpp
        PuertaEscenario.h
)
target_link_libraries(GameHormiga sfml-graphics sfml-audio)
