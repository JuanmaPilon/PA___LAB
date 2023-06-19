#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha {
public:
DTFecha(int, int, int, int);
DTFecha();
~DTFecha();

int getDia();
int getMes();
int getAnio();
int getHora();

void setDia(int);
void setMes(int);
void setAnio(int);
void setHora(int);

private:
int dia;
int mes;
int anio;
int hora;

};

#endif