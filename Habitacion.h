#ifndef HABITACION_H
#define HABITACION_H
#include "Reserva.h"
#include <map>
#include <string>
#include "Hostal.h"
using namespace std;
class Hostal;
class Habitacion {
public:
    Habitacion();
    Habitacion(int numero, float precio, int capacidad);
    int getNumero();
    float getPrecio();
    int getCapacidad();
    Hostal* getHostal();
  
    void setNumero(int numero);
    void setPrecio(float precio);
    void setCapacidad(int capacidad);
    void setHostalHabitacion(Hostal *hos);
private:
    int numero;
    float precio;
    int capacidad;
    Hostal *hostalHabitacion;
};



#endif
