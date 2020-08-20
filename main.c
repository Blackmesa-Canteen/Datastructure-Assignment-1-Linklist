#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

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
    FILE *fp = fopen(inputFileName, "r");

    if (!fp) {
        printf("can't opening file '%s'\n", inputFileName);
        return -1;
    }

    //creatList
    node_ptr dictList = creatNodes(fp);


    return 0;
}
