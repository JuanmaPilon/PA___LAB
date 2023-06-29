#include "CtrlSistema.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <istream>
#include <ios>
#include "ReservaInd.h"
#include "ReservaGrp.h"
#include "DTHabitacion.h"
#include "Fabrica.h"
#include "DTEmpleado.h"

CtrlSistema::CtrlSistema(){
}

CtrlSistema *CtrlSistema::instancia = NULL;

CtrlSistema *CtrlSistema::getInstancia()
{
	if (instancia == NULL)
		instancia = new CtrlSistema();
	return instancia;
};

void CtrlSistema::confirmarAltaHostal(string nombre, string direccion, string telefono)
{
  Hostal *nuevoHostal = new Hostal(nombre, direccion, telefono);
  this->coleccionHostales.insert({nombre, nuevoHostal});
}


void CtrlSistema::finalizarEstadia(string email){
  map<string, Estadia *> e = getHostal()->getColeccionEstadia();
  map<string, Estadia *>::iterator it= e.begin();
  Estadia* est;
  string key;
  while(it != e.end()){
    est= it->second;    //la estadia
    string texto= est->getHuesped()->getEmail();
    if(texto == email){
      int cod= est->getReserva()->getCodigo();
      key= to_string(cod) + email;
      it= e.end();
    } else {
      it++;
    }
  }

  Reloj *r = Reloj::getInstancia();
  DTFecha* fecha= r->getReloj();
  est->setFechaCheckOut(fecha);
} // COMPLETAR

bool CtrlSistema::existeEstadia(string email)
{ // COMPLETAR
  map<string, Estadia *> e = getHostal()->getColeccionEstadia();
  map<string, Estadia *>::iterator it= e.begin();
  Estadia* est;
  string key;

  while(it != e.end()){
    est= it->second;    //la estadia
    string texto= est->getHuesped()->getEmail();
    if(texto == email){
      int cod= est->getReserva()->getCodigo();
      key= to_string(cod) + email;
      it= e.end();
    } else {
      it++;
    }
  }
  return (e.find(key) != e.end());
}

bool CtrlSistema::estadiaValida(string email){

  map<string, Estadia *> e = getHostal()->getColeccionEstadia();
  map<string, Estadia *>::iterator it= e.begin();
  Estadia* est;
  string key;
  bool seguir= true;

  while(it != e.end()){
    est= it->second;    //la estadia
    string texto= est->getHuesped()->getEmail();
    if((texto == email) && (est->getCheckOut()==NULL)){
      int cod= est->getReserva()->getCodigo();
      key= to_string(cod) + email;
      it= e.end();
    } else {
      it++;
    }
  }
  return (est->getCheckOut() == NULL);


}

bool CtrlSistema::existeHostal(string nombre)
{
  map<string, Hostal *>::iterator iterador = this->coleccionHostales.find(nombre);
  return !(iterador == this->coleccionHostales.end());
}

void CtrlSistema::obtenerHostales()
{
  map<string, Hostal *> hostales = this->coleccionHostales;
  map<string, Hostal *>::iterator it;

  cout << "---------------------Listado de hostales disponibles----------------------------" << endl;
  for (it = hostales.begin(); it != hostales.end(); it++)
  {
    Hostal *hostalAux = it->second;
    DTHostal *aux = new DTHostal(hostalAux->getNombre(), hostalAux->getDireccion(), hostalAux->getTelefono());
    cout << "-Nombre del hostal: " << aux->getNombre() << endl;
    cout << "-Direccion: " << aux->getDireccion() << endl;
    cout << "-Telefono: " << aux->getTelefono() << endl;
    cout << "-------------" << endl;
    delete (aux);
  }
}

void CtrlSistema::seleccionarHostal(string nomHostal)
{
  map<string, Hostal *>::iterator it = this->coleccionHostales.find(nomHostal);
  this->hostalSeleccionado = it->second;
};

Hostal *CtrlSistema::getHostal()
{
  return this->hostalSeleccionado;
} // COMPLETAR

void CtrlSistema::asignarEmpHostal() {} // COMPLETAR

