//
// Created by george on 3/12/23.
//

#include "main.h"

int** matA;
int** matB;
int** matC;
int matSizes[6];

int main(int argc, char* argv[]){
    scan_matrices(DEFAULT_MATA, MATRIX_A);
    display_matrix(1);
    return 0;
}