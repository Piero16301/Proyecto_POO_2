#include "Ranking.h"

void imprimirRanking(str nombreArchivo, std::fstream &objArchivo, std::ios_base::openmode modoArchivo){
    objArchivo.open(nombreArchivo,modoArchivo);
    if(!objArchivo.is_open()){
        std::cout << "Error al imprimir el archivo del ranking";
        exit(EXIT_FAILURE);
    }
}