#include "reportbit.h"
#include "menu.h"
#include "entrenador.h"
#include "equipo.h"
#include "jugador.h"
#include "pais.h"
#include "puesto.h"
#include "usuarios.h"
#include "Bitacora.h"
#include "Login.h"
#include <iostream>
#include <windows.h>
#include <resultados.h>

reportbit::reportbit()
{

}
void reportbit::Reportes()
{
     system("cls");
    Bitacora bitacora; // Creamos un objeto Bitacora

    int opcion;
    string usuario;

    do {
        cout << "\t\t\t+-------------------------------+" << endl;
        cout << "\t\t\t|   Submenu Reportes            |"<< endl;
        cout << "\t\t\t+-------------------------------+" << endl;
        cout << "\t\t\t| 1. Generar reporte completo   |" << endl;
        cout << "\t\t\t| 2. Generar reporte por usuario|" << endl;
        cout << "\t\t\t| 3. Salir                      |" << endl;
        cout << "\t\t\t+-------------------------------+" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3]       |" << endl;
        cout << "\t\t\t+-------------------------------+" << endl;
        cout << "\t\t\tSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                 system("cls");
                bitacora.generarReporteCompleto(); // Llamamos al método para generar reporte completo
                break;
            case 2:
                 system("cls");
                cout << "Ingrese el nombre de usuario para generar el reporte: ";
                cin >> usuario;
                bitacora.generarReportePorUsuario(usuario); // Llamamos al método para generar reporte por usuario
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcion != 3);
}
