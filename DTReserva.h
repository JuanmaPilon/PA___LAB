#ifndef DTRESERVA
#define DTRESERVA
#include <string>
using namespace std;
#include "DTHuesped.h"
#include "Huesped.h"
#include "EstadoReserva.h"
#include "DTFecha.h"
#include "Habitacion.h"

class DTReserva {
	private:
		int codigo;
		DTFecha* checkIn;
		DTFecha* checkOut;
		EstadoReserva estado;
		//float costo;
		Huesped* huespedReserva;
		Habitacion* habitacionReserva;
	public:
		DTReserva();
		DTReserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado/*, float costo, int habitacion*/);
		DTReserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, Huesped *huespedReserva, Habitacion *habitacionReserva);

		int getCodigo(); //getters
		DTFecha* getCheckIn();
		DTFecha* getCheckOut();
		EstadoReserva getEstado();
		Huesped* getHuespedDTReserva();
		Habitacion* getHabitacion();
		~DTReserva();
};

//Sobrecarga de operadora para los DTReserva
ostream& operator<<(ostream& os, DTReserva& dt);

#endif