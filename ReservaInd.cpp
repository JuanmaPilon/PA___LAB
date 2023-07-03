#include "Reserva.h"
#include "ReservaInd.h"
#include "Habitacion.h"
#include "Huesped.h"
#include <string>
#include <iostream>
using namespace std;

ReservaIndividual::ReservaIndividual()
{
}
ReservaIndividual::ReservaIndividual(int Codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva Estado, Huesped *huesped, Habitacion *habitacion) : Reserva(Codigo, checkIn, checkOut, estado, habitacion)
{
  this->huesped = huesped;
}

float ReservaIndividual::calcularCosto()
{

  return 0;
}

void ReservaIndividual::borrarReserva()
{
  this->huesped = NULL;
  Reserva::setHabitacion(NULL);
  delete (this->getCheckIn());
  delete (this->getCheckOut());
}

ReservaIndividual::~ReservaIndividual() {}

Huesped *ReservaIndividual::getHuesped()
{
  return this->huesped;
}
void ReservaIndividual::setHuesped(Huesped *Huesped)
{
  this->huesped = huesped;
}

string ReservaIndividual::tipoReserva() { return "Individual"; }
