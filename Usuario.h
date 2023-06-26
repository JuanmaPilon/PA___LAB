#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "../ICollection/interfaces/ICollectible.h"
using namespace std;


class Usuario : public ICollectible {
public:
Usuario();
virtual ~Usuario();
private:
string email;
string nombre;
string password;
};


#endif