#ifndef PROYECTO_2_POO_I_JUEGO_H
#define PROYECTO_2_POO_I_JUEGO_H

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#include "MiMatriz.h"

using namespace std;
using TipoDato = int;

class Partida;

class Juego {

private:
    int estado;
    int fin;
    char movimiento;

protected:
    int maximo;
    int ganador;
    int suma;
    int puntaje;
    int matriz_actual[4][4];
    int matriz_backup[4][4];
    int matriz_temp[4][4];

    string sugerencia();
    void intercambio(bool n);
public:
    Juego(): puntaje(0),suma(0),ganador(2048),maximo(0),estado(0),fin(1) {}
    void entradaComando(Partida*);
    void verificarFinjuego(Partida*);
    void presionarTecla();
    void iniciarMatriz();
    void actualizarMatriz();
    void llenarCasilla();
    void generar();
    void buscarCasillamayor();
    void hacerBackup();
    void deshacer();

    int saturado();
    int movimientoBloque();

    friend int contarcero(int n[][4]);
};


#endif //PROYECTO_2_POO_I_JUEGO_H
