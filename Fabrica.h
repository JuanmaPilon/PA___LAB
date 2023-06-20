#ifndef FABRICA_H
#define FABRICA_H
#include "ISistema.h"
#include "CtrlSistema.h"
class Fabrica: public ISistema {
    public:
        static Fabrica* getInstance();
        ~Fabrica(); 

    private:
        
        static Fabrica* instancia;
        Fabrica();
};
#endif



