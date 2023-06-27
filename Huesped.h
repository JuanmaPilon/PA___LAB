#ifndef HUESPED_H
#define HUESPED_H
#include "Usuario.h"
#include "Estadia.h"
#include <string>
#include "Reserva.h"
#include "ReservaGrp.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/ICollection.h"
using namespace std;

class Huesped : public Usuario {
public:
    Huesped();
    Huesped(string email, string nombre, string password, bool esFinger);
    virtual ~Huesped();
    void getHuesped();
    bool getEsFinger();
    void setEsFinger(bool esFinger);
    virtual ~Huesped();
private:
bool esFinger;
IDictionary* colEstadias;
ICollection* colReservaGrp;
Reserva* reserva;
};

#endif