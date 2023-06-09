//
// Created by george on 3/12/23.
//

#ifndef SRC_MAIN_H
#define SRC_MAIN_H


// Including required system related modules
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <malloc.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct {
    int threads_count;
    char* method_name;
    struct timeval stop, start;
} multiplication_approach_data;

typedef struct {
    int rowNum;
    int colNum;
} matrix_element_location;

// Including other user defined modules
#include "matrix_io.h"
#include "matrix_utilities.h"
#include "different_approaches.h"

// Global definitions
#define DEFAULT_MATA "a"
#define DEFAULT_MATB "b"
#define DEFAULT_MATC "c"
#define MAX_LINE_LEN 200   // the 1st line in the text file
#define MAX_PATH_LEN 300
#define MATRIX_A 1
#define MATRIX_B 2
#define MATRIX_C 3

// Global variables
extern int** matA;
extern int** matB;
extern int** matC;
extern int matSizes[6];

// Functions prototype
int main(int argc, char* argv[]);
void scanInputMatrices(char* aPath, char* bPath);
void check_and_initialize(int argc, char** argv);
void prepare_environment(int argc, char* argv[]);
void refreshStoredResultMatrix();

#endif //SRC_MAIN_H
