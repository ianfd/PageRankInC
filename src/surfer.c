//
// Created by Ian F. Diks on 27.05.21.
//

#include "surfer.h"
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include "matrixUtils.h"
#include "data.h"
#include "stdbool.h"
#include "utils.h"
#include "graphUtils.h"

void runSurfer(GraphData *graphData, SurferData *surferData) {

    int currentPosition = -1;
    surferData->savedPosition = malloc(sizeof(int) * surferData->runs); // allocate enough memory to store all run data!
    // initial position, after that select random position (not saved in savedPosition)
    currentPosition = selectRandomPosition(graphData->size);
    for (int i = 0; i < surferData->runs; ++i) {
        if (hasOutgoingNodes(currentPosition, graphData, true)) {
            // do a random move to connected nodes
            if (doRandMove(surferData->p)) {
                // when you do a random move
                int randMove = selectRandomPosition(graphData->size);
                insertRun(i, randMove, surferData->savedPosition);
                currentPosition = randMove;
            } else {
                // do a move to connected nodes
                int randNode = getRandomOutgoingEdge(currentPosition, graphData);
                if (randNode != -1) {
                    insertRun(i, randNode, surferData->savedPosition);
                    currentPosition = randNode;
                } else {
                    fprintf(stderr, "An invalid random node has been delivered.");
                    exit(1);
                }
            }
        } else {
            // do random move
            int randMove = selectRandomPosition(graphData->size);
            insertRun(i, randMove, surferData->savedPosition);
            currentPosition = randMove;
        }
    }

    int *amountIDs = malloc(sizeof(int) * graphData->size);
    for (int i = 0; i < graphData->size; ++i) {
        int sumForID = 0;
        for (int j = 0; j < surferData->runs; ++j) {
            int tmp = surferData->savedPosition[j];
            if (tmp == i) {
                sumForID++;
            }
        }
        amountIDs[i] = sumForID;
    }

    for (int i = 0; i < graphData->size; ++i) {
        char* name = getNameFromID(i, graphData->size, graphData->nameIdPair);
        if (name != NULL) {
            double amount = (amountIDs[i] * 1.0) / surferData->runs;
            printf("%s %10.10f \n", name, amount);
            free(name);
        } else {
            exit(1);
        }
    }


}

void insertRun(int run, int toID, int *savedPositions) {
    savedPositions[run] = toID;
}


int selectRandomPosition(int size) {
    return randu(size);
}

bool doRandMove(double p) {
    int rand = randu(101); // generate num from 0 to 100
    double partial = rand / 100.0;
    if (p < partial) {
        // selects a linked page (when there are any!)
        return false;
    } else {
        // goes to a completely random page
        return true;
    }
}

bool hasOutgoingNodes(int position, GraphData *gd, bool includeSelfLink) {
    int *row = getTosFromIntMatrix(gd->size, position, gd->nodeLinks);
    if (row != NULL) {
        if (!includeSelfLink) row[position] = 0; // setting self link to zero so it is eliminated
        int sum = 0;
        for (int i = 0; i < gd->size; ++i) {
            int temp = row[i];
            sum = sum + temp;
        }
        return (sum > 0); //return true if sum is more than one
    } else {
        return false;
    }
}

int getRandomOutgoingEdge(int position, GraphData *gd) {
    int *row = getTosFromIntMatrix(gd->size, position, gd->nodeLinks);
    if (row != NULL) {
        // sum all weights together
        int sumOfWights = 0;
        for (int i = 0; i < gd->size; ++i) {
            int temp = row[i];
            sumOfWights = sumOfWights + temp;
        }
        // now randomize !
        int randomWeight = randu(sumOfWights);
        for (int i = 0; i < gd->size; ++i) {
            if (randomWeight < row[i]) {
                return i;
            }
            randomWeight = randomWeight - row[i];
        }
        return -1;
    } else {
        return -1;
    }

}
