//
// Created by george on 3/14/23.
//

#ifndef SRC_DIFFERENT_APPROACHES_H
#define SRC_DIFFERENT_APPROACHES_H

#include "main.h"

multiplication_approach_data* malloc_for_ApproachData(char* methodName);
void* first_method(void* outputFileName);
void* second_method(void* outputFileName);
void* second_method_calcRow(void* rowNum);
void* third_method(void* outputFileName);
void* third_method_calcElem(void* elemStruct);
char* createSuitableString(char* pureFileName, char* extension);

#endif //SRC_DIFFERENT_APPROACHES_H
