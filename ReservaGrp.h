#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H
#include "Reserva.h"
#include "../ICollection/interfaces/IDictionary.h"

class ReservaGrupal : public Reserva{
private:
    map<string, Huesped*> coleccionHuespedGrupal;
public:
    ReservaGrupal();
    ReservaGrupal(int codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, map<string,Huesped*>, Habitacion *habitacion);
	float calcularCosto();
	string tipoReserva();
	map<string, Huesped*> getHuespedes();
	~ReservaGrupal();
};


#endif