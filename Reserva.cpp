#include "Reserva.h"

#include <string>
#include <iostream>
using namespace std;
Reserva::Reserva(){
}
Reserva::Reserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, Habitacion* hab){
	this->codigo = codigo;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado =estado;
	this->habitacion= hab;
}
int Reserva::getCodigo(){
	return this->codigo;
}
DTFecha* Reserva::getCheckIn(){
	return this->checkIn;
}
DTFecha* Reserva::getCheckOut(){
	return this->checkOut;
}
EstadoReserva Reserva::getEstado(){
	return this->estado;
}
void Reserva::setCodigo(int codigo){
	this->codigo = codigo;
}
void Reserva::setCheckIn(DTFecha* checkIn){
	this->checkIn = checkIn;
}
void Reserva::setCheckOut(DTFecha* checkOut){
	this->checkOut = checkOut;
}
void Reserva::setEstado(EstadoReserva estado){
	this->estado = estado;
}
Habitacion *Reserva::getHabitacion(){
	return this->habitacion;
}
void Reserva::setHabitacion(Habitacion *habitacion){
	this->habitacion = habitacion;
}