Habitacion *CtrlSistema::getHabitacion(Hostal *hos, int num)
{
  map<int, Habitacion *> h = hos->getColeccionHabitaciones();
  map<int, Habitacion *>::iterator iterador = h.find(num);
  return (iterador->second);
}

Habitacion *CtrlSistema::seleccionarHabitacion(int numero)
{
  return NULL;
}

void CtrlSistema::imprimirlnfoEstadia(string nomHostal, string emailestadia, int cod)
{
  map<string, Hostal *>::iterator iter = this->coleccionHostales.find(nomHostal);
  Hostal *elhostal = iter->second;

  map<string, Estadia *> estadias = elhostal->getColeccionEstadia();
  map<string, Estadia *>::iterator it = estadias.find(to_string(cod) + emailestadia);

  string PROMO;
  int quiere;

  Estadia *res = it->second;
  DTFecha *fecha1 = res->getCheckIn();

  DTFecha *fecha2=NULL;
  if (res->getCheckOut()!=NULL){
    fecha2=res->getCheckOut();
  }

  cout << "Fecha checkIn: ";
  fecha1->imprimirFecha();
  cout << "Fecha de checkOut: ";
  if (fecha2 != NULL){
    fecha2->imprimirFecha();
  } else {
    cout << "aun no realiza checkOut";
  }

  Huesped *hue = res->getHuesped();
  // cout << "Huesped: " << hue->getNombre() << endl;

  Reserva *reservaAsociada = res->getReserva();
  cout << "Codigo de reserva asociada: " << reservaAsociada->getCodigo() << endl;

  cout << "Desea ver la informacion de la reserva asociada? SI = 1, NO = 0" << endl;
  cin >> quiere;

  if (quiere == 1)
  {
    string estado;
    if (reservaAsociada->getEstado() == ABIERTA){
      estado = "Abierta";
    } else if (reservaAsociada->getEstado()== CERRADA){
      estado = "Cerrada";
    } else if (reservaAsociada->getEstado() == CANCELADA){
      estado = "Cancelada";
    }

    cout << "Estado de la reserva: " << estado << endl;
    cout << "Numero de habitacion: " << reservaAsociada->getHabitacion()->getNumero()<< endl;
  }
}

void CtrlSistema::imprimirHabitaciones(Hostal *h)
{
  map<int, Habitacion *> habitaciones = h->getColeccionHabitaciones();
  map<int, Habitacion *>::iterator it;

  cout << "---------------------Listado de habitaciones disponibles----------------------------" << endl;
  for (it = habitaciones.begin(); it != habitaciones.end(); it++)
  {
    Habitacion *habAux = it->second;
    DTHabitacion *aux = new DTHabitacion(habAux->getNumero(), habAux->getPrecio(), habAux->getCapacidad());
    cout << "-Numero de habitacion: " << aux->getNumero() << endl;
    cout << "-Precio: " << aux->getPrecio() << endl;
    cout << "-Capacidad: " << aux->getCapacidad() << endl;
    cout << "-------------" << endl;
    delete (aux);
  }
}

Estadia *CtrlSistema::getEstadia()
{
  return this->estadiaSeleccionada;
} // COMPLETAR

void CtrlSistema::seleccionarEstadia(int cod, string email)
{
  map<string, Estadia *>::iterator iterador = hostalSeleccionado->getColeccionEstadia().find(to_string(cod) + email);
  Estadia *res = iterador->second;
  this->estadiaSeleccionada = res;
}

void CtrlSistema::imprimirInfoBasicaHostal(Hostal *hos)
{
  cout << "-Nombre del hostal: " << hos->getNombre() << endl;
  cout << "-Direccion: " << hos->getDireccion() << endl;
  cout << "-Telefono: " << hos->getTelefono() << endl;
  cout << "-------------" << endl;
};

