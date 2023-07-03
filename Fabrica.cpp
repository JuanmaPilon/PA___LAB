#include "Fabrica.h"
#include "CtrlSistema.h"

Fabrica *Fabrica::instancia = nullptr;

Fabrica::Fabrica()
{
}

Fabrica *Fabrica::getInstance()
{
    if (instancia == nullptr)
    {
        instancia = new Fabrica();
    }
    return instancia;
}
Fabrica::~Fabrica(){};
ISistema *Fabrica::getISistema()
{
    return CtrlSistema::getInstancia();
};
