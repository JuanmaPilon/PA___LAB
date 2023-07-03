#ifndef DTRESERVA_H
#define DTRESERVA_H
#include <string>
using namespace std;
#include "DTHuesped.h"
#include "Huesped.h"
#include "EstadoReserva.h"
#include "DTFecha.h"
#include "Habitacion.h"
class Habitacion;
class Huesped;
class DTReserva
{
private:
	int codigo;
	DTFecha *checkIn;
	DTFecha *checkOut;
	EstadoReserva estado;
	Huesped *huespedReserva;
	Habitacion *habitacionReserva;

public:
	DTReserva();
	DTReserva(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado);
	DTReserva(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, Huesped *huespedReserva, Habitacion *habitacionReserva);
	int getCodigo();
	DTFecha *getCheckIn();
	DTFecha *getCheckOut();
	EstadoReserva getEstado();
	Huesped *getHuespedDTReserva();
	Habitacion *getHabitacion();
	~DTReserva();
};

ostream &operator<<(ostream &os, DTReserva &dt);

#endif
