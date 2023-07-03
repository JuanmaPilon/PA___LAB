#ifndef HOSTAL_H
#define HOSTAL_H
#include <string>
#include <iostream>
#include <map>

#include "Habitacion.h"

using namespace std;

class Habitacion;
class Estadia;

class Hostal
{
public:
    Hostal();
    Hostal(string nombre, string direccion, string telefono);
    map<int, Habitacion *> getColeccionHabitaciones();
    map<string, Estadia *> getColeccionEstadia();
    string getNombre();
    string getDireccion();
    string getTelefono();
    Habitacion *getHabitacion(int num);
    Estadia *getEstadia(string cod);
    void setNombre(string nombre);
    void setDireccion(string direccion);
    void setTelefono(string telefono);
    void agregarHabitacion(int num, Habitacion *hab);
    void agregarEstadia(string cod, Estadia *e);
    void eliminarEstadia(string cod);
    ~Hostal();

private:
    string nombre;
    string direccion;
    string telefono;
    map<int, Habitacion *> coleccionHabitaciones;
    map<string, Estadia *> coleccionEstadia;
};

#endif
