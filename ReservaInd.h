#define RERSERVAIND_H
#ifndef RESERVAIND_H
#include "Reserva.h"

class ReservaInvdividual : public Reserva {
    public:
        ReservaInvdividual();
        virtual ~ReservaInvdividual();
        void agregoHuesped();
        void agregoHabitacion();
    private:

};


#endif