//
// Created by george on 3/12/23.
//

#include "matrix_io.h"

/*
 * In the following function, a procedure should be followed
 * to scan both the input matrices to the global matrices
 */
void scan_matrices(char* fileName, int matrixIdentifier){
    // ------------------- Separator -------------------
    char currentDirectory[MAX_PATH_LEN];
    getcwd(currentDirectory, MAX_PATH_LEN);
    strcat(currentDirectory, "/Data/");
    strcat(currentDirectory, fileName);
    strcat(currentDirectory, ".txt");
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
    int** selectedMatrix = malloc_for_2D_arrOfInts(dimensions[0], dimensions[1]);
    // ------------------- Separator -------------------
    switch (matrixIdentifier) {
        case(MATRIX_A):
        {
            matSizes[0] = dimensions[0];
            matSizes[1] = dimensions[1];
            matSizes[4] = dimensions[0];
            matA = selectedMatrix;
            break;
        }
        case(MATRIX_B):
        {
            matSizes[2] = dimensions[0];
            matSizes[3] = dimensions[1];
            matSizes[5] = dimensions[1];
            matB = selectedMatrix;
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

void write_out_matrix(struct multiplication_approach_data* approachData, char* fileName){
    // ------------------- Separator -------------------
    char currentDirectory[MAX_PATH_LEN];
    getcwd(currentDirectory, MAX_PATH_LEN);
    strcat(currentDirectory, "/Data/");
    strcat(currentDirectory, fileName);
    strcat(currentDirectory, ".txt");
    // ------------------- Separator -------------------
    FILE* matrixFile = fopen(currentDirectory, "w");
    fprintf(matrixFile, "Method: %s\nrow=%d col=%d\n", approachData->method_name, matSizes[4], matSizes[5]);
    fprintf(matrixFile, "Time taken in micro seconds: %ld\n", approachData->stop.tv_usec - approachData->start.tv_usec);
    fprintf(matrixFile, "Total number of threads spawned: %d\n", approachData->threads_count);
    for(int i = 0 ; i < matSizes[4] ; i++){
        for(int j = 0 ; j < matSizes[5] ; j++){
            fprintf(matrixFile, "%d \t", matC[i][j]);
        }
        fprintf(matrixFile, "\n");
    }
    // ------------------- Separator -------------------
    fclose(matrixFile);
    // ------------------- Separator -------------------
}