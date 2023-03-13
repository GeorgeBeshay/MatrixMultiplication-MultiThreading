//
// Created by george on 3/12/23.
//

#ifndef SRC_MATRIX_SCANNER_H
#define SRC_MATRIX_SCANNER_H

#include "main.h"

void scan_matrices(char* fileName, int matrixIdentifier);
void getDimensions( int *dimensions, int len, char descriptiveLine[len]);
int** realiseMatrix(int matrixIdentifier, int* dimensions);

#endif //SRC_MATRIX_SCANNER_H
