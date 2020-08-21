/**
 *  Created by Xiaotian Li on 8/19/2020.
 *  dictFunctions.c file contains source codes of functions, which manipulate the records from
 *  the source file, to give the dictionary ability to process data.
 *
 *  char* cutString(char* input,int start,int end) -> input source string, output the substring in
 *  index interval [start, end) from source string.
 *
 *  int extractIntNumber(char* buffer, int* start, int* end) -> input a line of record, index interval,
 *  and output the number converted from string.
 *
 *  double extractDoubleNumber(char* buffer, int* start, int* end) -> similar to above. Output double.
 *  char* extractString(char* buffer, int* start, int* end) -> similar to above. Deal with comma.
 *  void trimLastEnter(char *str) -> change '\n' into '\0' at the end of the string.
 */

#include <stdlib.h>
#include <string.h>

char* cutString(char* input,int start,int end) {

    int i = 0, j = 0;
    int size = end - start;
    char* output = NULL;

    output = (char*) malloc(sizeof(char) * (size + 1));
    if (output == NULL) exit(1);
    for ( i = start; i < end; i++) {
        output[j++] = input[i];
    }
    output[j] = '\0';

    return output;
}

int extractIntNumber(char* buffer, int* start, int* end) {

    int i = 0, number = 0;
    char* catch = NULL;
    *start = *end + 1;
    *end = *start;

    for(i = *start; buffer[i] != ','; i++) {
        *end = *end + 1;
    }
    catch = cutString(buffer, *start, *end);

    /* convert string to integer number */
    number = strtol(catch, NULL, 10);
    free(catch);

    return  number;
}

double extractDoubleNumber(char* buffer, int* start, int* end) {

    int i = 0;
    double number = 0;
    char* catch = NULL;

    *start = *end + 1;
    *end = *start;
    for(i = *start; buffer[i] != ','; i++) {
        *end = *end + 1;
    }
    catch = cutString(buffer, *start, *end);
    number = strtod(catch, NULL);
    free(catch);

    return  number;
}

char* extractString(char* buffer, int* start, int* end) {

    int i = 0;
    char* catch = NULL;

    *start = *end + 1;
    *end = *start;
    /* if this substring does NOT has comma */
    if (buffer[*start] != '\"') {
        for(i = *start; buffer[i] != ',' ; i++) {
            if(buffer[i] == '\0') { //Check at the end
                *end = *end + 1;
                break;
            }
            *end = *end + 1;
        }
        catch = cutString(buffer, *start, *end);
        return catch;
    }
    // if this substring has "..., ..."
    else {
        *start = *start + 1;
        *end = *start; // move out of the "
        for(i = *start; buffer[i] != '\"'; i++) {
            *end = *end + 1;
        }
        catch = cutString(buffer, *start, *end);
        *end = *end + 1; // move to the ,

        return catch;
    }
}

void trimLastEnter(char *str) {
    int len = strlen(str);
    //delete the last '\n'
    if(str[len-1] == '\n')
    {
        len--;
        str[len] = '\0';
    }
}