#include "Reserva.h"

#include <string>
#include <iostream>
using namespace std;

Reserva::Reserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, Habitacion* hab){
	this->codigo = codigo;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado =estado;
	this->habitacion= hab;
}