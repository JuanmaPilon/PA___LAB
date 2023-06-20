#ifndef HUESPED_H
#define HUESPED_H
#include "Usuario.h"
#include "Estadia.h"
#include <map>
#include <string>
#include "Reserva.h"
#include "ReservaGrp.h"
using namespace std;

using namespace std;
class Huesped : public Usuario{
public:
    Huesped();
    Huesped(const Huesped& obj);
    virtual ~Huesped();
private:
bool esFinger;
map<int, Estadia*> colEstadias;
map<string, ReservaGrupal*> colReservaGrp; // ver con nico
Reserva* reserva;
};

#endif