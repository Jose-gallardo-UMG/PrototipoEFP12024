#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>

using namespace std;

class jugador
{
    public:

        jugador() {}
        jugador(string id, string nom);

        string setid(string id);
        string getid();

        string setnom(string nom);
        string getnom();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void borrar();

        struct Jugador
        {
            char id[20];
            char nom[45];
        };

    protected:

    private:

        string id, nom;
};

#endif // JUGADOR_H
