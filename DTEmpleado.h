#ifndef DTEMPLEADO
#define DTEMPLEADO
#include <string>
#include "Usuario.h"
#include "TipoCargo.h"
#include "Hostal.h"

using namespace std;

class DTEmpleado{
    private:
        string email;
        string nombre;
        string password;

        tipoCargo cargo;
        Hostal *hostalTrabaja;
    public:
        DTEmpleado(string email, string nombre, string password, tipoCargo cargo, Hostal *nomHostal);

        string getEmail();
        string getNombre(); 
        tipoCargo getCargo(); 
        Hostal* getHostalTrabaja();

        void setEmail(string email);
        void setNombre(string nombre);
        void setCargo(tipoCargo cargo);
        void setHostalTrabaja(Hostal *hostalTrabaja);
        ~DTEmpleado();
};


#endif
