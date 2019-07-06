#include <iomanip>
#include "Partida.h"
#include "Ranking.h"

void Partida::mostrarTablero() { //Muestra el tablero
    system("clear"); //Limpia la pantalla

    cout << "\n\t     ------------------------------------------------------" << endl;
    cout << "\t     ---------------------  2048 GAME ---------------------" << endl;
    cout << "\t     ------------------------------------------------------" << endl << endl;

    cout << "\n\n";
    for(int i=0;i<4;i++){ //Imprime la matriz con los separadores |
        cout << "\t\t       ";
        for(int j=0;j<4;j++){
            if(matriz_actual[i][j]){ //Si la casilla es un numero diferente de 0 lo imprime
                cout << setw(7) << matriz_actual[i][j];
            }
            else{ //Si no solo imprime un espacio en blanco
                cout << setw(7) << 0;
            }
        }
        cout << "\n\n";
    }

    cout << "\n\t\t\t\t   PUNTAJE: " << puntaje << "\n\n\n"; //Imprime el puntaje al centro

    cout << "\t\t\t\t\t\t\ti - Instrucciones" << "\n";
    cout << "Sugerencia: " << sugerencia() << endl;

}

void Partida::mostrarPantalla_Instrucciones() { //Pantalla de instrucciones
    system("clear"); //Limpia la pantalla
    cout << "\n\t\t\t  Instrucciones de comandos\n\n"; //Comandos
    cout << "- Use 'b' para deshacer jugada y 'q' para salir.\n\n"; //Comandos principales
    cout << "\n\t\t\t  Instrucciones del juego 2048"; //Título
    char instrucciones[] = "- Al comienzo del juego aparecen dos numeros en el tablero de 4x4.- Estos números pueden ser un 4 o un 2.- Usa las teclas W, A, S, D para mover las casillas.- Cuando dos casillas con el mismo número esten juntas, se sumarán, y juntas, formarán una sola casilla.- Después de cada movimiento aparecerán nuevas casillas de 2 o 4 de manera aleatoria.- Para ganar el juego debes llegar hasta la casilla 2048, sin que el tablero se sature.- Presiona ENTER para continuar..."; //Instrucciones
    for(int i=0;instrucciones[i];i++){ //Recorre el array de caracteres
        if(instrucciones[i] == '-'){ //Si encuentra un quion (-)
            cout << "\n\n"; //Imprime dos saltos de linea
        }
        cout << instrucciones[i]; //Imprime las instrucciones en si
    }
}

void Partida::mostrarPantalla_Ganador() { //Pantalla de ganador
    system("clear"); //Limpia la pantalla
    cout << "\n\n";
    cout << "\t\t\t\t ¡FELICIDADES!"; //Titulo
    cout << "\n\n\n\t\t\t     LLEGASTE A LA CASILLA " << ganador << "\n\n\n"; //Imprime la casilla de ganador
    cout << "\t\t\t       HAS GANADO EL JUEGO" << "\n\n\n";
    cout << "\t\t\t PUNTAJE \t\t NOMBRE\n\n\n";
    printf("\t\t       %6d \t\t\t ",puntaje); //Imprime su puntaje
    Ranking << "\t\t   " << puntaje << "\t"; //Imprime el puntaje en el archivo
    getline(cin, nombre); //Pide ingresar el nombre
    Ranking << "\t     " << nombre; //Imprime el nombre en el archivo
    Ranking << "\t\t\t GANADOR\n"; //Imprime el estado de ganador en el archivo
}

void Partida::mostrarPantalla_Perdedor() { //Pantalla de Game over
    system("clear"); //Limpia la pantalla
    cout << "\n\t\t\t\t    GAME OVER\n\n\n"; //Imprime Game over
    cout << "\t\t\t PUNTAJE \t\t NOMBRE\n\n";
    printf("\t\t       %6d \t\t\t ",puntaje); //Imprime el puntaje
    Ranking << "\t\t   " << puntaje << "\t"; //Imprime el puntaje en el archivo
    getline(cin, nombre); //Pide que ingrese el nombre
    Ranking << "\t     " << nombre; //Imprime el nombre en el archivo
    Ranking << "\t\t\t PERDEDOR\n"; //Imprime el estado de perdedor en el archivo
}

char Partida::mostrarPantalla_Volveraintentar(int perdido) { //Pantalla de volver a intentar
    if(perdido) { //Si ingresa un numero diferente de 0 significa que se ha perdido el juego
        cout << "\n\t\t* ¿Quieres volver a intentarlo " << nombre << " (s/n)?\n"; //Pregunta si quiere volver a jugar
    }
    else{ //Si no significa que el juego se ha quedado en pausa
        cout << "\n\t\t* ¿Quieres continuar jugando " << nombre << " (s/n)?\n"; //Pergunta si quiere seguir jugando
    }
    system("stty raw"); //Permite ingresar char sin dar enter
    cin >> opcion; //Ingresa la opcion
    system("stty cooked"); //Cambia el valor de la varibale como por referencia
    return opcion; //Retorna la opcion
}

void Partida::crearRanking() { //Inicializa el archivo ranking
    imprimirRanking("./ranking.txt",Ranking,std::ios::out); //Se establece la ruta, el objeto archivo y el modo de apertura
    Ranking << "\n\t\t **********RANKING DE JUGADORES**********\n\n"; //Cout inicial (titulo)
    Ranking << "\t\t PUNTAJE \t\t NOMBRE \t\t ESTADO\n\n"; //Títulos de la tabla de ranking
}