//
// Created by Ian F. Diks on 26.05.21.
//

#include "fileParser.h"
#include "graphUtils.h"
#include "genUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "matrixUtils.h"

//

GraphData *parseGraphFile(char *filename) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "The file you provided is not available! Please check your path!");
        exit(1);
    }
    // init both
    char title[300];
    int sizeOfNidArray = 2;
    int sizeOfNlpArray = 2;
    NameIDPair *nameIdPair = nidInit(&sizeOfNidArray);
    NodeLinkPair *nodeLinkPair = nlpInit(&sizeOfNlpArray);
    int nidIncrement = -1;
    int nlpIncrement = -1;
    GraphData *graphData = initGraphData();
    // parse the graph data!!
    graphData->title = parseFileHeader(file, title);
    bool doParse = true;
    while (doParse) {
        if (nidIncrement + 2 >= sizeOfNidArray) {
            sizeOfNidArray = (sizeOfNidArray) * 2;
            nameIdPair = realloc(nameIdPair, sizeof(nameIdPair[0]) * (sizeOfNidArray));
        }
        if (nlpIncrement +2 >= sizeOfNlpArray) {
            sizeOfNlpArray = (sizeOfNlpArray) * 2;
            nodeLinkPair = realloc(nodeLinkPair, sizeof(nodeLinkPair[0]) * (sizeOfNlpArray));
        }
        char fromID[260];
        char toID[260];
        if (fscanf(file, "%s -> %s;", fromID, toID) == 2) {
            removeChar(fromID, ';'); // cleaning up the ids
            removeChar(toID, ';'); // cleaning up the ids
            int from = registerNewNode(&nidIncrement, fromID, nameIdPair, &sizeOfNidArray);
            int to = registerNewNode(&nidIncrement, toID, nameIdPair, &sizeOfNidArray);
            registerNodeLink(from, to, &nlpIncrement, nodeLinkPair);
        } else {
            if (strcmp("}", fromID) == 0) {
                doParse = false;
            } else {
                fprintf(stderr, "Failed to parse the file! ... aborting");
                exit(1);
            }
        }
    }
    int* linkMatrix;
    int amountOfIdentifiers = nidIncrement + 1; // amount of unique ID
    int amountOfLinks = nlpIncrement + 1;
    linkMatrix = initIntMatrix(amountOfIdentifiers * amountOfIdentifiers); // amount of identifiers squared
    for (int i = 0; i < amountOfLinks; ++i) {
        NodeLinkPair linkPair = nodeLinkPair[i];
        incrementAtInt(amountOfIdentifiers, linkPair.to, linkPair.from, linkMatrix);
    }
    free(nodeLinkPair);
    //printLinkMatrix(amountOfIdentifiers, linkMatrix);
    graphData->nodeLinks=linkMatrix;
    graphData->size = amountOfIdentifiers;
    graphData->nameIdPair = nameIdPair;

    return graphData;
}

void printRegistry(int size, NameIDPair *nid) {
    if (nid != NULL) {
        for (int i = 0; i < size; ++i) {
            printf("ID: %d | Name: %s\n", nid[i].id, nid[i].name);
        }
    }
}


char* parseFileHeader(FILE *file, char *tit) {
    char title[300]; // initial title size, will be adapted later
    if (fscanf(file, "digraph %s {", title) != 1) {
        fprintf(stderr, "Failed to parse the header of the file! ... aborting");
        exit(1);
    } else {
        return duplicateString(title);
    }
    return NULL;
}


GraphData *initGraphData() {
    GraphData *gd = malloc(sizeof(GraphData));
    gd->size = 0;
    gd->nameIdPair = NULL;
    gd->nodeLinks = NULL;
    return gd;
}



NameIDPair *nidInit(const int *sizeOfNidArray) {
    return malloc(sizeof(NameIDPair) * (*sizeOfNidArray));
}

NodeLinkPair *nlpInit(const int *sizeOfNlpArray) {
    return malloc(sizeof(NodeLinkPair) * (*sizeOfNlpArray));
}

void printLinkMatrix(int size, int* matrix) {
    printf("\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("| %4d ", getFromIntMatrix(size, j, i, matrix));
        }
        printf(" | \n");
    }
}

