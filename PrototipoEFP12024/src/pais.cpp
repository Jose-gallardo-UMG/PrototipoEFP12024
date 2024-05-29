#include "pais.h"
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

pais::pais(string id, string nom)
{
    this->id = id;
    this->nom = nom;
}

string pais::setid(string id)
{
    this->id = id;
    return id;
}

string pais::getid()
{
    return id;
}

string pais::setnom(string nom)
{
    this->nom = nom;
    return nom;
}

string pais::getnom()
{
    return nom;
}

void pais::menu()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2012", "PAIZ");

    system("cls");
    int opc;
    char continuar;

    do
    {
        cout << "\n";
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   Catalogo de Pais           |" << endl;
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
					cout<<" -> Deseas ingresar a otro pais? (S/N): ";
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

void pais::insertar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2013", "PAIZI");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|        Agregar detalles del Pais         |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    srand(time(NULL));
    Pais pais;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "pais-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        pais.id[i] = idString[i];
    }
    pais.id[idString.length()] = '\0';

    cout<<"        -> Generando codigo del pais: " << pais.id<<endl;
    cin.ignore();

    cout<<"        -> Ingrese el nombre del pais: ";
    cin.getline(pais.nom, 45);

    cout << "\n";
    cout<<"+---------------------------------------------------------+"<< endl;
    cout << "\n";

    ofstream archivo("Pais.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&pais), sizeof(pais));
    archivo.close();

}

void pais::desplegar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2014", "PAIZD");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|          Ver detalles del Pais           |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Pais.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada...";
        cout << "\n";
        return;
    }
        Pais pais;

        while (archivo.read(reinterpret_cast<char*>(&pais), sizeof(Pais)))
        {
            cout<<"       -> Codigo del pais: "<< pais.id << endl;
            cout<<"       -> Nombre del pais: "<< pais.nom << endl;
            cout << "     +-----------------------------------------------+" << endl;
            cout << "\n";
        }

        archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void pais::modificar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2015", "PAIZM");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|      Modificar detalles del Pais         |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    fstream archivo;
    string idPais;
    bool encontrado = false;

    archivo.open("Pais.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }
    cout << "       -> Ingrese el codigo del pais: ";
    cin >> idPais;

    Pais pais;

    while (archivo.read(reinterpret_cast<char*>(&pais), sizeof(Pais))) {
        if (pais.id == idPais) {
            encontrado = true;

            cout << "\n" << endl;
            cout << "           Pais encontrado con exito!" << endl;
            cout << "\n" << endl;
            cout << "        -> Ingrese el codigo del pais: ";
            cin >> pais.id;
            cout << "        -> Ingrese el nombre del pais: ";
            cin >> pais.nom;
            cout << "\n" << endl;

            archivo.seekp(-static_cast<int>(sizeof(Pais)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&pais), sizeof(Pais));
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "       -> No se encontró un pais con el ID proporcionado." << endl;
        cout << "\n" << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();

}

void pais::borrar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2016", "PAIZB");

	cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|       Eliminar detalles del Pais         |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Pais.dat", ios::binary);
    string idPais;

	if(!archivo)
	{
		cout<<"       -> Error, no se encuentra informacion...";
		cout << "\n";
		return;
	}

	ofstream archivo2("pais2.dat", ios::binary);

	Pais pais;

    cout<<"       -> Ingrese el codigo del pais: ";
    cin>>idPais;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&pais), sizeof(Pais)))
		{
			if(pais.id != idPais)
			{
				archivo2.write(reinterpret_cast<const char*>(&pais), sizeof(Pais));
			}
			else
			{
			    resta = true;
			}

		}
		archivo.close();
		archivo2.close();

		remove("Pais.dat");

		rename("pais2.dat","Pais.dat");

		if (resta)
        {
        cout << "\n" << endl;
        cout << "       -> Pais eliminado con exito." << endl;
        cout << "\n";
        }
        else
        {
        cout << "\n" << endl;
        cout << "       -> No se a podido encontrar el pais" << endl;
        cout << "\n";
        }
}
