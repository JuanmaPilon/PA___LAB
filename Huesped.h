#ifndef HUESPED_H
#define HUESPED_H
#include <string>
#include "Usuario.h"
#include "Reserva.h"
using namespace std;
class Huesped : public Usuario
{
public:
    Huesped();
    Huesped(string email, string nombre, string password, bool esFinger);
    virtual ~Huesped();
    void getHuesped();
    bool getEsFinger();
    void setEsFinger(bool esFinger);

private:
    bool esFinger;
};

#endif
