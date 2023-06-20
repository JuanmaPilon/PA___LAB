#ifndef FABRICA_H
#define FABRICA_H
#include "ISistema.h"
class Fabrica: public ISistema {
    public:
        static Fabrica* getInstance();
        ~Fabrica(); 

    private:
        static Fabrica* instancia;
        Fabrica();
};
#endif