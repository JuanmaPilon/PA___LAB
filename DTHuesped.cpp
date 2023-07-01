#include "DTHuesped.h"
#include <iostream>
#include <string>
#include <istream>
#include <ios>
using namespace std;

  DTHuesped::DTHuesped(string nombre, string email, bool esFinger){
    this->nombre=nombre;
    this->email=email;
    this->esFinger=esFinger;
  } // constructor
  string DTHuesped::getNombre(){
    return this->nombre;
  }

  string DTHuesped::getEmail(){
    return this->email;
  }

  bool DTHuesped::getEsFinger(){
    return this->esFinger;
  }

  DTHuesped::~DTHuesped(){}

  ostream &operator<<(ostream &os, DTHuesped &huesped){
	os << "Nombre: " << huesped.getNombre() << endl;
	os << "Email: " << huesped.getEmail() << endl;
	os << "Es Finger: " << huesped.getEsFinger() << endl;

	return os; 
}

