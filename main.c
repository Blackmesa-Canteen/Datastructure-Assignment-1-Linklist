#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "dictFunctions.h"

int main(int argc, char  **argv) {
    char* inputFileName = NULL;
    char* outputFileName = NULL;
    char* whatToFind = NULL;
    char quitCommend[] = "quit!";
    size_t whatToFindNumber = 0;

    // catch commandline;
    inputFileName = argv[1];
    outputFileName = argv[2];

    // Open the input file with the given filename for reading;
    FILE *fp = fopen(inputFileName, "r");
    if (!fp) {
        printf("can't opening file '%s'\n", inputFileName);
        return -1;
    }

    // creatList;
    node_ptr dictList = creatNodes(fp);
    fclose(fp); // close the input csv fie;

    // creat output file;
    fp = fopen(outputFileName, "w");
    if (!fp) {
        printf("can't create file '%s'\n", outputFileName);
        exit(1);
    }
    while(1) {
        fflush(stdin);
        printf("\n$ Please input the the business name to search (input \"quit!\" to stop input): ");
        getline(&whatToFind, &whatToFindNumber, stdin);
        trimLastEnter(whatToFind);
        if (!strcmp(quitCommend, whatToFind)) {
            printf("End of searching\n");
            break;
        }
        searchAndOutput(dictList, fp, whatToFind, outputFileName); //search and output;
    }
    printf("*********Thank you for using. *********\n");
    free(dictList);
    fclose(fp);
    return 0;
}
