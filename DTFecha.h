#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <istream>
#include <ios>
#include <time.h>

using namespace std;

class DTFecha
{
public:
    DTFecha(int dia, int mes, int anio, int hora, int minuto);
    DTFecha();
    ~DTFecha();

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    void setDia(int);
    void setMes(int);
    void setAnio(int);
    void setHora(int);

    bool esMayor(DTFecha *f);
    friend bool operator<(DTFecha &f1, DTFecha &f2);
    friend ostream &operator<<(ostream &out, DTFecha &dtfh);
    friend int operator-(DTFecha &f1, DTFecha &f2);
    void imprimirFecha();

private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
};

#endif
