#ifndef DTHABITACION_H
#define DTHABITACION_H

#include <string>

using namespace std;

class DTHabitacion
{
private:
  int numero;
  float precio;
  int capacidad;

public:
  DTHabitacion(int numero, float precio, int capacidad);
  int getNumero();
  float getPrecio();
  int getCapacidad();
  void setNumero(int numero);
  void setPrecio(float precio);
  void setCapacidad(int capacidad);
};

ostream &operator<<(ostream &os, DTHabitacion &dt);

#endif
