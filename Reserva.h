#ifndef RESERVA_H
#define RESERVA_H
#include "EstadoReserva.h"
#include "DTFecha.h"
#include "Estadia.h"
#include <map>
#include <string>
#include "Huesped.h"
#include "Habitacion.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IDictionary.h"

class Reserva {
public:
    Reserva();
    Reserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, Habitacion* hab);
    virtual ~Reserva();
    DTFecha* getCheckIn();
	DTFecha* getCheckOut();
    void setHabitacion(Habitacion*);
    void getReserva();
    void cambioDeEstado();
    virtual Huesped* getHuesped(){return NULL;};
protected:
int codigo;
DTFecha* checkIn; 
DTFecha* checkOut;
EstadoReserva estado;
float costoReserva;
//IDictionary* colEstadias;
Huesped* huesped;
Habitacion* habitacion;
};

#endif