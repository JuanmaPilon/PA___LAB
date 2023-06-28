#include "CtrlSistema.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <istream>
#include <ios>
#include "DTHabitacion.h"
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

  //calificacion *calif = res->getCalificacion();
  //cout << "Calificacion de la estadia: "; 
  //if (calif != NULL){
    //cout << res->getCalificacion()->getCalificacion() << endl;
    //cout << "Comentario :" << res->getCalificacion()->getComentario() << endl;
    //cout << "Respuesta :" << res->getCalificacion()->getRespuesta() << endl;
  //} else 
   // cout << "No hay calificacion."<< endl;

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
    /*
    cout << "Primero:" << it->second->getReserva()->getHabitacion()->getHostal()->getNombre() << " and " << this->hostalSeleccionado->getNombre() << endl;
    cout << "Segundo:" << it->second->getHuesped()->getEmail() << " and " << email << endl;
    bool test = (it->second->getCheckOut() != NULL);
    if (test){
      cout << "Es true" << endl;
    }*/
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