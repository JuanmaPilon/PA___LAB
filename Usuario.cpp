#include "Usuario.h"

Usuario::Usuario()
{
    this->email = "";
    this->nombre = "";
    this->password = "";
}

Usuario::Usuario(string email, string nombre, string password)
{
    this->email = email;
    this->nombre = nombre;
    this->password = password;
};

string Usuario::getEmail()
{
    return this->email;
}

string Usuario::getNombre()
{
    return this->nombre;
}

string Usuario::getPassword()
{
    return this->password;
}

void Usuario::setEmail(string email)
{
    this->email = email;
}
void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Usuario::setPassword(string password)
{
    this->password = password;
}