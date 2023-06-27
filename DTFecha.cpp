#include "DTFecha.h"
#include <stdexcept>
#include <iostream>
using namespace std;

DTFecha::DTFecha()
{
    this->anio = 0;
    this->mes = 0;
    this->dia = 0;
    this->hora = 0;
    this->minuto = 0;
};

DTFecha::DTFecha(int dia, int mes, int anio, int hora, int minuto)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    if (dia > 31 || dia < 1 || mes > 12 || mes < 1 || anio < 1900 || hora > 23 || hora < 0 || minuto > 59 || minuto < 0)
    {
        throw std::invalid_argument("Esa fecha no es valida");
    }
};

DTFecha::~DTFecha(){};

int DTFecha::getDia()
{
    return this->dia;
};

int DTFecha::getMes()
{
    return this->mes;
};

int DTFecha::getAnio()
{
    return this->anio;
};

int DTFecha::getHora()
{
    return this->hora;
};

int DTFecha::getMinuto()
{
    return this->minuto;
};

bool operator<(DTFecha &f1, DTFecha &f2)
{
    return (((f1.getDia() < f2.getDia()) && (f1.getMes() == f2.getMes()) && (f1.getAnio() == f2.getAnio())) || ((f1.getMes() < f2.getMes()) && (f1.getAnio() == f2.getAnio())) || (f1.getAnio() < f2.getAnio()));
}

bool DTFecha::esMayor(DTFecha *f1)
{
    bool anio = (f1->getAnio() < this->anio);
    bool anioMes = ((f1->getMes() < this->mes) && (f1->getAnio() == this->anio));
    bool anioMesDia = ((f1->getDia() < this->dia) && (f1->getMes() == this->mes) && (f1->getAnio() == this->anio));
    return (anio || anioMes || anioMesDia);
}

ostream &operator<<(ostream &out, DTFecha &dtfh)
{
    int dia = dtfh.getDia();
    int mes = dtfh.getMes();
    int anio = dtfh.getAnio();
    int hora = dtfh.getHora();
    int minuto = dtfh.getMinuto();
    out << dia << "/" << mes << "/" << anio << " - " << hora << ":";
    if (minuto < 10)
    {
        out << "0";
    };
    out << minuto << endl;
    return out;
};

// sobrecarga de operador - para calcular la diferencia entre instancias de DtFechaHora en minutos
int operator-(DTFecha &f1, DTFecha &f2)
{
    struct tm time1;
    struct tm time2;

    time1.tm_hour = f1.getHora();
    time1.tm_min = f1.getMinuto();
    time1.tm_year = f1.getAnio() - 1900;
    time1.tm_mon = f1.getMes();
    time1.tm_mday = f1.getDia();
    time1.tm_sec = 0;

    time2.tm_hour = f2.getHora();
    time2.tm_min = f2.getMinuto();
    time2.tm_year = f2.getAnio() - 1900;
    time2.tm_mon = f2.getMes();
    time2.tm_mday = f2.getDia();
    time2.tm_sec = 0;

    int resultado = difftime(mktime(&time1), mktime(&time2)) / 60;
    return resultado;
};

void DTFecha::imprimirFecha()
{
    cout << this->dia << "/" << this->mes << "/" << this->anio;
    cout << " a las " << this->hora << ":" << this->minuto << endl;
};