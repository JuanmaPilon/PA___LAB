#ifndef HOSTAL_H
#define HOSTAL_H
#include "Reserva.h"
#include <map>
#include <string>
#include "Empleado.h"
#include "Habitacion.h"
using namespace std;



class Hostal {
public:
    Hostal();
    virtual ~Hostal();
private:
    string nombre;
    string direccion;
    int telefono;
    map <int , Reserva*> colReservas;
    map <int , Habitacion*> colHabitaciones;
    map <string, Empleado*> colEmpleados;

};



#endif 