#ifndef HABITACION_H
#define HABITACION_H
#include "Reserva.h"
#include <map>
#include <string>
#include "../ICollection/interfaces/ICollectible.h"

class Habitacion {
public:
    Habitacion();
    virtual ~Habitacion();
private:
    int numero;
    float precioNoche;
    int capacidad;
    ICollectible* colReservas;
};



#endif