void CtrlSistema::confirmarAltaHabitacion(){
  Habitacion *hab = new Habitacion(this->numeroHabitacion, this->precioHabitacion, this->capacidadHabitacion);
  this->hostalSeleccionado->agregarHabitacion(numeroHabitacion, hab);
  hab->setHostalHabitacion(this->hostalSeleccionado);

  this->numeroHabitacion = 0;
  this->precioHabitacion = 0;
  this->capacidadHabitacion = 0;
  this->hostalSeleccionado = NULL;

} // COMPLETAR

void CtrlSistema::agregarEstadia(string key, Estadia* est){
  this->hostalSeleccionado->agregarEstadia(key, est);
  this->hostalSeleccionado = NULL;
}


void CtrlSistema::ingresaristarEstadiasFinalizadas(string emailUsuario) {} // COMPLETAR



void CtrlSistema::ingresarInformacionHabitacion(int num, float precio, int capacidad)
{
  this->numeroHabitacion = num;
  this->precioHabitacion = precio;
  this->capacidadHabitacion = capacidad;
}


void CtrlSistema::listarEstadiasFinalizadas(string email){
  map<string, Hostal *>::iterator it2 = this->coleccionHostales.find(this->hostalSeleccionado->getNombre());
  Hostal *elHostal = it2->second;
  cout << "Hostal seleccionado: " << elHostal->getNombre() << endl;
  map<string, Estadia *> estad = elHostal->getColeccionEstadia();
  map<string, Estadia *>::iterator it;

  cout << "---------------------Listado de estadias finalizadas----------------------------" << endl;
  for (it = estad.begin(); it != estad.end(); it++)
  {
    
    if (it->second->getReserva()->getHabitacion()->getHostal()->getNombre() == this->hostalSeleccionado->getNombre() &&
        it->second->getHuesped()->getEmail() == email && (it->second->getCheckOut() != NULL))
    {
      Estadia *est = it->second;
      DTEstadia *aux = new DTEstadia(est->getCheckIn(), est->getCheckOut(), est->getReserva()->getCodigo(), est->getHuesped()->getEmail());
      cout << "-Numero de reserva: " << aux->getCodigoReserva() << endl;
      cout << "-Correo del huesped: " << aux->getEmailHuesped() << endl;
      cout << "-Fecha de checkIn: "; 
      aux->getFechaCheckIn()->imprimirFecha();
      cout << "-Fecha de checkOut: "; 
      aux->getFechaCheckOut()->imprimirFecha();

      delete (aux);
    }
  }
}


void CtrlSistema::imprimirEstadias(string nomHostal){ // imprime todas las estadias (no la info)

  map<string, Hostal *>::iterator iter = this->coleccionHostales.find(nomHostal);
  Hostal *elhostal = iter->second;
  map<string, Estadia *> estadias = elhostal->getColeccionEstadia();
  map<string, Estadia *>::iterator it;
  cout << "---------------------Listado de estadias del hostal----------------------------" << endl;
  for (it = estadias.begin(); it != estadias.end(); it++)
  {
    cout << "Estadia: " << it->second->getHuesped()->getEmail();
    cout << "     Codigo de reserva: " << it->second->getReserva()->getCodigo() << endl;
  }
}

Reserva *CtrlSistema::seleccionarReserva(int codigo)
{
	map<int, Reserva *>::iterator it;
	it = this->coleccionReservas.find(codigo);
	Reserva *res = it->second;
	return res;
}

Reserva *CtrlSistema::getReserva()
{
	return NULL;
}

void CtrlSistema::cancelarReserva() {}

void CtrlSistema::confirmarReserva(int Codigo, Hostal *h, DTFecha *checkIn, DTFecha *checkOut, int tipoDeReserva, Habitacion *hab, Huesped *hue, map<string, Huesped *> coleccionHuespedReserva)
{
	if (tipoDeReserva == 0)
	{ // reserva individual
		ReservaIndividual *res = new ReservaIndividual(Codigo ,checkIn, checkOut, EstadoReserva::ABIERTA, hue, hab);
		coleccionReservas.insert({Codigo, res});
	}
	else
	{ // reserva grupal
		ReservaGrupal *res = new ReservaGrupal(Codigo, checkIn, checkOut, EstadoReserva::ABIERTA, coleccionHuespedReserva, hab);
		coleccionReservas.insert({Codigo, res});
	}
}

