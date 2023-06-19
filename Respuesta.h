#define RESPUESTA_H
#ifndef RESPUESTA_H
#include <string>
using namespace std;

class Respuesta {
    public:
        Respuesta();
        virtual ~Respuesta();
    private:
        string resp;
}

#endif