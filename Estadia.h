#ifndef ESTADIA_H
#define ESTADIA_H
#include <string>
using namespace std;

#include "Reserva.h"
#include "Reloj.h"
#include "DTFecha.h"
class Habitacion;

class Estadia {
public:
    Estadia();
    Estadia(DTFecha* checkIn, DTFecha* checkOut, Reserva* reservaEstadia, Huesped* huespedEstadia);
    virtual ~Estadia();
    string getPromo();
    Reserva* getReserva();
    Huesped* getHuesped();
    DTFecha* getCheckIn();
    DTFecha* getCheckOut();
    void setFechaCheckIn(DTFecha* checkIN);
    void setFechaCheckOut(DTFecha* checkOUT);
    void setPromoCode(string codigo);

    bool estaFinalizada();
private:
    string promo;
    DTFecha* checkIn;
    DTFecha* checkOut;
    Reserva* reservaEstadia;
    Huesped* huespedEstadia;

};

#endif