void CtrlSistema::ingresarInformacionReserva(DTFecha checkIN, DTFecha checkOUT, DTReserva *tipoReserva) {}

void CtrlSistema::obtenerReserva()
{
}

void CtrlSistema::obtenerReservas(Hostal *hos)
{
}

void CtrlSistema::obtenerReservasPorHostal(string nomHostal)
{
	map<int, Reserva *> reservas = this->coleccionReservas; // coleccion de reservas
	map<int, Reserva *>::iterator it;

	cout << "---------------------Listado de reservas registradas en el sistema----------------------------" << endl;
	for (it = reservas.begin(); it != reservas.end(); it++){

		if ((it->second != NULL) && (it->second->getHabitacion()->getHostal()->getNombre() == nomHostal))
		{

			cout << "Codigo de reserva: " << it->second->getCodigo() << endl;
			cout << "Numero de habitacion: " << it->second->getHabitacion()->getNumero() << endl;
			cout << "Fecha de check-in: ";
			it->second->getCheckIn()->imprimirFecha();
			cout << "Fecha de check-out: ";
			it->second->getCheckOut()->imprimirFecha();
			string estado;
			if (it->second->getEstado() == ABIERTA)
			{
				estado = "Abierta";
			}
			else if (it->second->getEstado() == CERRADA)
			{
				estado = "Cerrada";
			}
			else if (it->second->getEstado() == CANCELADA)
			{
				estado = "Cancelada";
			}

			cout << "Estado de la reserva: " << estado << endl;

			if (it->second->tipoReserva() == "Individual")
			{
				cout << "Tipo de reserva: Individual" << endl;
				cout << "Nombre del huesped: " << it->second->getHuesped()->getNombre() << endl;
				cout << "-----------------------------------";
			}
			else if (it->second->tipoReserva() == "Grupal")
			{
				cout << "Tipo de reserva: Grupal" << endl;
				map<string, Huesped *> huespedes = it->second->getHuespedes();
				map<string, Huesped *>::iterator itHuespedes;
				int cont = 1;
				cout << "--------------------------" << endl;

				for (itHuespedes = huespedes.begin(); itHuespedes != huespedes.end(); itHuespedes++)
				{
					cout << "Nombre del huesped " << cont << ": " << itHuespedes->second->getNombre() << endl;
					cont++;
					cout << "--------------------------" << endl;
				}
			}
		}
	}
	cout << endl;
}

void CtrlSistema::imprimirReservasHuesped(Huesped *hues){
	map<int, Reserva *> reservas = this->coleccionReservas;
	map<int, Reserva *>::iterator it;

	for (it = reservas.begin(); it != reservas.end(); it++){
		if (it->second->tipoReserva() == "Individual"){ //SI ES INDIVIDUAL
			if (it->second->getHuesped() == hues){
			Reserva *resAux = it->second;
			DTReserva *aux = new DTReserva(resAux->getCodigo(), resAux->getCheckIn(), resAux->getCheckOut(), resAux->getEstado(), hues, resAux->getHabitacion());

			cout << "-----------------------------------" << endl;
			cout << "Codigo: " << aux->getCodigo() << endl;
			cout << "Fecha check in: ";
			aux->getCheckIn()->imprimirFecha();
			cout << "Fecha check out: ";
			aux->getCheckOut()->imprimirFecha();
			cout << "Estado: " << aux->getEstado() << endl;
			cout << "A nombre de: " << aux->getHuespedDTReserva()->getNombre() << endl;
			cout << "Habitacion: " << aux->getHabitacion()->getNumero() << endl;
			
			}
		} else {	//SI ES GRUPAL
			map<string, Huesped*> h= it->second->getHuespedes();
			map<string, Huesped*>::iterator itEr= h.begin();
			for(itEr = h.begin(); itEr != h.end(); itEr++){
				if (itEr->second == hues){
					Reserva *resAux = it->second;
					DTReserva *aux = new DTReserva(resAux->getCodigo(), resAux->getCheckIn(), resAux->getCheckOut(), resAux->getEstado(), hues, resAux->getHabitacion());

					cout << "-----------------------------------" << endl;
					cout << "Codigo: " << aux->getCodigo() << endl;
					cout << "Fecha check in: ";
					aux->getCheckIn()->imprimirFecha();
					cout << "Fecha check out: ";
					aux->getCheckOut()->imprimirFecha();
					cout << "Estado: " << aux->getEstado() << endl;
					cout << "A nombre de: " << itEr->second->getNombre() << endl;
					cout << "Habitacion: " << aux->getHabitacion()->getNumero() << endl;
				} //if
			} //for
			
		}	//if
		
	}	//for
	cout << "-----------------------------------" << endl;
}

