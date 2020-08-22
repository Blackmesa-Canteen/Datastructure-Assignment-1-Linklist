/**
 *  Created by Xiaotian Li on 8/19/2020.
 *  This header file contains declaration of functions used to process records
 *  from the .csv file
 */

#ifndef ASSIGNMENT_1__CODE_DICTFUNCTIONS_H
#define ASSIGNMENT_1__CODE_DICTFUNCTIONS_H

char* cutString(char* input,int start,int end);
int extractIntNumber(char* buffer, int* start, int* end);
char* extractString(char* buffer, int* start, int* end);
double extractDoubleNumber(char* buffer, int* start, int* end);
void trimLastEnter(char* str);

#endif /* ASSIGNMENT_1__CODE_DICTFUNCTIONS_H */
