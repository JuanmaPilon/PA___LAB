#define ESTADIA_H
#ifndef ESTADIA_H

class Estadia {
public:
    Estadia();
    virtual ~Estadia();
    void getEstadia();
    void agregarReserva();
    void agregarHuesped();
    void setCheckOut();
    void creoCalificacion();
    void getDatosEstadias();
    void buscoCalificacion();
private:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    int promo;

};

#endif