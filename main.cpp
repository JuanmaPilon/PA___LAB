#include "Fabrica.h"
#include "cargarDatosDePrueba.h"
#include "ISistema.h"
#include <iostream>
#include <istream>
#include <ios>
#include <map>
#include <set>
#include <limits>

using namespace std;

int main()
{

	bool flag = false;
	while (!flag)
	{
		int numingresado;
		cout << "\nBienvenido. Elija la opcion.\n\n";
		cout << "1. Alta de Usuario\n";
		cout << "2. Alta de Hostal\n";
		cout << "3. Alta de Habitacion\n";
		cout << "4. Asignar Empleado a Hostal\n";
		cout << "5. Realizar Reserva\n";
		cout << "6. Registrar Estadia\n";
		cout << "7. Finalizar Estadia\n";
		cout << "8. Consulta de Usuario\n";
		cout << "9. Consulta de Hostal\n";
		cout << "10. Consulta de Reserva\n";
		cout << "11. Consulta de Estadia\n";
		cout << "12. Modificar fecha del Sistema\n";
		cout << "13. Cargar datos de prueba\n";
		cout << "0. Salir\n\n";
		cout << "Opcion:";

		while (flag == false)
		{
			cin >> numingresado;
			if (!cin.good())
			{
				cout << "ERROR\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
				cout << "Ingrese un numero valido\n";
			}
			else
				flag = true;
		}
		flag = false;

		switch (numingresado)
		{
		case 1: // Alta de Usuario
		{

			Fabrica *fab = Fabrica::getInstance();	 // Llamo a la instancia de la fabrica
			ISistema *isistema = fab->getISistema(); // Llamo a la interfaz de sistema

			cout << "Ingrese un nombre: ";
			string nombre;
			cin.ignore();
			getline(cin, nombre);

			cout << "Ingrese un email: ";
			string email;
			getline(cin, email);

			cout << "Ingrese una contrasenia: ";
			string password;
			getline(cin, password);

			isistema->setNombre(nombre);
			isistema->setEmail(email);
			isistema->setContrasenia(password);

			isistema->ingresarDatosUsuario();
			bool existeUsuario = isistema->existeUsuario();

			if (existeUsuario)
			{
				do
				{
					cout << "Se ha encontrado un usuario en el sistema con el correo electronico ingresado, ingrese otro correo electronico para el usuario: ";
					string email;
					cin >> email;
					isistema->actualizarEmailUsuario(email);

					existeUsuario = isistema->existeUsuario();
				} while (existeUsuario);
			}

			cout << " Desea confirmar y dar de alta al usuario? Ingrese (S) para confirmar el ingreso o cualquier otro caracter para cancelarlo: ";
			string confirmar;
			cin >> confirmar;

			if (confirmar == "S" || confirmar == "s")
			{
				isistema->confirmarAltaUsuario();
			}
			else
			{
				isistema->cancelarAltaIngreso();
				cout << "Se ha cancelado el alta del usuario" << endl;
			}
		}
		break;

		case 2: // Alta de Hostal
		{
			Fabrica *fab = Fabrica::getInstance();	 // llamo a la instancia de la fabrica
			ISistema *isistema = fab->getISistema(); // llamo a la interfaz de sistema

			string nombre, direccion, telefono;
			cout << "Ingrese nombre del hostal a crear: ";
			cin.ignore();
			getline(cin, nombre);

			while (isistema->existeHostal(nombre))
			{
				int a = 0;
				cout << "Error, ya existe un hostal con ese nombre, desea volver a intentar?" << endl;
				cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
				cin >> a;
				if (a == 0)
					break;
				else
				{
					cout << "Ingrese nombre del hostal a crear: ";
					cin.ignore();
					getline(cin, nombre);
				}
			}

			cout << "Ingrese direccion del hostal a crear: ";
			getline(cin, direccion);
			cout << "Ingrese telefono del hostal a crear: ";
			getline(cin, telefono);

			isistema->confirmarAltaHostal(nombre, direccion, telefono);
		}
		break;

		case 3: // Alta de Habitacion
		{
			Fabrica *fab = Fabrica::getInstance();	 // llamo a la instancia de la fabrica
			ISistema *isistema = fab->getISistema(); // llamo a la interfaz de sistema

			isistema->obtenerHostales();

			string nomHostal;
			cout << "Seleccione un hostal ingresando su nombre: ";
			cin.ignore();
			getline(cin, nomHostal);

			try
			{
				while (!(isistema->existeHostalThrow(nomHostal)))
				{
					int a = 0;
					cout << "Error, no existe un hostal con ese nombre, desea volver a intentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
					if (a == 0)
						break;
					else
					{
						cout << "Ingrese nombre del hostal: ";
						cin.ignore();
						getline(cin, nomHostal);
					}
				}

				isistema->seleccionarHostal(nomHostal);

				int num, capacidad;
				float precio;

				cout << "Ingrese el numero de la habitacion: ";
				cin >> num;

				cout << "Ingrese la capacidad de la habitacion: ";
				cin >> capacidad;

				cout << "Ingrese el precio de la habitacion: ";
				cin >> precio;

				isistema->ingresarInformacionHabitacion(num, precio, capacidad);
				isistema->confirmarAltaHabitacion();
			}
			catch (const std::exception &e)
			{
				cout << "Error: " << e.what() << endl;
			}
		}
		break;

		case 4: // Asignar Empleado a Hostal
		{
			Fabrica *fab = Fabrica::getInstance(); // llamo a la instancia de la fabrica
			ISistema *isistema = fab->getISistema();

			string nombreHostal, emailEmpleado, confirmar;
			bool seguir = true;

			isistema->obtenerHostales();

			cout << "Ingrese el nombre del hostal al cual desee asignar un empleado: ";
			cin.ignore();
			getline(cin, nombreHostal);

			isistema->seleccionarHostal(nombreHostal);
			Hostal *h = isistema->getHostal();

			while (seguir == true)
			{

				set<DTEmpleado *> empleados = isistema->obtenerEmpleadosNoRegistrados(h);
				set<DTEmpleado *>::iterator it;

				if (!empleados.empty())
				{

					cout << "--- EMPLEADOS DISPONIBLES PARA ASIGNAR-- " << endl;

					for (it = empleados.begin(); it != empleados.end(); it++)
					{
						DTEmpleado *aux = *it;
						cout << "-Nombre: " << aux->getNombre() << endl;
						cout << "-Email: " << aux->getEmail() << endl;
						cout << "-----------" << endl;
					}

					cout << "Ingrese el email del empleado al que quiere asignar: ";
					getline(cin, emailEmpleado);
					Empleado *emp = isistema->findEmpleado(emailEmpleado);

					cout << "Desea confirmar y realizar la asignacion? Ingrese (S) para confirmar el ingreso o cualquier otro caracter para cancelarlo\n";
					cin >> confirmar;
					if (confirmar == "S" || confirmar == "s")
					{
						emp->setHostalTrabaja(h);
						cout << "Se ha asignado al empleado exitosamente\n";
					}
					else
					{
						cout << "Se ha cancelado la asignacion\n";
					}
					cout << "-------------\n";
					cout << "Desea realizar otra asignacion? Ingrese (S) para confirmar el ingreso o cualquier otro caracter para cancelarlo\n";
					cin >> confirmar;
					cout << "'" << confirmar << "'" << endl;
					if (confirmar != "S" && confirmar != "s")
					{
						seguir = false;
					}
				}
				else
				{

					cout << "--------------- " << endl;
					cout << "No hay empleados sin asignar en este hostal" << endl;
					seguir = false;
				}
			}
		}
		break;

		case 5: // Realizar reserva
		{
			Fabrica *fab = Fabrica::getInstance();	 // Llamo a la instancia de la fabrica
			ISistema *isistema = fab->getISistema(); // Llamo a la interfaz de sistema

			map<string, Huesped *> coleccionHuespedReserva;

			string nombreH, email;
			int anio, mes, dia, hora, minuto, tipoDeReserva, numero, cantidadH, confirmar;

			isistema->obtenerHostales();
			cout << "Ingrese el nombre del hostal seleccionado: ";
			cin.ignore();
			getline(cin, nombreH);
			try
			{
				while (!(isistema->existeHostalThrow(nombreH)))
				{
					int a = 0;
					cout << "Error, no existe un hostal con ese nombre, desea volver a intentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
					if (a == 0)
						break;
					else
					{
						cout << "Ingrese nombre del hostal: ";
						cin.ignore();
						getline(cin, nombreH);
					}
				}

				isistema->seleccionarHostal(nombreH);
				Hostal *h = isistema->getHostal();

				cout << "Ingrese la fecha de check In:" << endl;
				cout << "Ingrese anio: ";
				cin >> anio;
				cout << "Ingrese mes: ";
				cin >> mes;
				cout << "Ingrese dia: ";
				cin >> dia;
				cout << "Ingrese hora: ";
				cin >> hora;
				cout << "Ingrese minuto: ";
				cin >> minuto;
				DTFecha *fechaCheckIn = new DTFecha(dia, mes, anio, hora, minuto);

				cout << "Ingrese la fecha de check Out:" << endl;
				cout << "Ingrese anio: ";
				cin >> anio;
				cout << "Ingrese mes: ";
				cin >> mes;
				cout << "Ingrese dia: ";
				cin >> dia;
				cout << "Ingrese hora: ";
				cin >> hora;
				cout << "Ingrese minuto: ";
				cin >> minuto;
				DTFecha *fechaCheckOut = new DTFecha(dia, mes, anio, hora, minuto);

				cout << "ingrese si la reserva sera grupal o individual (Individual = 0, Grupal = 1): ";
				cin >> tipoDeReserva;

				isistema->habitacionDisponible(fechaCheckIn, fechaCheckOut, h);

				cout << "Ingrese el numero de la habitacion seleccionada: ";
				cout << "---------------------------" << endl;

				cin >> numero;
				Habitacion *hab = isistema->getHabitacion(h, numero);

				isistema->obtenerHuespedes();
				cout << "Ingrese el email del huesped que realizara la reserva: ";
				cin.ignore();
				getline(cin, email);

				isistema->seleccionarHuesped(email);
				Huesped *hue = isistema->getHuesped();
				coleccionHuespedReserva.insert({email, hue});

				if (tipoDeReserva == 1)
				{ // Si la reserva es grupal
					cout << "Ingrese la cantidad de huespedes que se hospedaran con usted: ";
					cin >> cantidadH;
					cin.ignore();

					for (int i = 0; i < cantidadH; i++)
					{
						cout << "Ingrese el nombre del nuevo huesped: ";
						getline(cin, email);

						isistema->seleccionarHuesped(email);
						Huesped *hues = isistema->getHuesped();

						coleccionHuespedReserva.insert({email, hues});
					};
				}
				cout << "Desea confirmar la reserva? (Si = 1, No = 0): ";
				cin >> confirmar;

				if (confirmar == 1)
				{
					isistema->confirmarReserva(h, fechaCheckIn, fechaCheckOut, tipoDeReserva, hab, hue, coleccionHuespedReserva);
				}
			}
			catch (const std::exception &e)
			{
				cout << "Error: " << e.what() << endl;
			}
		}
		break;

		case 6: // Registrar Estadia
		{
			Fabrica *fab = Fabrica::getInstance();	 // llamo a la instancia de la fabrica
			ISistema *isistema = fab->getISistema(); // Llamo a la interfaz de sistema

			string nombreHostal, emailHuesped;
			int codReserva;

			isistema->obtenerHostales();

			cout << "Ingrese el nombre del hostal al cual desea registrarle una estadia" << endl;
			cin.ignore();
			getline(cin, nombreHostal);
			cout << "Nombre del hostal: " << nombreHostal << endl;
			isistema->seleccionarHostal(nombreHostal);
			Hostal *h = isistema->getHostal();

			cout << "Ingrese el email del huesped que quiere registrar una estadia" << endl;
			getline(cin, emailHuesped);
			cout << "email del huesped: " << emailHuesped << endl;
			isistema->seleccionarHuesped(emailHuesped);
			Huesped *hue = isistema->getHuesped();

			isistema->imprimirReservasHuesped(hue);

			cout << "Ingrese el id de la reserva sobre la cual registrara la estadia" << endl;
			cin >> codReserva;

			Reloj *r = Reloj::getInstancia();
			Estadia *est = new Estadia(r->getReloj(), NULL, isistema->seleccionarReserva(codReserva), hue);
			string key = to_string(codReserva) + emailHuesped;
			isistema->agregarEstadia(key, est);
			h->agregarEstadia(to_string(codReserva) + emailHuesped, est);
		}
		break;

		case 7: // Finalizar Estadia
		{
			Fabrica *fab = Fabrica::getInstance();
			ISistema *isistema = fab->getISistema();

			string hostal, email;
			cout << "A continuacion, se listan los hostales registrados" << endl;
			isistema->obtenerHostales();
			cout << "Por favor, ingrese el nombre del hostal seleccionado: ";
			cin.ignore();
			getline(cin, hostal);
			isistema->seleccionarHostal(hostal);
			cout << "Ingrese el email del huesped: ";
			getline(cin, email);
			bool seguir = true;

			while (!(isistema->existeEstadia(email) && isistema->estadiaValida(email)) && (seguir))
			{
				int a = 0;

				if (isistema->existeEstadia(email))
				{
					cout << "Error, no existe una estadia valida asociada a ese email, desea volver a intentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
				}
				else
				{
					cout << "Error, la estadia asociada a ese email ya ha finalizado, desea volver a intentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
				}
				if (a == 0)
					seguir = false;
				else
				{
					cout << "Ingrese el email del huesped: ";
					cin >> email;
				}
			}
			if (seguir)
			{
				isistema->finalizarEstadia(email);
			}
		}
		break;

		case 8: // Consulta de Usuario
		{
			Fabrica *fab = Fabrica::getInstance();
			ISistema *isistema = fab->getISistema();
			string rol, email;
			isistema->imprimirUsuarios();

			cout << "Ingrese si el usuario es huesped(H), empleado(E) o cualquier otra letra para salir" << endl;
			cin.ignore();
			getline(cin, rol);
			if ((rol != "E") && (rol != "H"))
			{
				break;
			}
			cout << "Ingrese el email del usuario sobre el cual desea consultar" << endl;
			getline(cin, email);

			try
			{
				isistema->obtenerInfoUsuario(rol, email);
			}
			catch (const std::exception &e)
			{
				cout << "Error: " << e.what() << endl;
			}
		}
		break;

		case 9: // Consulta de Hostal
		{
			Fabrica *fab = Fabrica::getInstance();
			ISistema *isistema = fab->getISistema();

			string hostalSeleccionado;
			isistema->obtenerHostales();
			cout << "Listado de hostales, por favor seleccione uno ingresando su nombre: " << endl;
			cin.ignore();
			getline(cin, hostalSeleccionado);
			isistema->seleccionarHostal(hostalSeleccionado);
			isistema->imprimirInfoBasicaHostal(isistema->getHostal());
			isistema->imprimirHabitaciones(isistema->getHostal());
			isistema->obtenerReservasPorHostal(hostalSeleccionado);
		}
		break;

		case 10: // Consulta de reserva
		{
			Fabrica *fab = Fabrica::getInstance();
			ISistema *isistema = fab->getISistema();

			isistema->obtenerHostales();

			string nomHostal;
			cout << "Seleccione un hostal ingresando su nombre: ";
			cin.ignore();
			getline(cin, nomHostal);
			try
			{
				while (!(isistema->existeHostalThrow(nomHostal)))
				{
					int a = 0;
					cout << "Error, no existe un hostal con ese nombre, desea volver a intentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
					if (a == 0)
						break;
					else
					{
						cout << "Ingrese nombre del hostal: ";
						cin.ignore();
						getline(cin, nomHostal);
					}
				}
			}
			catch (const std::exception &e)
			{
				cout << "Error: " << e.what() << endl;
			}

			isistema->seleccionarHostal(nomHostal);
			isistema->obtenerReservasPorHostal(nomHostal);
		}
		break;

		case 11: // Consulta de Estadia
		{
			Fabrica *fab = Fabrica::getInstance();
			ISistema *isistema = fab->getISistema();

			string nomHostal, emailestadia;
			isistema->obtenerHostales();
			cout << "Escriba el nombre del hostal que desea consultar" << endl;
			cin.ignore();
			getline(cin, nomHostal);
			if (isistema->existeHostal(nomHostal))
				isistema->imprimirEstadias(nomHostal);
			else
				break;
			cout << "Seleccione una de las estadias, ingresando el mail asociado a ella" << endl;
			getline(cin, emailestadia);
			int cod;
			cout << "Ingrese el codigo de la reserva" << endl;
			cin >> cod;
			isistema->imprimirlnfoEstadia(nomHostal, emailestadia, cod);
		}
		break;

		case 12: // Modificar fecha del Sistema
		{
			Reloj *fechaSistema = Reloj::getInstancia();

			int anio;
			bool existe = false;
			int a = 0;
			while (!existe)
			{
				cout << "Ingrese el anio: ";
				cin >> anio;
				if (anio >= 1900)
				{
					existe = true;
				}
				else
				{
					cout << "Error, el anio no es acorde, desea reintentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
					existe = !(a == 1);
					if (existe)
						break;
				}
			};
			int mes;
			existe = false;
			while (!existe)
			{
				cout << "Ingrese el mes: ";
				cin >> mes;
				if (mes > 0 && mes < 13)
				{
					existe = true;
				}
				else
				{
					cout << "Error, el mes no es acorde, desea reintentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
					existe = !(a == 1);
					if (existe)
						break;
				}
			};

			int dia;
			existe = false;
			while (!existe)
			{
				cout << "Ingrese el dia: ";
				cin >> dia;
				if (dia > 0 && dia < 32)
				{
					existe = true;
				}
				else
				{
					cout << "Error, el dia no es acorde, desea reintentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
					existe = !(a == 1);
					if (existe)
						break;
				}
			};

			int hora;
			existe = false;
			while (!existe)
			{
				cout << "Ingrese la hora: ";
				cin >> hora;
				if (hora >= 0 && hora < 24)
				{
					existe = true;
				}
				else
				{
					cout << "Error, la hora no es acorde, desea reintentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
					existe = !(a == 1);
					if (existe)
						break;
				}
			};

			int minuto;
			existe = false;
			while (!existe)
			{
				cout << "Ingrese el minuto: ";
				cin >> minuto;
				if (minuto >= 0 && minuto < 60)
				{
					existe = true;
				}
				else
				{
					cout << "Error, el minuto no es acorde, desea reintentar?" << endl;
					cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
					cin >> a;
					existe = !(a == 1);
					if (existe)
						break;
				}
			};

			fechaSistema->setReloj(dia, mes, anio, hora, minuto);
			cout << "Fecha y Hora ingresada: " << dia << "/" << mes << "/" << anio << " " << hora << ":" << minuto << endl;
		}
		break;

		case 13: // Cargar datos de prueba
		{
			cargarDatosDePrueba();
		}
		break;

		case 0:
		{
			cout << "Hasta luego.\n";
			flag = true;
		}
		break;

		default:
			cout << "Ingrese un numero del 0 al 13\n";
			break;
			return 0;
		}
	}
}
