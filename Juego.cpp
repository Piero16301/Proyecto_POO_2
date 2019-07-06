#include "Partida.h"
#include "Juego.h"
#include <vector>
#include <chrono>
#include <random>

int presionar_enter;

template <typename T>
T maxim(T n, T m){
    if(n > m){
        return n;
    } else {
        return m;
    }
}

int contarcero(int n[][4]){
    int ceros = 0;
    for(int i=0; i<4; i++){
        for(int e = 0; e<4; e++){
            if(n[i][e] == 0){
                ceros++;
            }
        }
    }
    return ceros;
}

void Juego::intercambio(bool n){
    if(n){
        for(int i = 0; i<4; i++){
            for(int e = 0; e<4; e++){
                matriz_actual[i][e] = matriz_temp[i][e];
            }
        }
    } else {
        for(int i = 0; i<4; i++){
            for(int e = 0; e<4; e++){
                matriz_temp[i][e] = matriz_actual[i][e];
            }
        }
    }
}

void Juego::entradaComando(Partida *juego_nuevo) { //Ejecuta el movimiento o comando
    switch (movimiento){
        case 'w':
        case 'a':
        case 's':
        case 'd':
            juego_nuevo->hacerBackup(); //Realiza el backup
            juego_nuevo->llenarCasilla(); //Realiza el movimiento
            juego_nuevo->actualizarMatriz(); //Realiza la suma e incrementa el puntaje
            juego_nuevo->llenarCasilla(); //Revisa que no queden ceros luego de las sumas
            juego_nuevo->buscarCasillamayor(); //Busca la casilla mayor para comprobar si se llegó a 2048
            juego_nuevo->mostrarTablero(); //Imprime el tablero nuevo

            if(juego_nuevo->saturado() && fin){ //Comprueba si se ha llenado todas las casillas
                estado = -1;
                break;
            }
            else if(juego_nuevo->movimientoBloque()){ //Verifica si se ha efectuado algun movimiento
                juego_nuevo->generar(); //Genera un nuevo numero en un espacio vacio
                break;
            }
            else{
                estado = 0; //Estado 0: Continua juego. Estado -1: Game over
                break;
            }
        case 'b':{ //Deshacer movimiento
            if(juego_nuevo->movimientoBloque()){
                puntaje -= suma; //Vuelve al puntaje anterior
            }
            juego_nuevo->deshacer(); //Copia la matriz del backup a la actual
            break;
        }
        case 'q':{ //Sale del juego
            estado = -1;
            break;
        }
        case 'i':{
            juego_nuevo->mostrarPantalla_Instrucciones(); //Cambia a la pantalla de instrucciones
            presionar_enter = getchar(); //Enter borra la pantalla de instrucciones
            juego_nuevo->mostrarTablero(); //Muestra nuevamente el tablero
            break;
        }
    }
}

void Juego::verificarFinjuego(Partida *nueva_partida) {
    if(maximo == ganador){ //Verifica si se ha llegado a la casilla de ganador
        nueva_partida->mostrarPantalla_Ganador(); //Muestra la pantalla de ganador
        if(nueva_partida->mostrarPantalla_Volveraintentar(0) == 'n'){ //Muestra si se quiere jugar de nuevo
            estado = -1; //Si se ingresa n se termina el juego
        }
        else{
            ganador *= 2;
        }
    }
    else if(estado == -1){ //Si se termina el juego antes, ingresa en este else if
        nueva_partida->mostrarPantalla_Perdedor(); //Muestra la pantalla de perdedor
        if(nueva_partida->mostrarPantalla_Volveraintentar(1) == 's'){ //Si se elige la s
            nueva_partida->iniciarMatriz(); //Inicia una nueva matriz
            estado = 0; //Cambia estado a 0
        }
    }
    if(estado == -1){ //Si estado -1 termina el juego
        cout << "\n\n\t\t\t     GRACIAS POR JUGAR A 2048\n" << endl << "Presione enter para salir....";
        presionar_enter = getchar(); //Muestra GAME OVER luego de mostrar la ventana de Game over
        system("clear");
        exit(0); //Termina el programa
    }
}

void Juego::presionarTecla() { //Recibe el movimiento o comando
    system("stty raw");
    cin >> movimiento;
    system("stty cooked");
}

