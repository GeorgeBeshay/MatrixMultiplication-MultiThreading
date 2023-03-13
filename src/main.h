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

// Including other user defined modules
#include "matrix_scanner.h"
#include "matrix_utilities.h"

// Global definitions
#define DEFAULT_MATA "a.txt"
#define DEFAULT_MATB "b.txt"
#define DEFAULT_MATC "c.txt"
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

#endif //SRC_MAIN_H
