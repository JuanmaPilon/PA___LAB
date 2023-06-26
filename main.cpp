#include "Fabrica.h"
#include <iostream>
#include <istream>
#include <ios>
#include <map>
#include <set>

using namespace std;



int main()
{
	
	bool flag = false;
	while (!flag)
	{
		//bool retroceder = false;
		int  numingresado;
		cout << "\nBienvenido. Elija la opción.\n\n";
        cout << "1. Alta de Usuario\n";
        cout << "2. Alta de Hostal\n";
        cout << "3. Alta de Habitacion\n";
		cout << "4. Asignar Empleado a Hostal\n";
		cout << "5. Realizar Reserva\n";
		cout << "6. Registrar Estadía\n";
		cout << "7. Finalizar Estadía\n";
		cout << "8. Consulta de Usuario\n";
		cout << "9. Consulta de Hostal\n";
		cout << "10. Consulta de Reserva\n";
		cout << "11. Consulta de Estadía\n";
		cout << "12. Modificar fecha del Sistema\n";
		cout << "13. Cargar datos de prueba\n";
        cout << "0. Salir\n\n";
        cout << "Opción:";

		while (flag == false)
        {
					cin >> numingresado;
					if(!cin.good())
					{
					  cout << "ERROR\n";
					  cin.clear();
					  cout << "Ingrese un número válido\n";
					}
                    else flag = true;
        }
		flag = false;
		
        switch (numingresado)
        {
            case 1: //Alta de Usuario
			{
				
			

			}
			break ; 

			case 2: //Alta de Hostal
			{
					
			}
			break ;  

			case 3: //Alta de Habitación
			{
					

			}
			break ;

			case 4: //Asignar Empleado a Hostal
           	{
                  	
  			  
            }
            break;

			case 5: //Realizar reserva
           	{
					
			}
            break;

			case 6: //Registrar Estadía
           	{
					cout << "Hasta luego.\n";
                	
            }
            break;

			case 7: //Finalizar Estadía
           	{
		           	
            }
            break;

			case 8: //Consulta de Usuario
           	{
					
                	
            }
            break;

			case 9: //Consulta de Hostal
           	{
					
                	
            }
            break;

			case 10: //Consulta de reserva
           	{
					
                	
            }
            break;

			case 11: //Consulta de Estadía
           	{
                        
   					       
             	
            }
            break;

			case 12 : //Modificar fecha del Sistema
			{	
					
			}
			break ; 

			case 13: //Cargar datos de prueba
            {
           		   	
            }
			break ; 
			
			case 0:
           	{
                cout << "Hasta luego.\n";
                flag = true;
            }
            break;
            	
			default:
            cout << "Ingrese un número del 0 al 13\n";
                

		return 0;
		}
	}
}