void Juego::iniciarMatriz() { //Inicia nueva matriz
    srand(time(NULL)); //Semilla
    suma = 0; //Inicia variables de suma puntaje y maximo(casilla maxima)
    puntaje = 0;
    maximo = 0;
    for(int i = 0; i < 4; i++){
        for(int e = 0; e<4; e++){
            matriz_actual[i][e] = 0;
        }
    }
    //Generar 2 pares ordenados randoms diferentes para el tablero
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    //Verificar que las 2 posiciones del tablero sean diferentes y random
    std::vector<int> numbers_x;
    std::vector<int> numbers_y;
    for(int i=0; i<4; i++){
        numbers_x.push_back(i);
    }
    for(int i=0; i<4; i++){
        numbers_y.push_back(i);
    }
    unsigned seed_x = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned seed_y = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers_x.begin(), numbers_x.end(), std::default_random_engine(seed_x));
    std::shuffle(numbers_y.begin(), numbers_y.end(), std::default_random_engine(seed_y));
    x1 = numbers_x[0];
    x2 = numbers_x[1];
    y1 = numbers_y[0];
    y2 = numbers_y[1];
    //std::cout << "x1:" << x1 << " y1:" << y1 << std::endl;
    //std::cout << "x2:" << x2 << " y2:" << y2 << std::endl;
    /*while (true) {
        x1 = rand() % 4;
        y1 = rand() % 4;
        x2 = rand() % 4;
        y2 = rand() % 4;
        if (x1 == x2) {
            if (y1 != y2) {
                break;
            }
        }
        if (y1 == y2) {
            if (x1 != x2) {
                break;
            }
        }
        if (x1 != x2) {
            break;
        }
        if (y1 != y2) {
            break;
        }
    }
    std::cout << "old way:" << x1 << " " << x2;*/
    // Asignamos del valor 2 en dos posiciones diferentes y random del tablero
    matriz_actual[x1][y1] = 2;
    matriz_actual[x2][y2] = 2;
}

void Juego::actualizarMatriz() { //Realiza las sumas y actualiza el puntaje

    suma = 0; //Inicializa suma en 0
    fin = 1; //Y variable fin en true(1)

    switch (movimiento){

        case 'w': //Para arriba
            for(int i=0;i<4;i++)
                for(int j=0;j<3;j++){
                    if(matriz_actual[j][i] && matriz_actual[j][i] == matriz_actual[j+1][i]){ //Si encuentra una casilla con un numero diferente de 0 y esa casilla es igual a la que esta a su costado
                        fin = 0; //Variable fin se establece en 0 indicando que el juego continua
                        matriz_actual[j][i] += matriz_actual[j+1][i]; //Se realiza la suma
                        matriz_actual[j+1][i] = 0; //La casilla del costado queda en 0
                        suma += matriz_actual[j][i] + matriz_actual[j+1][i]; //Se calcula la cantidad a sumar
                        puntaje += matriz_actual[j][i] + matriz_actual[j+1][i]; //Se aumenta el puntaje
                    }
                }
            break;

        case 's': //Para abajo
            for(int i=0;i<4;i++)
                for(int j=3;j>0;j--){
                    if(matriz_actual[j][i] && matriz_actual[j][i] == matriz_actual[j-1][i]){ //Si encuentra una casilla con un numero diferente de 0 y esa casilla es igual a la que esta a su costado
                        fin = 0; //Variable fin se establece en 0 indicando que el juego continua
                        matriz_actual[j][i] += matriz_actual[j-1][i]; //Se realiza la suma
                        matriz_actual[j-1][i] = 0; //La casilla del costado queda 0
                        suma += matriz_actual[j][i] + matriz_actual[j-1][i]; //Se calcula la cantidad a sumar
                        puntaje += matriz_actual[j][i] + matriz_actual[j-1][i]; //Se aumenta el puntaje
                    }
                }
            break;

        case 'a': //Para la izquierda
            for(int i=0;i<4;i++)
                for(int j=0;j<3;j++){
                    if(matriz_actual[i][j] && matriz_actual[i][j] == matriz_actual[i][j+1]){ //Si encuentra una casilla con un numero diferente de 0 y esa casilla es igual a la que esta a su costado
                        fin = 0; //Variable fin se establece en 0 indicando que el juego continua
                        matriz_actual[i][j] += matriz_actual[i][j+1]; //Se realiza la suma
                        matriz_actual[i][j+1] = 0; //La casilla del costado queda en 0
                        suma += matriz_actual[i][j] + matriz_actual[i][j+1]; //Se calcula la cantidad a sumar
                        puntaje += matriz_actual[i][j] + matriz_actual[i][j+1]; //Se aumenta el puntaje
                    }
                }
            break;

        case 'd': //Para la derecha
            for(int i=0;i<4;i++)
                for(int j=3;j>0;j--){
                    if(matriz_actual[i][j] && matriz_actual[i][j] == matriz_actual[i][j-1]){ //Si encuentra una casilla con un numero diferente de 0 y esa casilla es igual a la que esta a su costado
                        fin = 0; //Variable fin se establece en 0 indicando que el juego continua
                        matriz_actual[i][j] += matriz_actual[i][j-1]; //Se realiza la suma
                        matriz_actual[i][j-1] = 0; //La casilla del costado queda en 0
                        suma += matriz_actual[i][j] + matriz_actual[i][j-1]; //Se calcula la cantidad a sumar
                        puntaje += matriz_actual[i][j] + matriz_actual[i][j-1]; //Se aumenta el puntaje
                    }
                }
            break;
    }
}

