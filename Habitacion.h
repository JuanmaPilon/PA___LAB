#ifndef HABITACION_H
#define HABITACION_H
#include "Reserva.h"
#include <map>
#include <string>
class Habitacion {
public:
    Habitacion();
    virtual ~Habitacion();
private:
    int numero;
    float precioNoche;
    int capacidad;
    map<int, Reserva*> colReservas;
};



#endif