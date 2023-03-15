//
// Created by george on 3/12/23.
//

#include "matrix_utilities.h"

void display_matrix(int matrixIdentifier){
    int** selectedMatrix;
    int dimensions[2];
    switch(matrixIdentifier){
        case(MATRIX_A):
        {
            dimensions[0] = matSizes[0];
            dimensions[1] = matSizes[1];
            selectedMatrix = matA;
            printf("Input Matrix 1:\n");
            break;
        }
        case(MATRIX_B):
        {
            dimensions[0] = matSizes[2];
            dimensions[1] = matSizes[3];
            selectedMatrix = matB;
            printf("Input Matrix 2:\n");
            break;
        }
        case(MATRIX_C):
        {

            dimensions[0] = matSizes[4];
            dimensions[1] = matSizes[5];
            selectedMatrix = matC;
            printf("Output Matrix:\n");
            break;
        }
        default:
        {
            break;
        }
    }
    for(int i = 0; i < dimensions[0] ; i++){
        for(int j = 0 ; j < dimensions[1] ; j++){
            printf("%d\t", selectedMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** malloc_for_2D_arrOfInts(int rows, int cols){
    int** matrix;
    matrix = (int**) malloc(rows * sizeof(int*));
    for(int i = 0 ; i < rows ; i++){
        matrix[i] = (int*) malloc(cols * sizeof(int));
    }
    return matrix;
}

void printSeparator(){
    printf("------------------- Separator -------------------\n");
}