#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;

class Usuario{
public:
Usuario();
virtual ~Usuario();
private:
string email;
string nombre;
string password;

};


#endif /* USUARIO_H */