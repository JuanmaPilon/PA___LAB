#define HOSTAL_H
#ifndef HOSTAL_H
#include <string>
using namespace std;



class Hostal {
public:
    Hostal();
    virtual ~Hostal();
private:
    string nombre;
    string direccion;
    int telefono;
};



#endif 