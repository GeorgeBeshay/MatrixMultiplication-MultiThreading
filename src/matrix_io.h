//
// Created by george on 3/12/23.
//

#ifndef SRC_MATRIX_IO_H
#define SRC_MATRIX_IO_H

#include "main.h"

void scan_matrices(char* fileName, int matrixIdentifier);
void getDimensions( int *dimensions, int len, char descriptiveLine[len]);
int** realiseMatrix(int matrixIdentifier, int* dimensions);
void write_out_matrix(char* fileName, double timeTaken);

#endif //SRC_MATRIX_IO_H
