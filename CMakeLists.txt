cmake_minimum_required(VERSION 3.24)
project(practica_POO)

include_directories(lib)
include_directories(src)
include_directories(test)

add_subdirectory(lib/googleTest)
add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_CXX_STANDARD 17)

#add_executable(practica_POO src/Sistema.cpp src/Propietario.cpp src/Huesped.cpp src/Hogar.cpp src/Evaluacion.cpp src/Reserva.cpp src/Main.cpp)