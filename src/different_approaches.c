//
// Created by george on 3/14/23.
//

#include "different_approaches.h"


void* first_method(void* outputFileName){
    struct multiplication_approach_data* approachData = malloc_for_threadData("A Thread per matrix.");
    // ---------------------- Separator ----------------------
    for(int i = 0 ; i < matSizes[4] ; i++){
        for(int j = 0 ; j < matSizes[5] ; j++){
            matC[i][j] = 0;
            for(int k = 0 ; k < matSizes[1] ; k++)
                matC[i][j] += matA[i][k] * matB[k][j];
        }
    }
    // ---------------------- Separator ----------------------
    gettimeofday(&approachData->stop, NULL);
    char* finalOutputFileName = createSuitableString((char*) outputFileName, "_per_matrix");
    write_out_matrix(approachData, finalOutputFileName);
    printf("A thread per matrix:\n\tNumber of Threads -> %d\n\tExecution time -> %ld microS\n\n", approachData->threads_count, approachData->stop.tv_usec - approachData->start.tv_usec);
    // free the allocated memory for the thread data.
    free(finalOutputFileName);
    free(approachData);
    return NULL;
}

void* second_method(void* outputFileName){
    // allocate memory for the thread data, and initialize the method name, starting time.
    struct multiplication_approach_data* approachData = malloc_for_threadData("A Thread per row.");
    // ---------------------- Separator ----------------------
    pthread_t operationThreads[matSizes[4]];
    int rowNums[matSizes[4]];
    for(int i = 0 ; i < matSizes[4] ; i++){
        rowNums[i] = i;
        pthread_create(&operationThreads[i], NULL, second_method_calcRow, (void*) &rowNums[i]);
        approachData->threads_count++;
    }
    pthread_join(operationThreads[matSizes[4] - 1], NULL);
    // ---------------------- Separator ----------------------
    gettimeofday(&approachData->stop, NULL);
    char* finalOutputFileName = createSuitableString((char*) outputFileName, "_per_row");
    write_out_matrix(approachData, finalOutputFileName);
    printf("A thread per row:\n\tNumber of Threads -> %d\n\tExecution time -> %ld microS\n\n", approachData->threads_count, approachData->stop.tv_usec - approachData->start.tv_usec);
    // free the allocated memory for the thread data.
    free(finalOutputFileName);
    free(approachData);
    return NULL;
}

void* second_method_calcRow(void* rowNum){
    int rowNum_ = *(int*)rowNum;
    for(int j = 0 ; j < matSizes[5] ; j++){
        matC[rowNum_][j] = 0;
        for(int k = 0 ; k < matSizes[1] ; k++)
            matC[rowNum_][j] += matA[rowNum_][k] * matB[k][j];
    }
    return NULL;
}

void* third_method(void* outputFileName){
    struct multiplication_approach_data* approachData = malloc_for_threadData("A Thread per element.");
    // ---------------------- Separator ----------------------
    pthread_t operationThreads[matSizes[4]][matSizes[5]];
    struct matrix_element_location elementNums[matSizes[4]][matSizes[5]];
    for(int i = 0 ; i < matSizes[4] ; i++){
        for(int j = 0 ; j < matSizes[5] ; j++){
            elementNums[i][j].rowNum = i;
            elementNums[i][j].colNum = j;
            pthread_create(&operationThreads[i][j], NULL, third_method_calcElem, (void*) &elementNums[i][j]);
            approachData->threads_count++;
        }
    }
    pthread_join(operationThreads[matSizes[4] - 1][matSizes[5] - 1], NULL);
    // ---------------------- Separator ----------------------
    gettimeofday(&approachData->stop, NULL);
    char* finalOutputFileName = createSuitableString((char*) outputFileName, "_per_element");
    write_out_matrix(approachData, finalOutputFileName);
    printf("A thread per element:\n\tNumber of Threads -> %d\n\tExecution time -> %ld microS\n\n", approachData->threads_count, approachData->stop.tv_usec - approachData->start.tv_usec);
    // free the allocated memory for the thread data.
    free(finalOutputFileName);
    free(approachData);
    return NULL;
}

void* third_method_calcElem(void* elemStruct){
    int row = ((struct matrix_element_location*)elemStruct)->rowNum;
    int col = ((struct matrix_element_location*)elemStruct)->colNum;
    matC[row][col] = 0;
    for(int k = 0 ; k < matSizes[1] ; k++)
        matC[row][col] += matA[row][k] * matB[k][col];
    return NULL;
}

struct multiplication_approach_data* malloc_for_threadData(char* methodName){
    struct multiplication_approach_data* threadData = (struct multiplication_approach_data*) malloc(sizeof(struct multiplication_approach_data));
    threadData->method_name = (char*) malloc(100 * sizeof(char));
    strcpy(threadData->method_name, methodName);
    threadData->threads_count = 1;
    gettimeofday(&threadData->start, NULL);
    return threadData;
}

char* createSuitableString(char* pureFileName, char* extension){
    char* finalOutputFile = (char*) malloc((strlen((char*) pureFileName) + strlen(extension)) * sizeof(char));
    strcpy(finalOutputFile, pureFileName);
    strcat(finalOutputFile, extension);
    return finalOutputFile;
}