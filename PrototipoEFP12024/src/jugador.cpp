#include "jugador.h"
#include "bitacora.h"
#include "login.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

jugador::jugador(string id, string nom)
{
    this->id = id;
    this->nom = nom;
}

string jugador::setid(string id)
{
    this->id = id;
    return id;
}

string jugador::getid()
{
    return id;
}

string jugador::setnom(string nom)
{
    this->nom = nom;
    return nom;
}

string jugador::getnom()
{
    return nom;
}

void jugador::menu()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2022", "JUG");

    system("cls");
    int opc;
    char continuar;

    do
    {
       cout << "\n";
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   Catalogo de Jugador        |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Insertar                   |" << endl;
        cout << "\t\t\t 2. Desplegar                  |" << endl;
        cout << "\t\t\t 3. Modificar                  |" << endl;
        cout << "\t\t\t 4. Borrar                     |" << endl;
        cout << "\t\t\t 5. Salir del programa         |" << endl;
        cout << "\t\t\t 6. Regresar al menu           |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
            system("cls");
            do
				{
					insertar();
					cout<<" -> Deseas ingresar a otro jugador? (S/N): ";
					cin>>continuar;
				}while(continuar=='S' || continuar=='s');
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            desplegar();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            modificar();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            borrar();
            system("pause");
            system("cls");
            break;
        case 5:
            exit(0);
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=6);
}

void jugador::insertar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2023", "JUGI");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|        Agregar detalles del Jugador      |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    srand(time(NULL));
    Jugador jugador;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "posi-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        jugador.id[i] = idString[i];
    }
    jugador.id[idString.length()] = '\0';

    cout<<"        -> Generando codigo del jugador: " << jugador.id<<endl;
    cin.ignore();

    cout<<"        -> Ingrese el nombre de su posicion: ";
    cin.getline(jugador.nom, 45);

    cout << "\n";
    cout<<"+---------------------------------------------------------+"<< endl;
    cout << "\n";

    ofstream archivo("Jugador.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&jugador), sizeof(jugador));
    archivo.close();
}

void jugador::desplegar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2024", "JUGD");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|          Ver detalles del Jugador        |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Jugador.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada...";
        cout << "\n";
        return;
    }
        Jugador jugador;

        while (archivo.read(reinterpret_cast<char*>(&jugador), sizeof(Jugador)))
        {
            cout<<"       -> Codigo del jugador: "<< jugador.id << endl;
            cout<<"       -> Posicion del jugador: "<< jugador.nom << endl;
            cout << "     +-----------------------------------------------+" << endl;
            cout << "\n";
        }

        archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void jugador::modificar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2025", "JUGM");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|      Modificar detalles del Jugador      |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    fstream archivo;
    string idJuga;
    bool encontrado = false;

    archivo.open("Jugador.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }
    cout << "       -> Ingrese el codigo del jugador: ";
    cin >> idJuga;

    Jugador jugador;

    while (archivo.read(reinterpret_cast<char*>(&jugador), sizeof(Jugador))) {
        if (jugador.id == idJuga) {
            encontrado = true;

            cout << "\n" << endl;
            cout << "           Jugador encontrado con exito!" << endl;
            cout << "\n" << endl;
            cout << "        -> Ingrese el codigo del jugador: ";
            cin >> jugador.id;
            cout << "        -> Ingrese el nombre de su posicion: ";
            cin >> jugador.nom;
            cout << "\n" << endl;

            archivo.seekp(-static_cast<int>(sizeof(Jugador)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&jugador), sizeof(Jugador));
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "       -> No se encontró un jugador con el ID proporcionado." << endl;
        cout << "\n" << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void jugador::borrar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2026", "JUGB");

	cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|       Eliminar detalles del Jugador      |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Jugador.dat", ios::binary);
    string idJuga;

	if(!archivo)
	{
		cout<<"       -> Error, no se encuentra informacion...";
		cout << "\n";
		return;
	}

	ofstream archivo2("Jugador2.dat", ios::binary);

	Jugador jugador;

    cout<<"       -> Ingrese el codigo del jugador: ";
    cin>>idJuga;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&jugador), sizeof(Jugador)))
		{
			if(jugador.id != idJuga)
			{
				archivo2.write(reinterpret_cast<const char*>(&jugador), sizeof(Jugador));
			}
			else
			{
			    resta = true;
			}

		}
		archivo.close();
		archivo2.close();

		remove("Jugador.dat");

		rename("Jugador2.dat","Jugador.dat");

		if (resta)
        {
        cout << "\n" << endl;
        cout << "       -> Jugador eliminado con exito." << endl;
        cout << "\n";
        }
        else
        {
        cout << "\n" << endl;
        cout << "       -> No se a podido encontrar al jugador" << endl;
        cout << "\n";
        }
}
