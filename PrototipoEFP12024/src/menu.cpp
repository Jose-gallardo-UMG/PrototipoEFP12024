#include "menu.h"
#include "entrenador.h"
#include "equipo.h"
#include "jugador.h"
#include "pais.h"
#include "puesto.h"
#include "usuarios.h"
#include "Bitacora.h"
#include "Result.h"
#include "Login.h"
#include <iostream>
#include <windows.h>
#include <resultados.h>
#include <reportbit.h>
using namespace std;

menu::menu()
{
    //ctor
}

void menu::MenuGeneral()
{
    system("cls");
    int opc;
    reportbit reportes;

    do
    {
        cout << "\n";
        cout << "\t+----------------------------------------------------+" << endl;
        cout << "\t|                                                    |" << endl;
        cout << "\t|Jose Eduardo Gallardo Del Cid    9959-23-106        |" << endl;
        cout << "\t|                                                    |" << endl;
        cout << "\t+----------------------------------------------------+" << endl;
        cout << "\t|                   Menu general                     |" << endl;
        cout << "\t|                                                    |" << endl;
        cout << "\t+----------------------------------------------------+" << endl;
        cout << "\t|                                                    |" << endl;
        cout << "\t|1. Catalogos                                        |" << endl;
        cout << "\t|                                                    |" << endl;
        cout << "\t|2. Informes                                         |" << endl;
        cout << "\t|                                                    |" << endl;
        cout << "\t|3. Seguridad                                         |" << endl;
        cout << "\t|                                                    |" << endl;
        cout << "\t|4. Salir del Programa                               |" << endl;
        cout << "\t|                                                    |" << endl;
        cout << "\t+----------------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
            system("cls");
            Catalogos();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            Procesos();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            reportes.Reportes();
            system("pause");
            system("cls");
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=4);
}

void menu::Catalogos()
{
    system("cls");
    int opc;

    do
    {
        cout << "\n";
        cout << "\t\t\t+-------------------------------+" << endl;
        cout << "\t\t\t|     Menu de Catalogos         |" << endl;
        cout << "\t\t\t+-------------------------------+" << endl;
        cout << "\t\t\t| 1. Peliculas                 |" << endl;
        cout << "\t\t\t| 6. Usuarios                   |" << endl;
        cout << "\t\t\t| 7. Regresar al Menu           |" << endl;
        cout << "\t\t\t| 8. Salir del Programa         |" << endl;
        cout << "\t\t\t+-------------------------------+" << endl;
        cout << "\n" << endl;

        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
        {
            entrenador entrena;
            entrena.menu();
        }
            break;
        case 2:
        {
            usuarios usu;
            usu.menu();
        }
            break;
        case 3:
        {
            MenuGeneral();
        }
            break;
        case 4:
         {
            exit(0);
            break;
        }
            break;

        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=8);
}

void menu::Procesos()
{
     system("cls");
    int opc;

    do
    {
        system("cls");
        cout << "\t\t\t+--------------------------------+" << endl;
        cout << "\t\t\t|   Submenu Procesos             |"<< endl;
        cout << "\t\t\t+--------------------------------+" << endl;
        cout << "\t\t\t| 1. Resultados                  |" << endl;
        cout << "\t\t\t| 2. Bitacora                    |" << endl;
        cout << "\t\t\t| 3. Salir                       |" << endl;
        cout << "\t\t\t+--------------------------------+" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3]        |" << endl;
        cout << "\t\t\t+--------------------------------+" << endl;
        cout << "\t\t\tSeleccione una opcion: ";
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
             {
                 Result resultados;
                 resultados.Marcador();

                break;
            }
        case 2:
            {
                Bitacora bitacora;
                bitacora.mostrarBitacora();
                break;
            }
        case 3:
            MenuGeneral();
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=3);
}
