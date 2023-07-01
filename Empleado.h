#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Usuario.h"
#include "TipoCargo.h"
#include <map>
#include <string>
#include "Hostal.h"


class Empleado : public Usuario{
public:
    Empleado();
    Empleado(string email, string nombre, string password, tipoCargo cargo,Hostal* hostalTrabaja);
    ~Empleado();
    string getCargo();
    Hostal* getHostalTrabaja();
    void setHostalTrabaja(Hostal *hos);
    void setCargo(tipoCargo cargo);      
private:
    Hostal* hostalTrabaja;
    tipoCargo cargo;
  
};
#endif 
