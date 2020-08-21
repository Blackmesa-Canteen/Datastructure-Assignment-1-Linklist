/**
 *  Created by Xiaotian Li on 8/19/2020.
 *  list.c file contains source codes of functions, which manipulate linked list.
 *
 *  node_ptr creatNodes(FILE *fp) -> input the pointer that points to source .csv file, this
 *  function will creat nodes, and each node stores a line of record from .csv file. Then the
 *  function will return the pointer that points to the head pointer of nodes. This function
 *  reads source file for only once, because the data we need will be stored in linked list.
 *
 *  void searchAndOutput(node_ptr dictHead, FILE *fp, char* whatToFind) ->
 *  input the head pointer of linked list that contains data, the pointer of output file, the
 *  pointer of string contains the key users are looking for.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "dictFunctions.h"
#define MAXLENGTH 512

node_ptr creatNodes(FILE *fp) {

    char* buffer = (char *) malloc(sizeof(char) * (MAXLENGTH + 1));
    if (buffer == NULL) exit(1);
    int* start = (int *) malloc(sizeof(int));
    if (start == NULL) exit(1);
    int* end = (int *) malloc(sizeof(int));
    if (end == NULL) exit(1);

    /* Set up a head node */
    node_ptr p_head = (node_ptr) malloc(sizeof(node_t));
    if (p_head == NULL) exit(1);
    node_ptr p_tail = p_head;
    p_tail -> next = NULL;

    /* Skip the fist line of source file*/
    printf("Reading files.... \n");
    fgets(buffer, MAXLENGTH, fp);

    /* Read each line, and create each node */
    while (fgets(buffer, MAXLENGTH, fp) != NULL) {
        node_ptr pNew = (node_ptr) malloc(sizeof(node_t));
        if (pNew == NULL) exit(1);
        *start = -1;
        *end = *start;

        pNew -> censusYear = extractIntNumber(buffer, start, end);
        pNew -> blockId = extractIntNumber(buffer, start, end);
        pNew -> propertyId = extractIntNumber(buffer, start, end);
        pNew -> basePropertyId = extractIntNumber(buffer, start, end);
        pNew -> clueSmallArea = extractString(buffer, start, end);
        pNew -> key = extractString(buffer, start, end);
        pNew -> industryCode = extractIntNumber(buffer, start, end);
        pNew -> industryDescription = extractString(buffer, start, end);
        pNew -> xCoordinate = extractDoubleNumber(buffer, start, end);
        pNew -> yCoordinate = extractDoubleNumber(buffer, start, end);
        pNew -> location = extractString(buffer, start, end);

        /* set up connections */
        pNew -> next = NULL;
        p_tail -> next = pNew;
        p_tail = pNew;
    }

    printf("Done. Please input the key now. \n");
    printf("******************************\n");
    p_tail -> next = NULL;
    free(buffer);
    free(start);
    free(end);

    return p_head;
}

void searchAndOutput(node_ptr dictHead, FILE *fp, char* whatToFind) {

    int hasFound = 0;
    node_ptr p = dictHead -> next;

    printf("Generating the output...\n");
    while (p != NULL) {
        /* if found the record */
        if (!strcmp(p -> key, whatToFind)) {
            hasFound = 1;
            fprintf(fp,"%s −− > ", whatToFind);
            fprintf(fp, "Census year: %d || ", p -> censusYear);
            fprintf(fp, "Block ID: %d || ", p -> blockId);
            fprintf(fp, "Property ID: %d || ", p -> propertyId);
            fprintf(fp, "Base property ID: %d || ", p -> basePropertyId);
            fprintf(fp, "CLUE small area: %s || ", p -> clueSmallArea);
            fprintf(fp, "Industry (ANZSIC4) code: %d || ", p -> industryCode);
            fprintf(fp, "Industry (ANZSIC4) description: %s || ", p -> industryDescription);
            fprintf(fp, "X coordinate: %.5f || ", p -> xCoordinate);
            fprintf(fp, "Y coordinate: %.5f || ", p -> yCoordinate);
            fprintf(fp, "Location: %s || \n\n", p -> location);
        }
        p = p -> next;
    }

    /* if not found the record */
    if (hasFound == 0) {
        fprintf(fp,"%s −− > ", whatToFind); /* write the key name */
        printf("WARNING: No record, check the name?\n");
        fprintf(fp, "NOT FOUND. \n\n");
    }
}

void freeList(node_ptr head) {

    node_ptr p;
    while (head != NULL) {
        p = head;
        head = head -> next;

        /**
         *  4 sentences below deal with mem leak problems
         *  in cutString() func. Although no memory leaks
         *  anymore, 4 UninitCondition warnings shows up
         *  in Valgrind.
         */
        free(p -> clueSmallArea);
        free(p -> industryDescription);
        free(p -> location);
        free(p -> key);

        free(p);
    }
}

