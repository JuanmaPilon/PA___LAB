#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Usuario.h"
#include "TipoCargo.h"

class Empleado : public Usuario{
public:
    Empleado();
    Empleado(const Empleado& obj);
    virtual ~Empleado();
private:

tipoCargo cargo;

};
#endif /* EMPLEADO_H */// 