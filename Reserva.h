#ifndef RESERVA_H
#define RESERVA_H
#include "EstadoReserva.h"
#include "DTFecha.h"
#include "Estadia.h"
#include <map>
#include <string>
#include "Huesped.h"
#include "Habitacion.h"
class Reserva{
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
map<int, Estadia*> colEstadias;
Huesped* huesped;
Habitacion* habitacion;
};

#endif