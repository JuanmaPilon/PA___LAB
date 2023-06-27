#ifndef ESTADIA_H
#define ESTADIA_H
#include "DTFecha.h"
#include "Reserva.h"
#include <string>

class Estadia {
public:
    Estadia();
    Estadia(int codigo, DTFecha* checkIn, DTFecha* checkOut, Reserva* reservaEstadia, Huesped* huespedEstadia);
    virtual ~Estadia();
    string getPromo();
    Reserva* getReserva();
    Huesped* getHuesped();
    void setFechaCheckIn(DTFecha* checkIN);
    void setFechaCheckOut(DTFecha* checkOUT);
    void setPromoCode(string codigo);

    bool estaFinalizada();
private:
    int codigo;
    string promo;
    DTFecha* checkIn;
    DTFecha* checkOut;
    Reserva* reservaEstadia;
    Huesped* huespedEstadia;

};

#endif