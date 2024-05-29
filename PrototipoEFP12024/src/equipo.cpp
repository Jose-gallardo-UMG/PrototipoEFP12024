#include "equipo.h"
#include "bitacora.h"
#include "login.h"
#include "entrenador.h"
#include <entrenador.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

equipo::equipo(string id, string nom, string ide)
{
    this->id = id;
    this->nom = nom;
    this->ide = ide;
}

string equipo::setid(string id)
{
    this->id = id;
    return id;
}

string equipo::getid()
{
    return id;
}

string equipo::setnom(string nom)
{
    this->nom = nom;
    return nom;
}

string equipo::getnom()
{
    return nom;
}

string equipo::setide(string ide)
{
    this->ide = ide;
    return ide;
}

string equipo::getide()
{
    return ide;
}

void equipo::menu()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2007", "EQUI");

    system("cls");
    int opc;
    char continuar;

    do
    {
         cout << "\n";
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   Catalogo de Equipo         |" << endl;
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
					cout<<" -> Deseas ingresar a otro equipo? (S/N): ";
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

void equipo::insertar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2008", "EQUII");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|        Agregar detalles del Equipo       |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    srand(time(NULL));
    string cod;
    Equipo equipo;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "equipo-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        equipo.id[i] = idString[i];
    }
    equipo.id[idString.length()] = '\0';

    cout<<"        -> Generando codigo del equipo: " << equipo.id<<endl;
    cin.ignore();

    cout<<"        -> Ingrese el nombre del equipo: ";
    cin.getline(equipo.nom, 45);

    cout<<"        -> Ingrese el codigo del entrenador: ";
    cin >> cod;


    cout << "\n";
    cout<<"+---------------------------------------------------------+"<< endl;
    cout << "\n";

    ifstream archivo3("Entrenador.dat", ios::binary);
    Entrenador entrenador;

    while (archivo3.read(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador))) {
        if (entrenador.id == cod)
        {
            ofstream archivo("Equipo.dat", ios::binary | ios::app);
            archivo.write(reinterpret_cast<const char*>(&equipo), sizeof(Equipo));
            archivo.close();

        }else
        {
            cout << "        -> El codigo del entrenador no esta registrado." << endl;
            cout << "        -> No se a guardado ningun registro." << endl;
            cout << "\n" << endl;
        }
    }
}

void equipo::desplegar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2009", "EQUID");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|        Agregar detalles del Equipo       |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Equipo.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada...";
        cout << "\n";
        return;
    }
        Equipo equipo;

        while (archivo.read(reinterpret_cast<char*>(&equipo), sizeof(Equipo)))
        {
            cout<<"       -> Codigo del equipo: "<< equipo.id << endl;
            cout<<"       -> Nombre del equipo: "<< equipo.nom << endl;
            cout << "     +-----------------------------------------------+" << endl;
            cout << "\n";
        }

        archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void equipo::modificar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2010", "EQUIM");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|      Modificar detalles del Equipo       |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    fstream archivo;
    string idEquipo;
    bool encontrado = false;

    archivo.open("Equipo.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }
    cout << "       -> Ingrese el codigo del pais: ";
    cin >> idEquipo;

    Equipo equipo;

    while (archivo.read(reinterpret_cast<char*>(&equipo), sizeof(Equipo))) {
        if (equipo.id == idEquipo) {
            encontrado = true;

            cout << "\n" << endl;
            cout << "           Equipo encontrado con exito!" << endl;
            cout << "\n" << endl;

            cout << "        -> Ingrese el codigo del equipo: ";
            cin >> equipo.id;
            cout << "        -> Ingrese el nombre del equipo: ";
            cin >> equipo.nom;
            cout << "\n" << endl;

            archivo.seekp(-static_cast<int>(sizeof(Equipo)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&equipo), sizeof(Equipo));
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "       -> No se encontró un equipo con el ID proporcionado." << endl;
        cout << "\n" << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void equipo::borrar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2011", "EQUIB");

	cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|       Eliminar detalles del Equipo       |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Equipo.dat", ios::binary);
    string idEquipo;

	if(!archivo)
	{
		cout<<"       -> Error, no se encuentra informacion...";
		cout << "\n";
		return;
	}

	ofstream archivo2("equipo2.dat", ios::binary);

	Equipo equipo;

    cout<<"       -> Ingrese el codigo del equipo: ";
    cin>>idEquipo;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&equipo), sizeof(Equipo)))
		{
			if(equipo.id != idEquipo)
			{
				archivo2.write(reinterpret_cast<const char*>(&equipo), sizeof(Equipo));
			}
			else
			{
			    resta = true;
			}

		}
		archivo.close();
		archivo2.close();

		remove("Equipo.dat");

		rename("equipo2.dat","Equipo.dat");

		if (resta)
        {
        cout << "\n" << endl;
        cout << "       -> Equipo eliminado con exito." << endl;
        cout << "\n";
        }
        else
        {
        cout << "\n" << endl;
        cout << "       -> No se a podido encontrar al Equipo" << endl;
        cout << "\n";
        }
}
