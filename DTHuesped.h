#ifndef DTHUESPED_H
#define DTHUESPED_H

#include <string>
using namespace std;

class DTHuesped
{
private:
  string nombre;
  string email;
  bool esFinger;

public:
  DTHuesped(string nombre, string email, bool esFinger);
  string getNombre();
  string getEmail();
  bool getEsFinger();
  ~DTHuesped();
};

#endif
