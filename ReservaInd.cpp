#include "Reserva.h"
#include "ReservaInd.h"
#include "Habitacion.h"
#include "Huesped.h"
#include <string>
#include <iostream>
using namespace std;

ReservaIndividual::ReservaIndividual(){
}


ReservaIndividual::ReservaIndividual(int Codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva Estado, Huesped* huesped, Habitacion* habitacion): Reserva(codigo, checkIn, checkOut, estado, habitacion){
    this->huesped= huesped;
}

float ReservaIndividual::calcularCosto()
{
  // Falta el codigo
  return 0;
}


void ReservaIndividual::borrarReserva(){
  this->huesped=NULL;
  Reserva::setHabitacion(NULL);
  delete(this->getCheckIn());
  delete(this->getCheckOut());
}


// string reservaIndividual::tipoReserva() { return "Individual"; }

// reservaIndividual::~reservaIndividual() {}

// huesped *reservaIndividual::getHuesped()
// {
//   return this->hues;
// }
// void reservaIndividual::setHuesped(huesped *hues)
// {
//   this->hues = hues;
// }