void CtrlSistema::habitacionDisponible(DTFecha *checkIn, DTFecha *checkOut, Hostal *h)
{
	map<int, Reserva*> reservas = this->coleccionReservas;
	map<int, Reserva*>::iterator it;
	Fabrica *fab = Fabrica::getInstance(); // Llamo a la instancia de la fabrica
	ISistema *isistemaH = fab->getISistema();

	map<int, Habitacion*> habitaciones = h->getColeccionHabitaciones();
	map<int, Habitacion*>::iterator iter;
	bool reservada = false;
	bool disponible;

	for (iter = habitaciones.begin(); iter != habitaciones.end(); iter++){ //Por cada habitacion dentro del hostal seleccionado
		for (it = reservas.begin(); it != reservas.end(); it++){
			if ((iter->second->getNumero() == it->second->getHabitacion()->getNumero()) 
					&& (iter->second->getHostal()->getNombre() == it->second->getHabitacion()->getHostal()->getNombre())){
				if (checkIn->esMayor(it->second->getCheckOut())){
					reservada = false;
					cout << "La fecha de checkin es mayor que al de checkout" << endl;

				} else if (it->second->getCheckIn()->esMayor(checkOut)){
					reservada = false;
					cout << "La fecha de checkout es mayor que al de checkout" << endl;

				} else {
					cout << "Ese dia esta ocupada" << endl;
					reservada = true;
				}
			}
		}
		
		if(it == reservas.end()){
			if (iter->second->getHostal()->getNombre() == h->getNombre()){
				disponible = true;
			} else {
				disponible = false;
			}
		}

	if (!(reservada) && disponible){
			cout << "----------------------------" << endl;
			cout << "Habitacion " << iter->second->getNumero() << endl;
			cout << "Precio: " << iter->second->getPrecio() << endl;
		}
	reservada = false;
	}
}

void CtrlSistema::setHostalTrabaja(Hostal *hos){
    this->hostalTrabaja = hos;
};

void CtrlSistema::imprimirReservasHuesped(string emailHuesped){

};

set<DTEmpleado*> CtrlSistema::obtenerEmpleadosNoRegistrados(Hostal *hos){

    set<DTEmpleado*> res;

    map<string, Usuario*>::iterator itU;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (Empleado* e = dynamic_cast<Empleado*>(itU->second)){
            if(e->getHostalTrabaja() == NULL){

                tipoCargo cargo;
                if (e->getCargo() == "Administracion"){
                    cargo= ADMINISTRACION;
                } else if (e->getCargo() == "Limpieza"){
                    cargo= LIMPIEZA;
                } else if(e->getCargo() == "Recepcion") {
                    cargo= RECEPCION;
                } else if(e->getCargo() == "Infraestructura") {
                     cargo= INFRAESTRUCTURA;
                } else {
                    cargo= SinCargo;
                }
                //DTEmpleado::DTEmpleado(string email, string nombre, string password, tipoCargo cargo, Hostal *nomHostal){
                DTEmpleado *aux = new DTEmpleado(e->getEmail(), e->getNombre() , e->getPassword(), cargo, e->getHostalTrabaja());
                res.insert(aux);
            } 
        }
    }

    return res;
};

Huesped* CtrlSistema::findHuesped(string nombre){
    map<string, Usuario*>::iterator it;
	it = this->coleccionUsuarios.find(nombre);
	Huesped *res = dynamic_cast<Huesped*>(it->second);
	return res;
}

