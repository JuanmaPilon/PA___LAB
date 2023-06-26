#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H
#include "Reserva.h"
#include "../ICollection/interfaces/IDictionary.h"

class ReservaGrupal : public Reserva{
private:

public:
    ReservaGrupal();
    IDictionary* colReservaGrp;
};


#endif