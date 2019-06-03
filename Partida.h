#ifndef PROYECTO_2_POO_I_PARTIDA_H
#define PROYECTO_2_POO_I_PARTIDA_H

#include "Juego.h"
#include <fstream>

class Partida : public Juego {

private:
    char opcion;
    string nombre;
    std::fstream Ranking;

public:
    Partida(){};
    void mostrarTablero();
    void mostrarPantalla_Instrucciones();
    void mostrarPantalla_Ganador();
    void mostrarPantalla_Perdedor();
    char mostrarPantalla_Volveraintentar(int perdido);
    void crearRanking();
};

#endif //PROYECTO_2_POO_I_PARTIDA_H