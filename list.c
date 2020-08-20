//
// Created by root on 8/19/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "dictFunctions.h"

#define MAXLENGTH 512

node_ptr creatNodes(FILE *fp) {
    char* buffer = (char *) malloc(sizeof(char) * (MAXLENGTH + 1)); // 512 chars and a '\0'
    char* separateResult = NULL;
    char separatorComma[] = ",";
    int* start = (int *) malloc(sizeof(int));
    int* end = (int *) malloc(sizeof(int));
    int i = 0, j = 0;

    size_t lineBufferLength = 0;

    // Set up a head node
    node_ptr p_head = (node_ptr) malloc(sizeof(node_t));
    node_ptr p_tail = p_head;
    p_tail -> next = NULL;

    // Skip the fist line
    fgets(buffer, MAXLENGTH, fp);

    // Read each line, and create each node.
    while(fgets(buffer, MAXLENGTH, fp) != NULL) {
        node_ptr pNew = (node_ptr) malloc(sizeof(node_t)); // Creat a new node
        *start = -1;
        *end = *start;

        // read numbers
        pNew->censusYear = extractIntNumber(buffer, start, end);
        // then, the end pointer points to the comma next to the first letter.
        pNew->blockId = extractIntNumber(buffer, start, end);
        pNew->propertyId = extractIntNumber(buffer, start, end);
        pNew->basePropertyId = extractIntNumber(buffer, start, end);
        pNew->clueSmallArea = extractString(buffer, start, end);
        pNew->key = extractString(buffer, start, end);
        pNew->industryCode = extractIntNumber(buffer, start, end);
        pNew->industryDescription = extractString(buffer, start, end);
        pNew->xCoordinate = extractDoubleNumber(buffer, start, end);
        pNew->yCoordinate = extractDoubleNumber(buffer, start, end);
        pNew->location = extractString(buffer, start, end);

        // set up connections;
        pNew->next = NULL;
        p_tail->next = pNew;
        p_tail = pNew;

    }
    // close the last node's door and return the head node pointer;
    p_tail -> next = NULL;
    return p_head;

}


