#ifndef PROYECTO_MIMATRIZ_H
#define PROYECTO_MIMATRIZ_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

template <class T>
class Mimatriz {

public:
    T** arr;
    int row;
    int col;

    void allocate( const int& row, const int& col ) {
        this->row = row;
        this->col = col;

        arr = new T*[row];
        for ( int i = 0; i < row; i++ ) {
            arr[i] = new T[col];
        }
    }

    Mimatriz() : arr{nullptr}, row{0}, col{0} {}

    Mimatriz(const int& row, const int& col ){
        allocate(row, col);
    }

    T get_column() {
        return this->col;
    }

    T get_row() {
        return this->row;
    }

    void mostrarMatriz(){
        for (int f=0;f<this->row;f++) {
            for (int c = 0; c < this->col; c++) {
                std::cout << std::setw(4) << arr[f][c] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    ~Mimatriz() {
        /*for (int i = 0; i < row; i++)
            delete arr[i];
        delete [] arr;*/
    }

};

#endif //PROYECTO_MIMATRIZ_H