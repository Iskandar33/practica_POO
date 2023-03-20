all: compiler
compiler: Sistema Propietario Huesped Hogar Evaluacion Reserva Main
	g++ -o papu Sistema.o Propietario.o Huesped.o Hogar.o Evaluacion.o Reserva.o main.o
Sistema: Sistema.cpp Sistema.h
	g++ -c Sistema.cpp
Propietario: Propietario.cpp Propietario.h
	g++ -c Propietario.cpp
Huesped: Huesped.cpp Huesped.h
	g++ -c Huesped.cpp
Hogar: Hogar.cpp Hogar.h
	g++ -c Hogar.cpp
Evaluacion: Evaluacion.cpp Evaluacion.h
	g++ -c Evaluacion.cpp
Reserva: Reserva.cpp Reserva.h
	g++ -c Reserva.cpp
Main: Main.cpp
	g++ -c Main.cpp