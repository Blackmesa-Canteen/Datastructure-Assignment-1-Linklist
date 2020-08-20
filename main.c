#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void TraverseList(node_ptr h){
    node_ptr p = h->next;
    while(p != NULL){
        printf("%d\n",p->industryCode);
        p = p->next;
    }
}

int main(int argc, char  **argv) {

    char* inputFileName = NULL;
    char* outputFileName = NULL;
    char* whatToFind = NULL;
    size_t whatToFindNumber = 0;

    inputFileName = argv[1];
    outputFileName = argv[2];

    printf("Please input the the business name: \n");
    getline(&whatToFind, &whatToFindNumber, stdin);

    //Open the input file with the given filename for reading.
    printf("%s\n", inputFileName);
    FILE *fp = fopen(inputFileName, "r");

    if (!fp) {
        printf("can't opening file '%s'\n", inputFileName);
        return -1;
    }

    //creatList
    node_ptr dictList = creatNodes(fp);
    TraverseList(dictList);

    return 0;
}
