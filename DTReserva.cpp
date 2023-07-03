#include "DTReserva.h"

DTReserva::DTReserva() {}
DTReserva::DTReserva(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado)
{
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
}

int DTReserva::getCodigo()
{
    return this->codigo;
}

DTFecha *DTReserva::getCheckIn()
{
    return this->checkIn;
}

DTFecha *DTReserva::getCheckOut()
{
    return this->checkOut;
}

EstadoReserva DTReserva::getEstado()
{
    return this->estado;
}

Habitacion *DTReserva::getHabitacion()
{
    return this->habitacionReserva;
}

Huesped *DTReserva::getHuespedDTReserva()
{
    return this->huespedReserva;
}

DTReserva::DTReserva(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, Huesped *huespedReserva, Habitacion *habitacionReserva)
{
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->huespedReserva = huespedReserva;
    this->habitacionReserva = habitacionReserva;
}
DTReserva::~DTReserva() {}
