#ifndef PUESTO_H
#define PUESTO_H
#include <iostream>

using namespace std;

class puesto
{
    public:

        puesto() {}
        puesto(string id, string nom, string salario);

        string setid(string id);
        string getid();

        string setnom(string nom);
        string getnom();

        string setsalario(string salario);
        string getsalario();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void borrar();

        struct Puesto
        {
            char id[20];
            char nom[45];
            char salario[10];
        };

    protected:

    private:

        string id, nom, salario;
};
#endif // PUESTO_H
