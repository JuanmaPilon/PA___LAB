#ifndef HABITACION_H
#define HABITACION_H

class Habitacion {
public:
    Habitacion();
    virtual ~Habitacion();
private:
    int numero;
    float precioNoche;
    int capacidad;
};



#endif