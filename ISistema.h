#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <string>
using namespace std;
#include "TipoCargo.h"
#include "EstadoReserva.h"
#include "DTFecha.h"
#include "Hostal.h"
#include "Habitacion.h"
#include "Estadia.h"
#include <map>
#include "Reserva.h"
#include "Usuario.h"
#include "Empleado.h"
#include "DTEmpleado.h"
#include "DTReserva.h"
class ISistema
{
private:
public:
    //////////////////////////////////////////////////////////todo lo de HOSTAL////////////////////////////////////////////////////////////////////
    virtual void confirmarAltaHostal(string nombre, string direccion, string telefono) = 0;
    virtual void imprimirCalificacionesSR(Hostal *hos) = 0;
    virtual void imprimirHabitaciones(Hostal *h) = 0;
    virtual bool existeEstadia(string email) = 0;
    virtual bool existeCalificacion(int id, string email, Hostal *hos) = 0;
    virtual bool existeHostal(string nombre) = 0;
    virtual void finalizarEstadia(string email) = 0;
    virtual bool estadiaValida(string email) = 0;
    virtual void obtenerHostales() = 0;
    virtual void seleccionarHostal(string nomHostal) = 0;

    virtual void imprimirEstadias(string nomHostal) = 0;
    virtual Habitacion *seleccionarHabitacion(int numero) = 0;
    virtual Hostal *getHostal() = 0;
    virtual void asignarEmpHostal() = 0;
    virtual Habitacion *getHabitacion(Hostal *hos, int num) = 0;
    virtual void imprimirlnfoEstadia(string nomHostal, string emailestadia, int cod) = 0;
    virtual Estadia *getEstadia() = 0;
    virtual void seleccionarEstadia(int cod, string email) = 0;
    virtual void obtenerTop3Hostales() = 0;
    virtual void obtenerDetallesHostal(Hostal *hos) = 0;
    virtual void confirmarAltaHabitacion() = 0;
    virtual void ingresaristarEstadiasFinalizadas(string emailUsuario) = 0;
    virtual void ingresarlnfoCalificacion(string mensaje, int calificacion) = 0;
    virtual void ingresarInformacionHabitacion(int num, float precio, int capacidad) = 0;
    virtual void altaCalificacion() = 0;
    virtual void listarEstadiasFinalizadas(string email) = 0;
    virtual void imprimirInfoBasicaHostal(Hostal *hos) = 0;

    virtual void agregarEstadia(string key, Estadia *est) = 0;

    /////////////////////////////////////////////////////////////////////////////////////////////todo lo de reserva//////////////////////////////////////////////////////////////////////////////
    virtual void setContadorReserva() = 0;
    virtual void obtenerReservas(Hostal *hos) = 0;
    virtual Reserva *seleccionarReserva(int codigo) = 0;
    virtual void eliminarReserva(int codigo, Hostal *hos) = 0;
    virtual Reserva *getReserva() = 0;
    virtual void cancelarReserva() = 0;
    virtual void confirmarReserva(Hostal *h, DTFecha *fechaCheckIn, DTFecha *fechaCheckOut, int tipoDeReserva, Habitacion *hab, Huesped *hue, std::map<std::string, Huesped *> coleccionHuespedReserva) = 0;
    virtual void ingresarInformacionReserva(DTFecha checkIN, DTFecha checkOUT, DTReserva *tipoReserva) = 0;
    virtual void obtenerReserva() = 0;
    virtual void obtenerReservasPorHostal(string nomHostal) = 0;
    virtual void habitacionDisponible(DTFecha *checkIn, DTFecha *checkOut, Hostal *h) = 0;
    virtual void imprimirReservasHuesped(Huesped *hues) = 0;
    ///////////////////////////////////////////////////////////////////todo lo de  usuario/////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void seleccionarEmpleado(string email) = 0;
    virtual Usuario *seleccionarUsuario(string email) = 0;
    virtual Huesped *seleccionarHuesped(string nombre) = 0;
    virtual void imprimirUsuarios() = 0;
    virtual void cancelarAltaIngreso() = 0;
    virtual Huesped *getHuesped() = 0;

    virtual void asignarCargo(string nombre, tipoCargo cargo) = 0;
    virtual void setCargo(tipoCargo) = 0;

    virtual Empleado *findEmpleado(string email) = 0;
    virtual Huesped *findHuesped(string nombre) = 0;
    virtual bool existeUsuario() = 0;
    virtual void ingresarDatosUsuario() = 0;
    virtual void actualizarEmailUsuario(string email) = 0;
    virtual void confirmarAltaUsuario() = 0;

    // opiti
    virtual void setHostalTrabaja(Hostal *hos) = 0;
    virtual set<DTEmpleado *> obtenerEmpleadosNoRegistrados(Hostal *hos) = 0;
    virtual void imprimirReservasHuesped(string emailHuesped) = 0;

    virtual void imprimirNotificaciones() = 0;

    // setters
    virtual void setNombre(string nombre) = 0;
    virtual void setEmail(string email) = 0;
    virtual void setContrasenia(string contrasenia) = 0;
    virtual void setEsFinger(bool finger) = 0;

    // OPERACIONES DONDE OBTENGO COSAS
    virtual Empleado *getEmpleado() = 0;
    virtual void obtenerInfoUsuario(string rol, string email) = 0;
    virtual bool obtenerEsFinger() = 0;
    virtual void obtenerInfoEmpleado() = 0;
    virtual Empleado *obtenerEmpleado() = 0;

    // OPERACIONES DONDE PRINTEO SETS DE COSITAS
    virtual void obtenerEmpleados(string nomHostal) = 0;
    virtual void obtenerEmpleados() = 0;
    virtual void obtenerReservasHuesped(string email) = 0;
    virtual void obtenerHuespedes() = 0;
    virtual void obtenerUsuarios() = 0;

    // IMPRIMIRINFO
    virtual void imprimirTodaLaInfoDeUsuarios() = 0;
};
#endif