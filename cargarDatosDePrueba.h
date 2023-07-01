#include <string>
#include <iostream>
#include <iomanip>

#include "Fabrica.h"

#include "Usuario.h"
#include "Estadia.h"
#include "Reserva.h"
#include "Hostal.h"
#include "Habitacion.h"
#include "Empleado.h"
#include "Huesped.h"

using namespace std;

void cargarDatosDePrueba()
{
  Fabrica* fab = Fabrica::getInstance();
  ISistema* isistema = fab->getISistema();


  Empleado *E1, *E2, *E3, *E4;

  isistema->setNombre("Emilia");
  isistema->setEmail("emilia@mail.com");
  isistema->setContrasenia("123");
  isistema->setCargo(RECEPCION);
  isistema->confirmarAltaUsuario();
  E1 = isistema->findEmpleado("emilia@mail.com");

  isistema->setNombre("Leonardo");
  isistema->setEmail("leo@mail.com");
  isistema->setContrasenia("123");
  isistema->setCargo(RECEPCION);
  isistema->confirmarAltaUsuario();
  E2 = isistema->findEmpleado("leo@mail.com");

  isistema->setNombre("Alina");
  isistema->setEmail("alina@mail.com");
  isistema->setContrasenia("123");
  isistema->setCargo(ADMINISTRACION);
  isistema->confirmarAltaUsuario();
  E3 = isistema->findEmpleado("alina@mail.com");

  isistema->setNombre("Barliman");
  isistema->setEmail("barli@mail.com");
  isistema->setContrasenia("123");
  isistema->setCargo(RECEPCION);
  isistema->confirmarAltaUsuario();
  E4 = isistema->findEmpleado("barli@mail.com");

  Huesped *H1, *H2, *H3, *H4, *H5, *H6;

  isistema->setNombre("Sofia");
  isistema->setEmail("sofia@mail.com");
  isistema->setContrasenia("123");
  isistema->setEsFinger(true);
  isistema->confirmarAltaUsuario();
  H1 = isistema->findHuesped("sofia@mail.com");


  isistema->setNombre("Frodo");
  isistema->setEmail("frodo@mail.com");
  isistema->setContrasenia("123");
  isistema->setEsFinger(true);
  isistema->confirmarAltaUsuario();
  H2 = isistema->findHuesped("frodo@mail.com");


  isistema->setNombre("Sam");
  isistema->setEmail("sam@mail.com");
  isistema->setContrasenia("123");
  isistema->setEsFinger(false);
  isistema->confirmarAltaUsuario();
  H3 = isistema->findHuesped("sam@mail.com");


  isistema->setNombre("Merry");
  isistema->setEmail("merry@mail.com");
  isistema->setContrasenia("123");
  isistema->setEsFinger(false);
  isistema->confirmarAltaUsuario();
  H4 = isistema->findHuesped("merry@mail.com");


  isistema->setNombre("Pippin");
  isistema->setEmail("pippin@mail.com");
  isistema->setContrasenia("123");
  isistema->setEsFinger(false);
  isistema->confirmarAltaUsuario();
  H5 = isistema->findHuesped("pippin@mail.com");


  isistema->setNombre("Seba");
  isistema->setEmail("seba@mail.com");
  isistema->setContrasenia("123");
  isistema->setEsFinger(true);
  isistema->confirmarAltaUsuario();
  H6 = isistema->findHuesped("seba@mail.com");
  
  
  Hostal *HO1, *HO2, *HO3, *HO4, *HO5;

  isistema->confirmarAltaHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");
  isistema->seleccionarHostal("La posada del finger");
  HO1 = isistema->getHostal();

  isistema->confirmarAltaHostal("Mochileros", "Rambla Costanera 333, Rocha", "42579512");
  isistema->seleccionarHostal("Mochileros");
  HO2 = isistema->getHostal();

  isistema->confirmarAltaHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");
  isistema->seleccionarHostal("El Pony Pisador");
  HO3 = isistema->getHostal();

  isistema->confirmarAltaHostal("Altos de Fing", "Av del Toro 1424", "099892992");
  isistema->seleccionarHostal("Altos de Fing");
  HO4 = isistema->getHostal();

  isistema->confirmarAltaHostal("Caverna Lujosa", "Amaya 2515", "233233235");
  isistema->seleccionarHostal("Caverna Lujosa");
  HO5 = isistema->getHostal();


  Habitacion *HAB1 ,*HAB2, *HAB3, *HAB4, *HAB5, *HAB6;


  isistema->seleccionarHostal(HO1->getNombre());
  isistema->ingresarInformacionHabitacion(1, 40, 2);
  isistema->confirmarAltaHabitacion();
  HAB1 = isistema->getHabitacion(HO1, 1);

  isistema->seleccionarHostal(HO1->getNombre());
  isistema->ingresarInformacionHabitacion(2, 10, 7);
  isistema->confirmarAltaHabitacion();
  HAB2 = isistema->getHabitacion(HO1, 2);

  isistema->seleccionarHostal(HO1->getNombre());
  isistema->ingresarInformacionHabitacion(3, 30, 3);
  isistema->confirmarAltaHabitacion();
  HAB3 = isistema->getHabitacion(HO1, 3);


  isistema->seleccionarHostal(HO1->getNombre());
  isistema->ingresarInformacionHabitacion(4, 5, 12);
  isistema->confirmarAltaHabitacion();
  HAB4 = isistema->getHabitacion(HO1, 4);


  isistema->seleccionarHostal(HO5->getNombre());
  isistema->ingresarInformacionHabitacion(1, 3, 2);
  isistema->confirmarAltaHabitacion();
  HAB5 = isistema->getHabitacion(HO5, 1);


  isistema->seleccionarHostal(HO3->getNombre());
  isistema->ingresarInformacionHabitacion(1, 9, 5);
  isistema->confirmarAltaHabitacion();
  HAB6 = isistema->getHabitacion(HO3, 1);


  E1->setHostalTrabaja(HO1);
  E2->setHostalTrabaja(HO2);
  E3->setHostalTrabaja(HO2);
  E4->setHostalTrabaja(HO3);


  Reserva *R1, *R2, *R3, *R4; 


  
  string emailH1 = "sofia@mail.com";
  string emailH2 = "frodo@mail.com";
  string emailH3 = "sam@mail.com";
  string emailH4 = "merry@mail.com";
  string emailH5 = "pippin@mail.com";
  string emailH6 = "seba@mail.com";

  
  DTFecha *fechaInR1 = new DTFecha(01,05,2022,14,00);
  DTFecha *fechaOutR1 = new DTFecha(10,05,2022,10,00);
  DTFecha *fechaInR2 = new DTFecha(04,01,2001,20,00);
  DTFecha *fechaOutR2 = new DTFecha(05,01,2001,02,00);
  DTFecha *fechaInR3 = new DTFecha(07,06,2022,14,00);
  DTFecha *fechaOutR3 = new DTFecha(30,06,2022,11,00);
  DTFecha *fechaInR4 = new DTFecha(10,06,2022,14,00);
  DTFecha *fechaOutR4 = new DTFecha(30,06,2022,11,00);
  map<string, Huesped*> huespedNull;
  huespedNull.begin() = huespedNull.end();

  map<string, Huesped*> huespedes;
  huespedes.insert({emailH2,H2});
  huespedes.insert({emailH3,H3});
  huespedes.insert({emailH4,H4});
  huespedes.insert({emailH5,H5});

  map<string, Huesped*>::iterator it;


  isistema->confirmarReserva(HO1,fechaInR1,fechaOutR1,0,HAB1,H1,huespedNull);
  R1 = isistema->seleccionarReserva(1);
  isistema->confirmarReserva(HO3,fechaInR2,fechaOutR2,1,HAB6,NULL,huespedes);
  R2 = isistema->seleccionarReserva(2);
  isistema->confirmarReserva(HO1,fechaInR3,fechaOutR3,0,HAB3,H1,huespedNull);
  R3 = isistema->seleccionarReserva(3);
  isistema->confirmarReserva(HO5,fechaInR4,fechaOutR4,0,HAB5,H6,huespedNull);
  R4 = isistema->seleccionarReserva(4);


  //Estadias (ref, reserva, huesped, check in)


DTFecha *fecha1 = new DTFecha(01,05,2022,18,00);
DTFecha *fecha2 = new DTFecha(04,01,2001,21,00);
DTFecha *fecha6 = new DTFecha(07,06,2022,18,00);
DTFecha *fecha7 = new DTFecha(10,05,2022,9,00);
DTFecha *fecha8 = new DTFecha(5,01,2001,2,00);
DTFecha *fecha9 = new DTFecha(15,06,2022,10,00);


Estadia *ES1 = new Estadia(fecha1, fecha7, R1, H1);
HO1->agregarEstadia(to_string(R1->getCodigo()) + H1->getEmail(), ES1);

Estadia *ES2 = new Estadia(fecha2, fecha8, R2, H2);
HO3->agregarEstadia(to_string(R2->getCodigo()) + H2->getEmail(), ES2);

Estadia *ES3 = new Estadia(fecha2, NULL, R2, H3);
HO3->agregarEstadia(to_string(R2->getCodigo()) + H3->getEmail(), ES3);

Estadia *ES4 = new Estadia(fecha2, NULL, R2, H4);
HO3->agregarEstadia(to_string(R2->getCodigo()) + H4->getEmail(), ES4);

Estadia *ES5 = new Estadia(fecha2, NULL, R2, H5);
HO3->agregarEstadia(to_string(R2->getCodigo()) + H5->getEmail(), ES5);

Estadia *ES6 = new Estadia(fecha6, fecha8, R4, H6);
HO5->agregarEstadia(to_string(R4->getCodigo()) + H6->getEmail(), ES6);


}
