//
// Created by root on 8/19/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//convert string to number;
int toNumber(char* input) {
    int number = atoi(input);
    return number;
}

// similar to subString method in Java, [start, end);
char* cutString(char * input,int start,int end) {

    int i = 0, j = 0;
    int size = end - start;
    int inputSize = strlen(input);
    char* output = NULL;

    output = (char*) malloc(sizeof(char) * (size + 1));

    for( i = start; i < end; i++) {
        output[j++] = input[i];
    }

    output[j] = '\0';
    return output;
}

// used to extract Integer number start from the comma that nears the number;
int extractIntNumber(char* buffer, int* start, int* end) {
    int i = 0, number = 0;
    char* catch = NULL;
    *start = *end + 1;
    *end = *start;
    for(i = *start; buffer[i] != ','; i++) {
        *end = *end + 1;
    }
    catch = cutString(buffer, *start, *end);
    number = toNumber(catch);
    return  number;
}

// used to extract Double number start from the comma that nears the number;
double extractDoubleNumber(char* buffer, int* start, int* end) {
    int i = 0;
    float number = 0;
    char* catch = NULL;
    *start = *end + 1;
    *end = *start;
    for(i = *start; buffer[i] != ','; i++) {
        *end = *end + 1;
    }
    catch = cutString(buffer, *start, *end);
    number = atof(catch);
    return  number;

}

// used to extract characters;
char* extractString(char* buffer, int* start, int* end) {
    int i = 0, number = 0;
    char* catch = NULL;
    *start = *end + 1;
    *end = *start;

    // if this substring does NOT has "..., ..."
    if (buffer[*start] != '\"') {
        for(i = *start; buffer[i] != ',' ; i++) {
            if( buffer[i] == '\0') { //Check at the end
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