#ifndef RESERVA_H
#define RESERVA_H
#include "EstadoReserva.h"
#include "DTFecha.h"
#include "Estadia.h"
#include <map>
#include <string>
#include "Huesped.h"
#include "Habitacion.h"

class Reserva {
public:
    Reserva();
    Reserva(int Codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, Habitacion* habitacion);
    virtual float calcularCosto() = 0; //sin metodo
    virtual string tipoReserva() = 0; //sin metodo
    virtual ~Reserva();
    int getCodigo();
    EstadoReserva getEstado();
    Habitacion* getHabitacion();
    DTFecha* getCheckIn();
	DTFecha* getCheckOut();
    virtual Huesped* getHuesped(){return NULL;};
	virtual void setHuesped(Huesped* huesped){};
    void setHabitacion(Habitacion *habitacion);
    void setCodigo(int codigo);
    void setCheckIn(DTFecha* checkIn); 
	void setCheckOut(DTFecha* chechOut);
	void setEstado(EstadoReserva estado);
    void getReserva();
    virtual map<string, Huesped*> getHuespedes(){map<string, Huesped*> res; return res;};
protected:
int Codigo;
DTFecha* checkIn; 
DTFecha* checkOut;
EstadoReserva estado;
float costoReserva;
Huesped* huesped;
Habitacion* habitacion;
};

#endif