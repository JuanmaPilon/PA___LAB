#ifndef RESERVAIND_H
#define RESERVAIND_H
#include "Reserva.h"
#include <string>
#include <DTFecha.h>
#include "Huesped.h"
#include "Usuario.h"


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