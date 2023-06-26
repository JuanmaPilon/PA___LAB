#ifndef CALIFICACION_H
#define CALIFICACION_H
#include <map>
#include <string>
using namespace std;
#include "Respuesta.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"

class Calificacion{
public:
    Calificacion();
    virtual ~Calificacion();
    int getCaficacion();
    void getCalificaciones();
    void agregoRepsuesta(string respuesta);
private:
    int numCalificacion;
    string comentario;
    //DTFechaCali fechaCali;

    ICollection* colCalificaciones;
    
};
#endif