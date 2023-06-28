#include "CtrlSistema.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <istream>
#include <ios>
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

Hostal *controladorHostal::getHostal()
{
  return this->hostalSeleccionado;
} // COMPLETAR

void controladorHostal::asignarEmpHostal() {} // COMPLETAR

habitacion *controladorHostal::getHabitacion(hostal *hos, int num)
{
  map<int, habitacion *> h = hos->getColeccionHabitaciones();
  map<int, habitacion *>::iterator iterador = h.find(num);
  return (iterador->second);
}

habitacion *controladorHostal::seleccionarHabitacion(int numero)
{
  return NULL;
}

void controladorHostal::imprimirlnfoEstadia(string nomHostal, string emailestadia, int cod)
{
  map<string, hostal *>::iterator iter = this->coleccionHostales.find(nomHostal);
  hostal *elhostal = iter->second;

  map<string, estadia *> estadias = elhostal->getColeccionEstadia();
  map<string, estadia *>::iterator it = estadias.find(to_string(cod) + emailestadia);

  string PROMO;
  int quiere;

  estadia *res = it->second;
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

  huesped *hue = res->getHuesped();
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
    if (reservaAsociada->getEstado() == Abierta){
      estado = "Abierta";
    } else if (reservaAsociada->getEstado()== Cerrada){
      estado = "Cerrada";
    } else if (reservaAsociada->getEstado() == Cancelada){
      estado = "Cancelada";
    }

    cout << "Estado de la reserva: " << estado << endl;
    cout << "Numero de habitacion: " << reservaAsociada->getHabitacion()->getNumero()<< endl;
  }
}

void controladorHostal::imprimirHabitaciones(hostal *h)
{
  map<int, habitacion *> habitaciones = h->getColeccionHabitaciones();
  map<int, habitacion *>::iterator it;

  cout << "---------------------Listado de habitaciones disponibles----------------------------" << endl;
  for (it = habitaciones.begin(); it != habitaciones.end(); it++)
  {
    habitacion *habAux = it->second;
    DTHabitacion *aux = new DTHabitacion(habAux->getNumero(), habAux->getPrecio(), habAux->getCapacidad());
    cout << "-Numero de habitacion: " << aux->getNumero() << endl;
    cout << "-Precio: " << aux->getPrecio() << endl;
    cout << "-Capacidad: " << aux->getCapacidad() << endl;
    cout << "-------------" << endl;
    delete (aux);
  }
}

estadia *controladorHostal::getEstadia()
{
  return this->estadiaSeleccionada;
} // COMPLETAR

void controladorHostal::seleccionarEstadia(int cod, string email)
{
  map<string, estadia *>::iterator iterador = hostalSeleccionado->getColeccionEstadia().find(to_string(cod) + email);
  estadia *res = iterador->second;
  this->estadiaSeleccionada = res;
}

void controladorHostal::imprimirInfoBasicaHostal(hostal *hos)
{
  cout << "-Nombre del hostal: " << hos->getNombre() << endl;
  cout << "-Direccion: " << hos->getDireccion() << endl;
  cout << "-Telefono: " << hos->getTelefono() << endl;
  cout << "-------------" << endl;
};

void controladorHostal::confirmarAltaHabitacion(){
  habitacion *hab = new habitacion(this->numeroHabitacion, this->precioHabitacion, this->capacidadHabitacion);
  this->hostalSeleccionado->agregarHabitacion(numeroHabitacion, hab);
  hab->setHostalHabitacion(this->hostalSeleccionado);

  this->numeroHabitacion = 0;
  this->precioHabitacion = 0;
  this->capacidadHabitacion = 0;
  this->hostalSeleccionado = NULL;

} // COMPLETAR

void controladorHostal::agregarEstadia(string key, estadia* est){
  this->hostalSeleccionado->agregarEstadia(key, est);
  this->hostalSeleccionado = NULL;
}


void controladorHostal::ingresaristarEstadiasFinalizadas(string emailUsuario) {} // COMPLETAR



void controladorHostal::ingresarInformacionHabitacion(int num, float precio, int capacidad)
{
  this->numeroHabitacion = num;
  this->precioHabitacion = precio;
  this->capacidadHabitacion = capacidad;
}


void controladorHostal::listarEstadiasFinalizadas(string email){
  map<string, hostal *>::iterator it2 = this->coleccionHostales.find(this->hostalSeleccionado->getNombre());
  hostal *elHostal = it2->second;
  cout << "Hostal seleccionado: " << elHostal->getNombre() << endl;
  map<string, estadia *> estad = elHostal->getColeccionEstadia();
  map<string, estadia *>::iterator it;

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
      estadia *est = it->second;
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

void controladorHostal::agregarObservador(IObserver *o){
  observers.insert(o);
}

void controladorHostal::eliminarObservador(IObserver *o){
  observers.erase(o);
}

void controladorHostal::notificarObservadores(calificacion *cal){
  set<IObserver *>::iterator it;
  for (it = observers.begin(); it != observers.end(); ++it){
    IObserver* papa = *it;
    papa->getNombresito();
    cout << "ya mande";
    papa->notify(cal);
  }
}

void controladorHostal::imprimirEstadias(string nomHostal){ // imprime todas las estadias (no la info)

  map<string, hostal *>::iterator iter = this->coleccionHostales.find(nomHostal);
  hostal *elhostal = iter->second;
  map<string, estadia *> estadias = elhostal->getColeccionEstadia();
  map<string, estadia *>::iterator it;
  cout << "---------------------Listado de estadias del hostal----------------------------" << endl;
  for (it = estadias.begin(); it != estadias.end(); it++)
  {
    cout << "Estadia: " << it->second->getHuesped()->getEmail();
    cout << "     Codigo de reserva: " << it->second->getReserva()->getCodigo() << endl;
  }
}