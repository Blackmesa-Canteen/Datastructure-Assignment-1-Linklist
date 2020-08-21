/**
 *  Created by Xiaotian Li on 8/21/2020.
 *
 *  This program is a simple dictionary based on a linked list to store information from
 *  the City of Melbourne Census of Land Use and Employment (CLUE). A user can search this
 *  dictionary to retrieve information about businesses in Melbourne using the business name.
 *
 *  Input:
 *  This program takes two command line arguments: (1) the name of the source file (the .csv file
 *  stores CLUE data), and (2) the name of an output file. When the program is running, a user
 *  could input one business name (key) from the screen at a time. The program keeps asking the
 *  user to enter key values until 'quit!' is typed.
 *
 *  Output:
 *  program will look up each key and output the matched record to the output file specified by
 *  the second command line parameter. If the key is not found, NOT FOUND would be output.
 *
 *  Input Example 1:                       Input Example2:
 *  ~$ dict test.csv out.txt               ~$ dict test.csv out.txt < keyfile
 *  ~$ Vacant
 *  ~$ Hello, world
 *     ...
 *  ~$ quit!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "dictFunctions.h"

int main(int argc, char  **argv) {

    char* inputFileName = NULL;
    char* outputFileName = NULL;
    char* keyFileName = NULL;
    char* whatToFind = NULL;
    const char quitCommend[] = "quit!";
    size_t whatToFindNumber = 0;

    if (argc == 3) {
        inputFileName = argv[1];
        outputFileName = argv[2];
    }
    else if (argc == 5 && !strcmp(argv[3], "<")){
        inputFileName = argv[1];
        outputFileName = argv[2];
        keyFileName = argv[4];
    } else {
        printf("ERROR: Insufficient parameters!\n");
        exit(1);
    }

    /* Open the input file with the given filename for reading */
    FILE *fp = fopen(inputFileName, "r");
    if (!fp) {
        printf("can't opening file '%s'\n", inputFileName);
        return -1;
    }

    /* creat link List that contains data */
    node_ptr dictList = creatNodes(fp);
    fclose(fp);

    /* creat output file */
    fp = fopen(outputFileName, "w");
    if (!fp) {
        printf("can't create file '%s'\n", outputFileName);
        exit(1);
    }

    while(1) {
        fflush(stdin);
        printf("\n$ Please input a business name to "
               "search (input \"quit!\" to stop input): ");
        getline(&whatToFind, &whatToFindNumber, stdin);
        trimLastEnter(whatToFind); /* trim '\n' at the end of the string */
        if (!strcmp(quitCommend, whatToFind)) {
            printf("End of searching\n");
            break;
        }

        /* search link list and creat output file */
        searchAndOutput(dictList, fp, whatToFind);
    }
    freeList(dictList);
    free(whatToFind);
    fclose(fp);
    printf("*********Thank you for using. *********\n");
    fflush(stdout);

    return 0;
}
