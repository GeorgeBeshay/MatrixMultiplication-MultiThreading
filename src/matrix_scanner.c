//
// Created by george on 3/12/23.
//

#include "matrix_scanner.h"

/*
 * In the following function, a procedure should be followed
 * to scan both the input matrices to the global matrices
 */
void scan_matrices(char* fileName, int matrixIdentifier){
    // ------------------- Separator -------------------
    char currentDirectory[MAX_PATH_LEN];
    getcwd(currentDirectory, MAX_PATH_LEN);
    strcat(currentDirectory, "/../");
    strcat(currentDirectory, fileName);
    // ------------------- Separator -------------------
    FILE* matrixFile = fopen(currentDirectory, "r");
    char descriptionLine[MAX_LINE_LEN];
    fgets(descriptionLine, sizeof(descriptionLine), matrixFile);
    char descriptionLineCopy[MAX_LINE_LEN];
    strcpy(descriptionLineCopy, descriptionLine);
    // ------------------- Separator -------------------
    int* dimensions = (int*) malloc(2 * sizeof(int));
    getDimensions(dimensions, strlen(descriptionLineCopy), descriptionLineCopy);
    // ------------------- Separator -------------------
    int** selectedMatrix = realiseMatrix(matrixIdentifier, dimensions);
    for(int i = 0 ; i < dimensions[0] ; i++){
        for(int j = 0 ; j < dimensions[1] ; j++){
            if(j == dimensions[1])
                fscanf(matrixFile, "%d\n", &selectedMatrix[i][j]);
            else
                fscanf(matrixFile, "%d\t", &selectedMatrix[i][j]);
        }
    }
    // ------------------- Separator -------------------
    fclose(matrixFile);
}

/*
 * Function objective is to allocate memory for a matrix, given its dimensions,
 * and then return a pointer to the same memory location.
 */
int** realiseMatrix(int matrixIdentifier, int* dimensions){
    // ------------------- Separator -------------------
    int **selectedMatrix;
    selectedMatrix = (int**) malloc(dimensions[0] * sizeof(int*));
    for(int i = 0 ; i < dimensions[0] ; i++){
        selectedMatrix[i] = (int*) malloc(dimensions[1] * sizeof(int));
    }
    // ------------------- Separator -------------------
    switch (matrixIdentifier) {
        case(MATRIX_A):
        {
            matSizes[0] = dimensions[0];
            matSizes[1] = dimensions[1];
            matA = selectedMatrix;
            break;
        }
        case(MATRIX_B):
        {
            matSizes[2] = dimensions[0];
            matSizes[3] = dimensions[1];
            matB = selectedMatrix;
            break;
        }
        case(MATRIX_C):
        {

            matSizes[4] = dimensions[0];
            matSizes[5] = dimensions[1];
            matC = selectedMatrix;
            break;
        }
        default:
        {
            break;
        }
    }
    // ------------------- Separator -------------------
    return selectedMatrix;
}

/*
 * In this function a line input would be passed
 * from which the size of the matrix should be fetched.
 */
void getDimensions( int *dimensions, int len, char descriptiveLine[len]){
    sscanf(descriptiveLine, "row=%d col=%d", &dimensions[0], &dimensions[1]);
}