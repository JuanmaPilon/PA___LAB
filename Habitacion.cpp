#include "Habitacion.h"

Habitacion::Habitacion(){
  this->numero = 0;
  this->capacidad = 0;
  this->precio = 0;
}

Habitacion::Habitacion(int numero, float precio, int capacidad){
  this->numero = numero;
  this->capacidad = capacidad;
  this->precio = precio;
}

int Habitacion::getNumero(){
  return this->numero;
}

float Habitacion::getPrecio(){
  return this->precio;
}

int Habitacion::getCapacidad(){
  return this->capacidad;
}

Hostal* Habitacion::getHostal(){
  return this->hostalHabitacion;
}

void Habitacion::setNumero(int numero){
  this->numero = numero;
}

void Habitacion::setPrecio(float precio){
  this->precio = precio;
}

void Habitacion::setCapacidad(int capacidad){
  this->capacidad = capacidad;
}

void Habitacion::setHostalHabitacion(Hostal *hos){
  this->hostalHabitacion = hos;
}
