#include "Reloj.h"
#include "DTFecha.h"
#include <iostream>
using namespace std;
#include <iomanip>

Reloj::Reloj(int diaN, int mesN, int anioN, int horaN, int minutoN)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
};

Reloj *Reloj::instancia = NULL;

Reloj *Reloj::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new Reloj(3, 7, 2023, 20, 30);
    };
    return instancia;
};

void Reloj::releaseInstancia()
{
    if (instancia != NULL)
    {
        delete instancia;
        instancia = NULL;
    };
}

Reloj::~Reloj(){};

int Reloj::getDia()
{
    return this->dia;
};

int Reloj::getMes()
{
    return this->mes;
};

int Reloj::getAnio()
{
    return this->anio;
};

int Reloj::getHora()
{
    return this->hora;
};

int Reloj::getMinuto()
{
    return this->minuto;
};

void Reloj::setReloj(int dia, int mes, int anio, int hora, int minuto)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
};

DTFecha *Reloj::getReloj()
{
    DTFecha *res = new DTFecha(this->dia, this->mes, this->anio, this->hora, this->minuto);
    return res;
};