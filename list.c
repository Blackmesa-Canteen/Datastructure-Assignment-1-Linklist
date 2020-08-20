//
// Created by root on 8/19/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define MAXLENGTH 512

//int* getInt (int start, char* buffer);
//char* getString (int start, char* buffer);
int toNumber(char* input);
char* toString(char* input);

node_ptr creatNodes(FILE *fp) {
    char* buffer = (char *) malloc(sizeof(char) * (MAXLENGTH + 1)); // 512 chars and a '\0'
    char* separateResult = NULL;
    char separatorComma[] = ",";
    int i = 0, j = 0;
    size_t lineBufferLength = 0;

    // Set up a head node
    node_ptr p_head = (node_ptr) malloc(sizeof(node_t));
    node_ptr p_tail = p_head;
    p_tail -> next = NULL;

    // Skip the fist line
    fgets(buffer, MAXLENGTH, fp);

    // Read each line, and create each node.
    while(fgets(buffer, MAXLENGTH, fp) != NULL){
        node_ptr pNew = (node_ptr) malloc(sizeof(node_t)); // Creat a new node

        separateResult = strtok(buffer, separatorComma);
        pNew -> censusYear = toNumber(separateResult);

        separateResult = strtok(NULL, separatorComma);
        pNew -> blockId = toNumber(separateResult);

        separateResult = strtok(NULL, separatorComma);
        pNew -> propertyId = toNumber(separateResult);

        separateResult = strtok(NULL, separatorComma);
        pNew -> basePropertyId = toNumber(separateResult);

        separateResult = strtok(NULL, separatorComma);
        pNew -> clueSmallArea = (char*) malloc(
                sizeof(char) * (strlen(separateResult) + 1));
        //!!!
        strcpy(pNew -> clueSmallArea, separateResult);
        separateResult = strtok(NULL, separatorComma);

        pNew -> key = (char*) malloc(
                sizeof(char) * (strlen(separateResult) + 1));

    }

}
int toNumber(char* input) {
    int number = atoi(input);
    return number;
}

// get int number from a part of buffer(between the comma)
// return an array, the first is the number, the second is size
//int* getInt(int start, char* buffer) {
//    int i = 0, j = 0;
//    int number = 0;
//    int sizeCounter = 0;
//    int returnArray[2] = {0, 0};
//    char* numberbuffer = NULL;
//
//    for (i = start; buffer[i] != ','; i++) {
//        sizeCounter++;
//    }
//    numberbuffer = (char*) malloc(sizeof(char) * sizeCounter);
//    for (i = start; buffer[i] != ','; i++) {
//        numberbuffer[j] = buffer[i];
//        j++;
//    }
//    number = atoi(numberbuffer);
//
//    returnArray[0] = number;
//    returnArray[1] = sizeCounter;
//
//    return returnArray;
//}
//
//char* getString (int start, char* buffer) {
//    int i = 0, j = 0;
//    int sizeCounter = 0;
//    char* returnChars = NULL;
//
//    for (i = start; buffer[i] != ','; i++) {
//        sizeCounter++;
//    }
//    returnChars = (char*) malloc(sizeof(char) * (sizeCounter + 1));
//    for (i = start; buffer[i] != ','; i++) {
//        returnChars[j] = buffer[i];
//        j++;
//    }
//
//    returnChars[j] = '\0';
//    return returnChars;
//}