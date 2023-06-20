#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H
#include "Reserva.h"
class ReservaGrupal : public Reserva{
private:

public:
    ReservaGrupal();
    map<string, Huesped*> colHuespedes;
};


#endif