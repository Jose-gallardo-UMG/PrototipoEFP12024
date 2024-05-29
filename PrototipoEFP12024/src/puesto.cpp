#include "puesto.h"
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

puesto::puesto(string id, string nom, string salario)
{
    this->id = id;
    this->nom = nom;
    this->salario = salario;
}

string puesto::setid(string id)
{
    this->id = id;
    return id;
}

string puesto::getid()
{
    return id;
}

string puesto::setnom(string nom)
{
    this->nom = nom;
    return nom;
}

string puesto::getnom()
{
    return nom;
}

string puesto::setsalario(string salario)
{
    this->salario = salario;
    return salario;
}

string puesto::getsalario()
{
    return salario;
}

void puesto::menu()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2017", "PUE");

    system("cls");
    int opc;
    char continuar;

    do
    {
      cout << "\n";
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   Catalogo de Puestos        |" << endl;
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
					cout<<" -> Deseas ingresar a otro puesto? (S/N): ";
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

void puesto::insertar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2018", "PUEI");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|        Agregar detalles del Puesto       |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    srand(time(NULL));
    Puesto puesto;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "puesto-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        puesto.id[i] = idString[i];
    }
    puesto.id[idString.length()] = '\0';

    cout<<"        -> Generando codigo del puesto: " << puesto.id<<endl;
    cin.ignore();

    cout<<"        -> Ingrese el nombre del puesto: ";
    cin.getline(puesto.nom, 45);

    cout<<"        -> Ingrese el salario del puesto: ";
    cin.getline(puesto.salario, 10);

    cout << "\n";
    cout<<"+---------------------------------------------------------+"<< endl;
    cout << "\n";

    ofstream archivo("Puesto.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&puesto), sizeof(puesto));
    archivo.close();
}

void puesto::desplegar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2019", "PUED");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|          Ver detalles del Puesto         |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Puesto.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada...";
        cout << "\n";
        return;
    }
        Puesto puesto;

        while (archivo.read(reinterpret_cast<char*>(&puesto), sizeof(Puesto)))
        {
            cout<<"       -> Codigo del puesto: "<< puesto.id << endl;
            cout<<"       -> Nombre del puesto: "<< puesto.nom << endl;
            cout<<"       -> Salario del puesto: "<< puesto.salario << endl;
            cout << "     +-----------------------------------------------+" << endl;
            cout << "\n";
        }

        archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void puesto::modificar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2020", "PUEM");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|      Modificar detalles del Puesto       |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    fstream archivo;
    string idPuest;
    bool encontrado = false;

    archivo.open("Puesto.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }
    cout << "       -> Ingrese el codigo del puesto: ";
    cin >> idPuest;

    Puesto puesto;

    while (archivo.read(reinterpret_cast<char*>(&puesto), sizeof(Puesto))) {
        if (puesto.id == idPuest) {
            encontrado = true;

            cout << "\n" << endl;
            cout << "           Puesto encontrado con exito!" << endl;
            cout << "\n" << endl;
            cout << "        -> Ingrese el codigo del puesto: ";
            cin >> puesto.id;
            cout << "        -> Ingrese el nombre del puesto: ";
            cin >> puesto.nom;
            cout<<"         -> Ingrese el salario del puesto: ";
            cin >> puesto.salario;
            cout << "\n" << endl;

            archivo.seekp(-static_cast<int>(sizeof(Puesto)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&puesto), sizeof(Puesto));
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "       -> No se encontró un puesto con el ID proporcionado." << endl;
        cout << "\n" << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void puesto::borrar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2021", "PUEB");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|        Eliminar detalles del Puesto      |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Puesto.dat", ios::binary);
    string idPuest;

	if(!archivo)
	{
		cout<<"       -> Error, no se encuentra informacion...";
		cout << "\n";
		return;
	}

	ofstream archivo2("Puesto2.dat", ios::binary);

	Puesto puesto;

    cout<<"       -> Ingrese el codigo del puesto: ";
    cin>>idPuest;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&puesto), sizeof(Puesto)))
		{
			if(puesto.id != idPuest)
			{
				archivo2.write(reinterpret_cast<const char*>(&puesto), sizeof(Puesto));
			}
			else
			{
			    resta = true;
			}

		}
		archivo.close();
		archivo2.close();

		remove("Puesto.dat");

		rename("Puesto2.dat","Puesto.dat");

		if (resta)
        {
        cout << "\n" << endl;
        cout << "       -> Puesto eliminado con exito." << endl;
        cout << "\n";
        }
        else
        {
        cout << "\n" << endl;
        cout << "       -> No se a podido encontrar el puesto" << endl;
        cout << "\n";
        }
}
