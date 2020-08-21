//
// Created by Xiaotian on 8/19/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "dictFunctions.h"
#define MAXLENGTH 512

node_ptr creatNodes(FILE *fp) {
    char* buffer = (char *) malloc(sizeof(char) * (MAXLENGTH + 1)); // 512 chars + '\0'
    if(buffer == NULL) exit(1);
    int* start = (int *) malloc(sizeof(int));
    if(start == NULL) exit(1);
    int* end = (int *) malloc(sizeof(int));
    if(end == NULL) exit(1);

    // Set up a head node
    node_ptr p_head = (node_ptr) malloc(sizeof(node_t));
    if(p_head == NULL) exit(1);
    node_ptr p_tail = p_head;
    p_tail -> next = NULL;

    // Skip the fist line
    printf("Reading files.... \n");
    fgets(buffer, MAXLENGTH, fp);

    // Read each line, and create each node.
    while(fgets(buffer, MAXLENGTH, fp) != NULL) {
        node_ptr pNew = (node_ptr) malloc(sizeof(node_t)); // Creat a new node
        if(pNew == NULL) exit(1);
        *start = -1;
        *end = *start;

        // read numbers
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

        //set up connections;
        pNew->next = NULL;
        p_tail->next = pNew;
        p_tail = pNew;
    }
    // close the last node's door and return the head node pointer;
    printf("Reading finished!\n");
    printf("******************************\n");
    p_tail -> next = NULL;
    free(buffer);
    free(start);
    free(end);
    return p_head;
}

void searchAndOutput(node_ptr dictHead, FILE *fp, char* whatToFind, char* outputFileName) {
    int hasFound = 0;
    node_ptr p = dictHead->next; // the pointer points to the dictionary;

    printf("Generating the output...\n");
    while(p != NULL) {

        // if found the record
        if ( !strcmp(p -> key, whatToFind) ) {
            hasFound = 1;
            fprintf(fp,"%s −− > ", whatToFind); //write the key name;
            fprintf(fp, "Census year: %d || ", p -> censusYear);
            fprintf(fp, "Block ID: %d || ", p -> blockId);
            fprintf(fp, "Property ID: %d || ", p -> propertyId);
            fprintf(fp, "Base property ID: %d || ", p -> basePropertyId);
            fprintf(fp, "CLUE small area: %s || ", p -> clueSmallArea);
            fprintf(fp, "Industry (ANZSIC4) code: %d || ", p -> industryCode);
            fprintf(fp, "Industry (ANZSIC4) description: %s || ", p -> industryDescription);
            fprintf(fp, "X coordinate: %f || ", p -> xCoordinate);
            fprintf(fp, "Y coordinate: %f || ", p -> yCoordinate);
            fprintf(fp, "Location: %s || \n", p -> location);
        }
        p = p -> next; // move to the next node;
    }
    // if not found the record;
    if(hasFound == 0) {
        fprintf(fp,"%s −− > ", whatToFind); //write the key name;
        printf("WARNING: No record, check again please.\n");
        fprintf(fp, "NOT FOUND. \n");
    }
}

