//
// Created by george on 3/12/23.
//

#include "main.h"

int** matA;
int** matB;
int** matC;
int matSizes[6];


int main(int argc, char* argv[]){
    system("clear");
    // ---------------------- Separator ----------------------
    prepare_environment(argc, argv);
    pthread_t firstMethodThread, secondMethodThread, thirdMethodThread;
    // ---------------------- Separator ----------------------
    printSeparator();
    pthread_create(&firstMethodThread, NULL, first_method, (void*) argv[3]);
    pthread_join(firstMethodThread, NULL);
    refreshStoredResultMatrix();
    // ---------------------- Separator ----------------------
    printSeparator();
    pthread_create(&secondMethodThread, NULL, second_method, (void*) argv[3]);
    pthread_join(secondMethodThread, NULL);
    refreshStoredResultMatrix();
    // ---------------------- Separator ----------------------
    printSeparator();
    pthread_create(&thirdMethodThread, NULL, third_method, (void*) argv[3]);
    pthread_join(thirdMethodThread, NULL);
    // ---------------------- Separator ----------------------
    printSeparator();
    display_matrix(MATRIX_A);
    display_matrix(MATRIX_B);
    display_matrix(MATRIX_C);
    // ---------------------- Separator ----------------------
    free(matA);
    free(matB);
    free(matC);
    // ---------------------- Separator ----------------------
    return 0;
}

/*
 * Function Checks the arguments, scan the input matrices
 * and then set the output matrix dimensions.
 */
void prepare_environment(int argc, char* argv[]){
    check_and_initialize(argc, argv);
    scanInputMatrices(argv[1], argv[2]);
    matC = malloc_for_2D_arrOfInts(matSizes[4], matSizes[5]);
}

/*
 * Function checks if the matrices files were given or not, if not
 * then initialize them to the default paths.
 */
void check_and_initialize(int argc, char** argv){
    if(argc == 1){
        argv[1] = DEFAULT_MATA;
        argv[2] = DEFAULT_MATB;
        argv[3] = DEFAULT_MATC;
    } else if(argc != 4){
        printf("Input Error: check_and_initialize, number of "
               "arguments was not expected.\n");
    }
}

/*
 * Function delegate the scanning process to the appropriate module.
 */
void scanInputMatrices(char* aPath, char* bPath){
    scan_matrices(aPath, MATRIX_A);
    scan_matrices(bPath, MATRIX_B);
}

void refreshStoredResultMatrix(){
    free(matC);
    matC = malloc_for_2D_arrOfInts(matSizes[4], matSizes[5]);
}
