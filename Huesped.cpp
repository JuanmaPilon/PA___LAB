#include "Huesped.h"

Huesped::Huesped(){
}
Huesped::Huesped(string email, string nombre, string password, bool esFinger):Usuario(email, nombre, password){
	this->esFinger=esFinger;
}
bool Huesped::getEsFinger(){
    return this->esFinger;
}
void Huesped::setEsFinger(bool esFinger){
    this->esFinger = esFinger;
}
Huesped::~Huesped(){ 
}