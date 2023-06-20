#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Usuario.h"
#include "TipoCargo.h"
#include <map>
#include <string>
#include "Respuesta.h"
class Empleado : public Usuario{
public:
    Empleado();
    Empleado(const Empleado& obj);
    virtual ~Empleado();
private:

tipoCargo cargo;
map<string, Respuesta*> colRespuestas;
};
#endif 