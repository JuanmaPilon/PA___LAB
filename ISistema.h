#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <string>
using namespace std;
#include "TipoCargo.h"
#include "EstadoReserva.h"
#include "DTFecha.h"

class ISistema{
private:

public:

void IngresarDatosEmpleado(string nombre, string email, string contrasenia, tipoCargo cargo);
void IngresarDatosHuesped(string nombre, string email, string contrasenia, bool esFinger);
void confirmarAltaUsuario();
void ingresarDatos(string nombre, string direccion, string telefono);
void altaHostal();
void listarHostalesRegistrados();
void seleccionarHostal(string nombre);
void ingresarDatosHabitacion(int numero, int precio, int capacidad);
void altaHabitacion();
void listaEmpleadosSinAsignar();
void seleccionarEmpleado(string email);
void ConfirmarAsignacion();
void seleccionarHostal(string nombre, DTFecha checkIn, DTFecha checkOut);
void seleccionarHabitacion(int numero);
void seleccionarHuesped(string email);
void seleccionarHuespedesGrupal(string email);
void confirmarReserva();
void listarTopHostales();
void seleccionarTopHostales(string nombre);
void VerReservaHuesped(string email);
void registrarEstadia(string codigoReserva);
void ingresoHuesped(string email, string);
void ingresoHuespedS(string email, string);
void FinalizaEstadia();
void seleccionarEstadiaFinalizada(string estadia);
void AltaCalificacion(string comentario, int numeroCalificacion, DTFecha fechaCali);
void ingresoEmpleado(string email);
void responderComentario(string respuestas);
void listarHuespedes();
void listarEmpleados();
void seleccionarUser(string nombre);
void mostrarDatosEsFinger();
void MostrarDatoEmpleado();
void MostrarTrabajaEnHostal();
void listarHabitacion();
void mostrarReservas();
void listarHostalesRegistrados();
void seleccionarHostal();
void seleccionarHuesped(string email);
void seleccionarEstadia(string codigo);
void listarCalificacion();
void listarRespuesta();
void listarReservas();
void seleccionarReserva(string codigo);
void eliminarReserva();
void seleccionarHostal(string nombre);
void modificarFechaSistema(DTFecha fecha);
void cancelar();
};
#endif