#define CALIFICACION_H
#ifndef CALIFICACION_H

class Calificacion{
public:
    Califcacion();
    virtual ~Calificacion();
    int getCaficacion();
    void getCalificaciones();
    void agregoRepsuesta();
private:
    int numCalificacion;
    string comentario;
    DTFechaCali fechaCali;
};

#endif