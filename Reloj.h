#ifndef RELOJ
#define RELOJ
#include "DTFecha.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Reloj
{
private:
    static Reloj *instancia;
    ~Reloj();
    Reloj(int dia, int mes, int anio, int hora, int minuto);

    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

public:
    static Reloj *getInstancia();
    static void releaseInstancia();

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    void setReloj(int dia, int mes, int anio, int hora, int minuto);
    DTFecha *getReloj();
};

#endif