#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;


class Usuario {
public:
Usuario();
Usuario(string email, string nombre, string password);
string getEmail();
string getNombre();
string getPassword();
void setEmail(string email);
void setNombre(string nombre);
void setPassword(string password);
~Usuario();
private:
string email;
string nombre;
string password;
};


#endif