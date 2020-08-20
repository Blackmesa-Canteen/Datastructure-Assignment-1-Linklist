//
// Created by root on 8/19/20.
//
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef ASSIGNMENT_1__CODE_DICTFUNCTIONS_H
#define ASSIGNMENT_1__CODE_DICTFUNCTIONS_H

int toNumber(char* input);
char* cutString(char * input,int start,int end);
int extractIntNumber(char* buffer, int* start, int* end);
char* extractString(char* buffer, int* start, int* end);
double extractDoubleNumber(char* buffer, int* start, int* end);

#endif //ASSIGNMENT_1__CODE_DICTFUNCTIONS_H
