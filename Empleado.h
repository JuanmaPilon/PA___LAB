#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Usuario.h"
#include "TipoCargo.h"
#include <map>
#include <string>
#include "Respuesta.h"
#include "../ICollection/interfaces/IDictionary.h"


class Empleado : public Usuario{
public:
    Empleado();
    Empleado(const Empleado& obj);
    virtual ~Empleado();
private:

tipoCargo cargo;
IDictionary* colRespuestas;
};
#endif 