#ifndef HOSTAL_H
#define HOSTAL_H
#include "Reserva.h"
#include <map>
#include <string>
#include "Empleado.h"
#include "Habitacion.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
using namespace std;



class Hostal : public ICollectible {
public:
    Hostal();
    virtual ~Hostal();
private:
    string nombre;
    string direccion;
    int telefono;
    ICollection* colReservas;
    ICollection* colHabitaciones;
    IDictionary* colEmpleados;

};



#endif 