void CtrlSistema::setNombre(string nombre){
    this->nombre = nombre;
};

void CtrlSistema::setEmail(string email){
    this->email = email;
};

void CtrlSistema::setContrasenia(string contrasenia){
    this->password = contrasenia;
};

void CtrlSistema::setCargo(tipoCargo cargo){
    this->cargo = cargo;
};

void CtrlSistema::setEsFinger(bool finger){
    this->esFinger = finger;
};


void CtrlSistema::seleccionarEmpleado(string email){
    map<string, Usuario*>::iterator it = this->coleccionUsuarios.find(email);
    Empleado* e = dynamic_cast<Empleado*>(it->second);
	this->empleadoSeleccionado = e;
};

Empleado* CtrlSistema::getEmpleado(){
    return this->empleadoSeleccionado;
}

Usuario* CtrlSistema::seleccionarUsuario(string nombre){
    Usuario *user = new Usuario();
    return user;
};

void CtrlSistema::asignarCargo(string nombre, tipoCargo cargo){}
	
Huesped* CtrlSistema::seleccionarHuesped(string email) {
	map<string, Usuario*>::iterator it= this->coleccionUsuarios.find(email);
    Huesped* h = dynamic_cast<Huesped*>(it->second);
	this->huespedSeleccionado = h;
    return huespedSeleccionado;
}

Huesped* CtrlSistema::getHuesped() {
  return this->huespedSeleccionado;
} 

Empleado* CtrlSistema::findEmpleado(string email){
    map<string,Usuario*>::iterator it = this->coleccionUsuarios.find(email);
    Empleado* e = dynamic_cast<Empleado*>(it->second);
    return e;
}


bool CtrlSistema::existeUsuario(){
    return (this->coleccionUsuarios.count(this->email) > 0);
};

void CtrlSistema::ingresarDatosUsuario(){
    bool tipoUsuarioInvalido;
    cout << "Indique si el usuario es un empleado (E) o un huesped (H): ";
    string tipoUsuario; 

    do {  
        cin >> tipoUsuario; 
        
        if (tipoUsuario == "E" || tipoUsuario == "e"){
            tipoUsuarioInvalido = false;

            bool cargoIngresoInvalido;
            string cargoIngreso;
            tipoCargo cargo;

            do {
                cout << "Indicar si el empleado pertenece al area de limpieza (L), administracion (A), recepcion (R) o infraestructua (I): ";
                cin >> cargoIngreso;

                if (cargoIngreso == "L" || cargoIngreso == "l"){
                    cargoIngresoInvalido = false;
                    cargo = LIMPIEZA;

                } else if (cargoIngreso == "A" || cargoIngreso == "a"){
                    cargoIngresoInvalido = false;
                    cargo = ADMINISTRACION;

                } else if (cargoIngreso == "R" || cargoIngreso == "r"){
                    cargoIngresoInvalido = false;
                    cargo = RECEPCION;

                } else if (cargoIngreso == "I" || cargoIngreso == "i"){
                    cargoIngresoInvalido = false;
                    cargo = INFRAESTRUCTURA;

                } else {
                    cargoIngresoInvalido = true;
                    cout << "Se ha ingresado un valor invalido, por favor intentelo nuevamente"<< endl;

                }
            } while (cargoIngresoInvalido);       

            this->cargo = cargo;

        } else if (tipoUsuario == "H" || tipoUsuario == "h"){
            tipoUsuarioInvalido = false;
            
            cout << "Si el usuario es finger ingrese (S), si no lo es ingrese (N): ";
            string ingresoEsFinger;
            bool ingresoEsFingerInvalido;
            bool esFinger;

            do {
                cin >> ingresoEsFinger;

                if (ingresoEsFinger == "S" || ingresoEsFinger == "s"){
                    ingresoEsFingerInvalido = false;
                    esFinger = true;

                } else if (ingresoEsFinger == "N" || ingresoEsFinger == "n"){
                    ingresoEsFingerInvalido = false;
                    esFinger = false;

                } else {
                    ingresoEsFingerInvalido = true;
                    cout << "Se ha ingresado un valor invalido. Si el usuario es finger ingrese (S), si no lo es ingrese (N): ";
                }
                
            } while (ingresoEsFingerInvalido);

            this->esFinger = esFinger;

        } else {
            tipoUsuarioInvalido = true;
            cout << "Se ha ingresado un valor invalido, por favor indique si el usuario es un empleado (E) o un huesped (H)" << endl;

        }
    } while (tipoUsuarioInvalido);
}

