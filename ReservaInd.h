#ifndef RESERVAIND_H
#define RESERVAIND_H

#include <string>
using namespace std;
#include "DTFecha.h"
#include "Reserva.h"


class ReservaIndividual : public Reserva {
    public:
        ReservaIndividual();
        ReservaIndividual(int Codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, Huesped* huesped, Habitacion* habitacion);
        ~ReservaIndividual();
        float calcularCosto();
        string tipoReserva();
        Huesped* getHuesped();
        void setHuesped(Huesped* Huesped);
        void borrarReserva();
        void agregoHuesped();
        void agregoHabitacion();
    private:
        Huesped* huesped;
};
#endif
