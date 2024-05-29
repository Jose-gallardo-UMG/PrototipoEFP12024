#include "Result.h"
#include "login.h"
#include "equipo.h"
#include "Bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include <ctime>
#include<iomanip>
#include<string>

using namespace std;

Result::Result()
{
    //ctor
}

void Result::Marcador() {
    system("cls");
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2004", "ENTRED");
      // Obtener la fecha actual
    time_t now = time(0);
    tm *ltm = localtime(&now);

	cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|       Ver detalles del Partido           |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Equipo.dat", ios::binary | ios::in);
    if (!archivo) {
        cout << "No hay informacion registrada...";
        cout << "\n";
        return;
    }

    Equipo equipo1, equipo2;
    int partido = 1;

    // Inicializar la semilla de los n�meros aleatorios
    srand(static_cast<unsigned>(time(nullptr)));

    while (archivo.read(reinterpret_cast<char*>(&equipo1), sizeof(Equipo))) {
        if (!archivo.read(reinterpret_cast<char*>(&equipo2), sizeof(Equipo))) {
            cout << "N�mero impar de equipos, no se puede emparejar el �ltimo equipo." << endl;
            break;
        }
        int golesEquipo1 = rand() % 5; // Generar un n�mero aleatorio de goles para el equipo 1 (m�ximo 4)
        int golesEquipo2 = rand() % 5; // Generar un n�mero aleatorio de goles para el equipo 2 (m�ximo 4)
        char fecha[20];
        strftime(fecha, sizeof(fecha), "%d/%m/%Y", ltm);

        cout << " Partido " << partido++ << " (" << fecha << "): " << equipo1.nom << " " << golesEquipo1 << " - " << golesEquipo2 << " " << equipo2.nom << endl;
    }

    archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
