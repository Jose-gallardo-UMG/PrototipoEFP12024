#ifndef EQUIPO2_H
#define EQUIPO2_H
#include <iostream>
using namespace std;

 struct Entrenador
        {
            char id[20];
            char nom1[45];
            char nom2[45];
            char ape1[45];
            char ape2[45];
            char fechan[45];
        };


class equipo2
{
    public:

        equipo2() {}
        equipo2(string id, string nom, string ide);

        string setid(string id);
        string getid();

        string setnom(string nom);
        string getnom();

        string setide(string ide);
        string getide();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void borrar();

        struct Equipo
        {
            char id[20];
            char nom[45];
            char ide[20];
        };

    protected:

    private:
        string id, nom, ide;
};

#endif // EQUIPO2_H
