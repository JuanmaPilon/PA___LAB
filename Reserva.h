#ifndef RESERVA_H
#define RESERVA_H
#include "EstadoReserva.h"
#include "DTFecha.h"
#include "Estadia.h"
#include <map>
#include <string>
#include "Huesped.h"
#include "Habitacion.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IDictionary.h"

class Reserva {
public:
    Reserva();
    Reserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, Habitacion* habitacion);
    virtual float calcularCosto() = 0; //sin metodo
	virtual string tipoReserva() = 0; //sin metodo
    int getCodigo();
    virtual Huesped* getHuesped(){return NULL;};
    DTFecha* getCheckIn();
	DTFecha* getCheckOut();
    void getReserva();
    EstadoReserva getEstado();
    Habitacion* getHabitacion();
    void setHabitacion(Habitacion* habitacion);
    virtual void setHuesped(Huesped* huesped);
    void setCodigo(int codigo);
    void setCheckIn(DTFecha* checkIn); 
	void setCheckOut(DTFecha* chechOut);
    void setEstado(EstadoReserva estado);
    virtual ~Reserva();
protected:
    int codigo;
    DTFecha* checkIn; 
    DTFecha* checkOut;
    EstadoReserva estado;
    float costoReserva;
    //IDictionary* colEstadias;
    Huesped* huesped;
    Habitacion* habitacion;
};

#endif