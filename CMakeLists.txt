cmake_minimum_required(VERSION 3.16)
project(TrabajoPractico)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TrabajoPractico
        Menu.cpp
        Peliculas.cpp
        archivo.cpp
        main.cpp
        )