void CtrlSistema::actualizarEmailUsuario(string email){
    this->email = email;
}

void CtrlSistema::confirmarAltaUsuario(){
    if (this->cargo == SinCargo){
        Huesped *nuevoHuesped = new Huesped(this->email, this->nombre, this->password, this->esFinger);
        this->coleccionUsuarios.insert({this->email, nuevoHuesped});
    } else {
        Empleado *nuevoEmpleado = new Empleado(this->email, this->nombre, this->password, this->cargo, NULL);
        this->coleccionUsuarios.insert({this->email, nuevoEmpleado});
    }

    cout << "Se ha dado de alta el usuario exitosamente\n";

    this->nombre = "";
    this->email = "";
    this->password = "";
    this->cargo = SinCargo;
    this->esFinger = false;
}

void CtrlSistema::cancelarAltaIngreso(){
    cout << "Se ha cancelado el ingreso del usuario\n";
    
    this->nombre = "";
    this->email = "";
    this->password = "";
    this->cargo = SinCargo;
    this->esFinger = false;
}

void CtrlSistema::imprimirUsuarios(){ //imprime solo los nombres de los usuarios
    
    map<string,Usuario*> usuarios =this->coleccionUsuarios; //coleccion de usuarios
    map<string,Usuario*> :: iterator itU; 

    map<string, Empleado*> empleados;
    map<string, Empleado*>::iterator itER;

    map<string, Huesped*> huespedes;
    map<string, Huesped*>::iterator it;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (Empleado* e = dynamic_cast<Empleado*>(itU->second)){
            empleados.insert({e->getEmail(), e});
        } else {
            Huesped* h = dynamic_cast<Huesped*>(itU->second);
            huespedes.insert({h->getEmail(), h});
        }
    }

    cout << "---------------------Listado de huespedes registrados en el sistema----------------------------" << endl;
    for (it = huespedes.begin(); it != huespedes.end(); it++){
    Huesped *hueAux = it->second;
    DTHuesped *aux = new DTHuesped(hueAux->getNombre(), hueAux->getEmail(), hueAux->getEsFinger());
    cout << "-Nombre del huesped: " << aux->getNombre() << endl;
    cout << "-Email: " << aux->getEmail() << endl;
    delete(aux);
    }


     cout << "---------------------Listado de empleados registrados en el sistema----------------------------" << endl;
    for (itER = empleados.begin(); itER != empleados.end(); itER++){
    Empleado *empAux = itER->second;
    string nomhos;
    cout << "-Nombre del empleado: " << empAux->getNombre() << endl;
    cout << "-Email: " << empAux->getEmail() << endl;
    }
}



void CtrlSistema::obtenerInfoUsuario(string rol, string email){
    if(rol=="H"){
        Huesped* h =findHuesped(email);
        DTHuesped * aux = new DTHuesped(h->getNombre(),h->getEmail(),h->getEsFinger());
        cout << "-Nombre del empleado: " << aux->getNombre() << endl;
        cout << "-Email: " << aux->getEmail() << endl;
        if (aux->getEsFinger())
            cout << "-Es Finger: Si" << endl;
        else
            cout << "-Es Finger: No" << endl;
    } else {
        Empleado* e =findEmpleado(email);
        Hostal* h = e->getHostalTrabaja();

        cout << "-Nombre del empleado: " << e->getNombre() << endl;
        cout << "-Email: " << e->getEmail() << endl;
        cout << "-Cargo: " << e->getCargo() << endl;
        if (h==NULL)
            cout << "-Hotel donde trabaja: aun no se le asigna un hostal" << endl;
        else 
            cout << "-Hotel donde trabaja: " << h->getNombre() << endl;
    }
}

