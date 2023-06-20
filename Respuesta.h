#ifndef RESPUESTA_H
#define RESPUESTA_H

#include <string>
using namespace std;

class Respuesta {
    public:
        Respuesta();
        virtual ~Respuesta();
    private:
        string resp;
};

#endif