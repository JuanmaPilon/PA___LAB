#include "CtrlSistema.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
CtrlSistema::CtrlSistema(){
}

CtrlSistema *CtrlSistema::instancia = NULL;

CtrlSistema *CtrlSistema::getInstancia()
{
	if (instancia == NULL)
		instancia = new CtrlSistema();
	return instancia;
};