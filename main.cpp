#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "Juego.h"
#include "Partida.h"
#include "MiMatriz.h"

using namespace std;

Partida juego_nuevo; //Se crea el objeto

int main(int argc, char** argv) {

    fstream ranking("../ranking.txt",ios::out); //Se crea el archivo ranking
    juego_nuevo.crearRanking(); //Se abre el archivo ranking en el programa
    juego_nuevo.iniciarMatriz(); //Se inicializa la matriz

    while(true) {

        if (SDL_Init(SDL_INIT_AUDIO) != 0) {
            std::cerr << "SDL_Init ERROR: " << SDL_GetError() << std::endl;
            return -1;
        }

        //Abrir audio
        if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048) != 0) {
            std::cerr << "Mix_OpenAudio ERROR: " << Mix_GetError() << std::endl;
            return -1;
        }

        // Coloca el volumen
        Mix_VolumeMusic(100);

        // Abre archivo de audio
        Mix_Music *music = Mix_LoadMUS(argv[1]);

        if (music) {
            // Inicia reproduccion
            if (Mix_PlayMusic(music, 1) == 0) {
                unsigned int startTime = SDL_GetTicks();

                // Comienza
                while (Mix_PlayingMusic()) {
                    juego_nuevo.mostrarTablero(); //Imprime la matriz
                    juego_nuevo.presionarTecla(); //Espera ingreso de movimiento o comando
                    juego_nuevo.entradaComando(&juego_nuevo); //Ejecuta el movimiento
                    juego_nuevo.verificarFinjuego(&juego_nuevo); //Verifica si la matriz está llena
                }
            } else {
                std::cerr << "Mix_PlayMusic ERROR: " << Mix_GetError() << std::endl;
            }

            // Libera archivo
            Mix_FreeMusic(music);
            music = 0;
        } else {
            std::cerr << "Mix_LoadMuS ERROR: " << Mix_GetError() << std::endl;
        }

        // End
        Mix_CloseAudio();
    }

}