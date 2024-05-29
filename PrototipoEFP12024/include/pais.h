#ifndef PAIS_H
#define PAIS_H
#include <iostream>

using namespace std;

class pais
{
    public:

        pais() {}
        pais(string id, string nom);

        string setid(string id);
        string getid();

        string setnom(string nom);
        string getnom();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void borrar();

        struct Pais
        {
            char id[20];
            char nom[45];
        };

    protected:

    private:

        string id, nom;
};

#endif // PAIS_H
