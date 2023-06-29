#include "Reserva.h"
#include "ReservaGrp.h"
#include <string>
#include <iostream>
using namespace std;

ReservaGrupal::ReservaGrupal(int Codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, map<string,Huesped*> huespedes, Habitacion *habitacion):Reserva(Codigo,checkIn,checkOut,estado,habitacion){
    this->coleccionHuespedGrupal=huespedes;
}

float ReservaGrupal::calcularCosto(){
    //falta el codigo
    return 0;
}

string ReservaGrupal::tipoReserva() { return "Grupal"; };

map<string, Huesped*> ReservaGrupal::getHuespedes(){
    return this->coleccionHuespedGrupal;
}
ReservaGrupal::~ReservaGrupal(){
}