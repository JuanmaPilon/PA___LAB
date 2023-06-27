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
  // Falta hacer calcular costo
  return 0;
}


void ReservaIndividual::borrarReserva(){  // no va?
  this->huesped=NULL;
  Reserva::setHabitacion(NULL);
  delete(this->getCheckIn());
  delete(this->getCheckOut());
}



// string ReservaIndividual::TipoReserva() { return "Individual"; }

// reservaIndividual::~reservaIndividual() {} 

Huesped *ReservaIndividual::getHuesped()
{
  return this->huesped;
}
void ReservaIndividual::setHuesped(Huesped *Huesped)
{
  this->huesped = huesped;
}
