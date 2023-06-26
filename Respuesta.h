#ifndef RESPUESTA_H
#define RESPUESTA_H
#include "../ICollection/interfaces/ICollectible.h"
#include <string>
using namespace std;

class Respuesta : public ICollectible{
    public:
        Respuesta();
        virtual ~Respuesta();
    private:
        string resp;
};

#endif