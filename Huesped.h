#ifndef HUESPED_H
#define HUESPED_H
#include "Usuario.h"

class Huesped : public Usuario{
public:
    Huesped();
    Huesped(const Huesped& obj);
    virtual ~Huesped();
private:

};

#endif /*HUESPED_H*/