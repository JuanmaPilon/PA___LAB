#ifndef FABRICA_H
#define FABRICA_H
#include <stdexcept>
#include "ISistema.h"
#include "CtrlSistema.h"

class Fabrica{
    public:
        static Fabrica* getInstance();
        
        ISistema* getISistema();
    private:
        static Fabrica* instancia;
        Fabrica();
		~Fabrica();
};
#endif



