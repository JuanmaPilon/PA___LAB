#ifndef HUESPED_H
#define HUESPED_H
#include "Usuario.h"
#include "Estadia.h"
#include <string>
#include "Reserva.h"
#include "ReservaGrp.h"
using namespace std;

class Huesped : public Usuario {
public:
    Huesped();
    Huesped(string email, string nombre, string password, bool esFinger);
    virtual ~Huesped();
    void getHuesped();
    bool getEsFinger();
    void setEsFinger(bool esFinger);
    ~Huesped();
private:
bool esFinger;
Reserva* reserva;
};

#endif