bool CtrlSistema::obtenerEsFinger(){
        return true;
}

void CtrlSistema::obtenerInfoEmpleado(){}

Empleado* CtrlSistema::obtenerEmpleado(){
    return NULL;
}

void CtrlSistema::obtenerEmpleados(string nomHostal){}

void CtrlSistema::obtenerReservasHuesped(string email){}

void CtrlSistema::obtenerHuespedes(){

    map<string,Usuario*> usuarios =this->coleccionUsuarios; //coleccion de usuarios
    map<string,Usuario*> :: iterator itU; 

    map<string, Huesped*> huespedes;
    map<string, Huesped*>::iterator it;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (Huesped* h = dynamic_cast<Huesped*>(itU->second)){
            huespedes.insert({h->getEmail(), h});
        }
    }

     cout << "---------------------Listado de usuarios registrados en el sistema----------------------------" << endl;
    for (it = huespedes.begin(); it != huespedes.end(); it++){
        Huesped *hueAux = it->second;
        DTHuesped *aux = new DTHuesped(hueAux->getNombre(), hueAux->getEmail(), hueAux->getEsFinger());
        cout << "-Nombre del huesped: " << aux->getNombre() << endl;
        cout << "-Email: " << aux->getEmail() << endl;
        cout << "-Es finger: " << aux->getEsFinger() << endl;
        cout << "-------------" << endl;
        delete(aux);
    }
}

void CtrlSistema::obtenerUsuarios(){}

void CtrlSistema::imprimirTodaLaInfoDeUsuarios(){
    map<string,Usuario*> usuarios = this->coleccionUsuarios; //coleccion de usuarios
    map<string,Usuario*> :: iterator itU; 

 // cout << "--------------------------------------------------------" << endl;
    cout << "-                                                      -" << endl;
    cout << "-------------------- HUESPEDES -------------------------" << endl;
    cout << endl;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (Huesped* h = dynamic_cast<Huesped*>(itU->second)){
            cout << "-Nombre del huesped: " << h->getNombre() << endl;
            cout << "-Email: " << h->getEmail() << endl;
            cout << "-Es finger: ";
            if (h->getEsFinger() == 1){
              cout << "Si" << endl;
            } else {
                cout << "No" << endl;
            }
            cout << "-Contrasenia: " << h->getPassword() << endl;

            cout << "--------------------------------- " << endl;
        }
    }

    cout << "-                                                      -" << endl;
    cout << "-------------------- EMPLEADOS -------------------------" << endl;
    cout << endl;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (Empleado* e = dynamic_cast<Empleado*>(itU->second)){
            cout << "-Nombre del empleado: " << e->getNombre() << endl;
            cout << "-Email: " << e->getEmail() << endl;
            cout << "-Contrasenia: " << e->getPassword() << endl;
            cout << "-Cargo: " << e->getCargo() << endl;
            if (e->getHostalTrabaja() ==NULL)
                cout << "-Hostal donde trabaja: aun no se le asigna un hostal" << endl;
            else 
                cout << "-Hostal donde trabaja: " << e->getHostalTrabaja()->getNombre() << endl;

            cout << "--------------------------------- " << endl;
        }
    }
}




void CtrlSistema::obtenerEmpleados(){

    map<string,Usuario*> usuarios =this->coleccionUsuarios; //coleccion de usuarios
    map<string,Usuario*> :: iterator itU; 

    map<string, Empleado*> empleados;
    map<string, Empleado*>::iterator it;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (Empleado* e = dynamic_cast<Empleado*>(itU->second)){
            empleados.insert({e->getEmail(), e});
        }
    }

    for (it = empleados.begin(); it != empleados.end(); it++){
        Empleado *empAux = it->second;
        cout<< "-Nombre: "<< empAux->getNombre() << endl;
        cout<< "-Email: "<< empAux->getEmail() << endl;
        cout << "----------------------------"<< endl;
    }//for
}

