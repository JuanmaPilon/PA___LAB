#include "DTEmpleado.h"

DTEmpleado::DTEmpleado(string email, string nombre, string password, tipoCargo cargo, Hostal *nomHostal){
    this->email=email;
    this->nombre=nombre;
    this->password=password;
    this->cargo=cargo;
    this->hostalTrabaja=nomHostal;
}

string DTEmpleado::getEmail(){
    return this->email;
}
string DTEmpleado::getNombre(){
    return this->nombre;
}
tipoCargo DTEmpleado::getCargo(){
    return this->cargo;
} 
Hostal* DTEmpleado::getHostalTrabaja(){
    return this->hostalTrabaja;
}
void DTEmpleado::setHostalTrabaja(Hostal *hostalTrabaja){
    this->hostalTrabaja=hostalTrabaja;
}

DTEmpleado::~DTEmpleado(){}