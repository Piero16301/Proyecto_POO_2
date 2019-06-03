#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Juego.h"
#include "Partida.h"

using namespace std;

Partida juego_nuevo; //Se crea el objeto

int main() {
    fstream ranking("../ranking.txt",ios::out); //Se crea el archivo ranking
    juego_nuevo.crearRanking(); //Se abre el archivo ranking en el programa
    juego_nuevo.iniciarMatriz(); //Se inicializa la matriz
    while (1) {
        juego_nuevo.mostrarTablero(); //Imprime la matriz
        juego_nuevo.presionarTecla(); //Espera ingreso de movimiento o comando
        juego_nuevo.entradaComando(&juego_nuevo); //Ejecuta el movimiento
        juego_nuevo.verificarFinjuego(&juego_nuevo); //Verifica si la matriz está llena
    }
}