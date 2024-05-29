#ifndef RESULTADOS_H
#define RESULTADOS_H

#include "equipo.h"
#include <string>
#include "resultados.h"

class Resultados
{
public:
    Resultados(equipo equipo1, equipo equipo2, std::string fecha, int marcador1, int marcador2);

    equipo getEquipo1() const;
    equipo getEquipo2() const;
    std::string getFecha() const;
    int getMarcador1() const;
    int getMarcador2() const;

    void setEquipo1(const equipo& equipo1);
    void setEquipo2(const equipo& equipo2);
    void setFecha(const std::string& fecha);
    void setMarcador1(int marcador1);
    void setMarcador2(int marcador2);

    void mostrarResultado1() const;

private:
    equipo equipo1;
    equipo equipo2;
    std::string fecha;
    int marcador1;
    int marcador2;
};

#endif // RESULTADOS_H
