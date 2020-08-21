//
// Created by Xiaotian on 8/19/20.
//
#ifndef ASSIGNMENT_1__CODE_LIST_H
#define ASSIGNMENT_1__CODE_LIST_H

typedef struct node {
    char* key;
    int censusYear;
    int blockId;
    int propertyId;
    int basePropertyId;
    char* clueSmallArea;
    int industryCode;
    char* industryDescription;
    double xCoordinate;
    double yCoordinate;
    char* location;

    struct node* next;
} node_t;

typedef node_t* node_ptr;
node_ptr creatNodes(FILE *fp);
void searchAndOutput(node_ptr dictHead, FILE *fp, char* whatToFind, char* outputFileName);

#endif //ASSIGNMENT_1__CODE_LIST_H
