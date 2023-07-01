#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H

#include <map>
#include <string>
#include <map>

#include "DTFecha.h"
#include "Reserva.h"

#include "Usuario.h"
#include "Empleado.h"
#include "Huesped.h"


class ReservaGrupal : public Reserva {
private:
    map<string, Huesped*> coleccionHuespedGrupal;
public:
    ReservaGrupal();
    ReservaGrupal(int Codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, map<string,Huesped*>, Habitacion *habitacion);
	float calcularCosto();
	string tipoReserva();
	map<string, Huesped*> getHuespedes();
	~ReservaGrupal();
};


#endif
