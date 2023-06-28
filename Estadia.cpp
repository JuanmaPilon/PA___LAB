#include "Estadia.h"
Estadia::Estadia(){

}
Estadia::Estadia(int codigo, DTFecha* checkIn, DTFecha* checkOut, Reserva* reservaEstadia, Huesped* huespedEstadia){
    this->codigo=codigo;
    this->checkIn =checkIn;
    this->checkOut=checkOut;
    this->reservaEstadia = reservaEstadia;
    this->huespedEstadia = huespedEstadia;
}
Estadia:: ~Estadia(){
    delete this->checkIn;
    delete this->checkOut;
}
string Estadia::getPromo(){
    return this->promo;
}
Reserva* Estadia::getReserva(){
    return this->reservaEstadia;
}
Huesped* Estadia::getHuesped(){
    return this->huespedEstadia;
}
DTFecha* Estadia::getCheckIn(){
    return this->checkIn;
}
DTFecha* Estadia::getCheckOut(){
    return this->checkOut;
}
void Estadia::setFechaCheckIn(DTFecha* checkIn){
    this->checkIn=checkIn;
}
void Estadia::setFechaCheckOut(DTFecha* checkOUT){
    this->checkOut=checkOUT;
}

void Estadia::setPromoCode(string codigo){
    this->promo=codigo;
}
bool Estadia::estaFinalizada(){
    return (this->checkOut->getAnio() == 0); //Si el anio es 0, retorna false, en otro caso, retorna true;
}
