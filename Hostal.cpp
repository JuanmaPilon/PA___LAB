#include "Hostal.h"

Hostal::~Hostal(){
}
Hostal::Hostal(string nombre, string direccion, string telefono){
  this->nombre = nombre;
  this->direccion = direccion;
  this->telefono = telefono;
}
map<int, Habitacion *> Hostal::getColeccionHabitaciones(){
  return this->coleccionHabitaciones;
}
//map<string, Estadia *> Hostal::getColeccionEstadia(){
//  return this->coleccionEstadia;
//}
string Hostal::getNombre(){
  return this->nombre;
}
string Hostal::getDireccion(){
  return this->direccion;
}
string Hostal::getTelefono(){
  return this->telefono;
}
Habitacion* Hostal::getHabitacion(int num){
  return (this->coleccionHabitaciones.find(num))->second;
}
//Estadia* Hostal::getEstadia(string cod){
//  return (this->coleccionEstadia.find(cod))->second;
//}
void Hostal::setNombre(string nombre){
  this->nombre = nombre;
}
void Hostal::setDireccion(string direccion){
  this->direccion = direccion;
}
void Hostal::setTelefono(string telefono){
  this->telefono = telefono;
}
void Hostal::agregarHabitacion(int num, Habitacion* hab){
    this->coleccionHabitaciones.insert({num, hab});
}
//void Hostal::agregarEstadia(string cod, Estadia* e){
//  this->coleccionEstadia.insert({cod, e });
//}
//void Hostal::eliminarEstadia(string cod){
//  this->coleccionEstadia.erase(cod);
//}
Hostal:: ~Hostal(){
}

