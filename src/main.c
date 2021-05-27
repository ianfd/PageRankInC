/*
 * main.c
 *
 * Programmierung 2 - Projekt 3 (PageRank)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "utils.h"
#include "genUtils.h"
#include "matrixUtils.h"
#include "argParser.h"
#include "data.h"
#include "fileParser.h"

PRData *initPrData();

int main(int argc, char *const *argv) {
    // defining the default dataStorage for the pagerank data.
    PRData *prGeneralInformation = initPrData();
    GraphData *gd;

    // initialize the random number generator
    rand_init();

    argParsers(argc, argv, prGeneralInformation);

    if (prGeneralInformation->fileProvided) {
        checkFile(prGeneralInformation->file);
    } else {
        fprintf(stderr, "You didn't provide a file! ... aborting \n");
        exit(1);
    }
    // ------------------------------- end argument parser -------------------------------

    // check the starting procedure

    if (prGeneralInformation->outputHelp) {
        // when to output help!
        printHelp();
    } else if (prGeneralInformation->outputMarkowChain) {
        // when executing the Markow chain
        gd = parseGraphFile(prGeneralInformation->file);
        printf("Title: %s", gd->title);
        printLinkMatrix(gd->size, gd->nodeLinks);
        return 0;
    } else if (prGeneralInformation->outputSimulation) {
        // when executing the simulation


    } else {

    }


    exit(0);
}

PRData *initPrData() {
    PRData *returnPr = malloc(sizeof(PRData));
    returnPr->outputHelp = false;
    returnPr->outputMarkowChain = false;
    returnPr->outputSimulation = false;
    returnPr->outputStatistics = false;
    returnPr->fileProvided = false;
    returnPr->p = 0.1;
    returnPr->n = 0;
    return returnPr;
}



