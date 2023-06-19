#define CALIFICACION_H
#ifndef CALIFICACION_H

class Calificacion{
public:
    Califcacion();
    virtual ~Calificacion();
private:
    int numCalificacion;
    string comentario;
    DTFechaCali fechaCali;
};

#endif /* CALIFICACION_H */ 