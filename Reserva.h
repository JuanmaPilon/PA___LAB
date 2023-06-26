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

class Reserva : public ICollectible{
public:
    Reserva();
    Reserva(const Reserva& obj);
    virtual ~Reserva();
    void getReserva();
    void cambioDeEstado();
private:
int codigo;
DTFecha* checkIn; 
DTFecha* checkOut;
EstadoReserva estado;
float costoReserva;
IDictionary* colEstadias;
Huesped* huesped;
Habitacion* habitacion;
};

#endif