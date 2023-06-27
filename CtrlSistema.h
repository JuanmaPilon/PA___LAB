#include "ISistema.h"
#include "Estadia.h"
#include "Huesped.h"
#include "Hostal.h"
#include "Empleado.h"
#include <string>
#include "TipoCargo.h"
#include "EstadoReserva.h"
#include "DTFecha.h"
using namespace std;
class CtrlSistema : public ISistema{
public:
    static CtrlSistema *getInstancia();
    //copypaste de las opers de isistema
private:
    CtrlSistema();
    static CtrlSistema *instancia; //singleton
};