void Juego::llenarCasilla() { //Realiza los movimientos de los numeros
    switch (movimiento){
        case 'w': //Para arriba
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++){
                    if(!matriz_actual[j][i]){ //Si encuentra un 0
                        for(int k=j+1;k<4;k++)
                            if(matriz_actual[k][i]){ //Si encuentra un numero diferente de 0
                                matriz_actual[j][i] = matriz_actual[k][i]; //El 0 es reeemplazado por el nuevo numero
                                matriz_actual[k][i] = 0; //La otra coordenada queda en 0
                                break;
                            }
                    }
                }
            break;

        case 's': //Para abajo
            for(int i=0;i<4;i++)
                for(int j=3;j>=0;j--){
                    if(!matriz_actual[j][i]){ //Si encuentra un 0
                        for(int k=j-1;k>=0;k--)
                            if(matriz_actual[k][i]){ //Si encuentra un numero diferente de 0
                                matriz_actual[j][i] = matriz_actual[k][i]; //El 0 es reemplazado por el nuevo numero
                                matriz_actual[k][i] = 0; //La otra coordenada queda en 0
                                break;
                            }
                    }
                }
            break;

        case 'a': //Para la izquierda
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++){
                    if(!matriz_actual[i][j]){ //Si encuentra un 0
                        for(int k=j+1;k<4;k++)
                            if(matriz_actual[i][k]){ //Si encuentra un numero diferente de 0
                                matriz_actual[i][j] = matriz_actual[i][k]; //El 0 es reemplazado por el nuevo numero
                                matriz_actual[i][k] = 0; //La otra coordenada queda en 0
                                break;
                            }
                    }
                }
            break;

        case 'd': //Para la derecha
            for(int i=0;i<4;i++)
                for(int j=3;j>=0;j--){
                    if(!matriz_actual[i][j]){ //Si encuentra un 0
                        for(int k=j-1;k>=0;k--)
                            if(matriz_actual[i][k]){ //Si encuentra un numero diferente de 0
                                matriz_actual[i][j] = matriz_actual[i][k]; //El 0 es reemplazado por el nuevo numero
                                matriz_actual[i][k] = 0; //La otra coordenada queda en 0
                                break;
                            }
                    }
                }
            break;

    }
}

void Juego::generar() { //Genera un nuevo numero
    int a,b,c;
    srand(time(NULL)); //Semilla

    do{
        a = rand()%4; //Genera la coordenada hasta que toque una casilla vacia 0-3
        b = rand()%4;
        c = rand()%10; //Genrera el numero para la probabilidad 0-9
    }while (matriz_actual[a][b]);

    if(c<2){ //Si es 0,1 colocará un 4 20% probabilidad
        matriz_actual[a][b] = 4;
    }
    else{ //Si no colocará un 2 80% probabilidad
        matriz_actual[a][b] = 2;
    }
}

void Juego::buscarCasillamayor() { //Busca la casilla mayor en el tablero
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matriz_actual[i][j]>maximo){
                maximo = matriz_actual[i][j]; //Cambia la variable maximo si encuentra un nuevo numero mayor
            }
        }
    }
}

void Juego::hacerBackup() { //Crea el backup
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            matriz_backup[i][j] = matriz_actual[i][j]; //Copia los valores a la matriz de backup
        }
    }
}

void Juego::deshacer() { //Deshace el ultimo movimiento
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            matriz_actual[i][j] = matriz_backup[i][j]; //Se reemplazan los valores de la matriz actual por la del backup
        }
    }
}

int Juego::saturado() { //Verifica si se ha llenado por completo el tablero
    int a = 1; //Se inicia como 1

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(!matriz_actual[i][j]){ //Si hay un 0 entonces a retorna 0
                a = 0;
            }
        }
    }
    return a; //Si no retorna 1 y se termina el juego
}

int Juego::movimientoBloque() { //Detecta si ha habido un movimiento
    int p = 0; //Se inicia en 0 (no hay movimiento)

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matriz_backup[i][j] != matriz_actual[i][j]){ //Compara la matriz del backup con la actual
                p = 1; //Si retorna 1 ha habido movimiento
                break;
            }
        }
    }
    return p;
}

std::string Juego::sugerencia(){
    int punt = puntaje;
    intercambio(false);
    int w, a, s, d, max;
    movimiento = 'w';
    llenarCasilla();
    actualizarMatriz();
    llenarCasilla();
    w = contarcero(matriz_actual);
    intercambio(true);
    movimiento = 'a';
    llenarCasilla();
    actualizarMatriz();
    llenarCasilla();
    a = contarcero(matriz_actual);
    intercambio(true);
    movimiento = 's';
    llenarCasilla();
    actualizarMatriz();
    llenarCasilla();
    s = contarcero(matriz_actual);
    intercambio(true);
    movimiento = 'd';
    llenarCasilla();
    actualizarMatriz();
    llenarCasilla();
    d = contarcero(matriz_actual);
    intercambio(true);
    max = maxim(w, maxim(a, maxim(s, d)));
    puntaje = punt;
    if(max == w && max == a && max == s && max == d){
        return "Dale a cualquiera";
    } else if(max == w){
        return "Dale a w";
    } else if(max == a){
        return "Dale a a";
    } else if(max == s){
        return "Dale a s";
    } else {
        return "Dale a d";
    }
}