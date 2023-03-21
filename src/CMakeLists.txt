file(GLOB_RECURSE SOURCES Sistema.cpp Propietario.cpp Huesped.cpp Hogar.cpp Evaluacion.cpp Reserva.cpp Sistema.h Propietario.h Huesped.h Hogar.h Evaluacion.h Reserva.h)  #Todas las fuentes sin el Main

set(BINARY ${CMAKE_PROJECT_NAME})  # El nombre va a a estar en el CMake principal

# Definicion variable sources
set(SOURCES ${SOURCES})

# STATIC libraries are archives of object files for use when linking other targets
#add_library(${CMAKE_PROJECT_NAME}_lib Sistema.h Propietario.h Huesped.h Hogar.h Evaluacion.h Reserva.h)  #construye una libraria que tiene los test que vamos a ejecutar

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_lib)

# Instrucción que define el ejecutable a partir de las fuentes definidas
add_executable(${BINARY}_exe ${SOURCES} Main.cpp)  # Las fuentes mas el archivo main
