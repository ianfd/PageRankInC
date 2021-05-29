//
// Created by Ian F. Diks on 29.05.21.
//

#include "matrixUtils.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include "surfer.h"
#include "markow.h"
#include "graphUtils.h"

void doMarkow(GraphData *gd, MarkowData *md) {


    initProbMatrix(gd, md);
    runMarkowCalc(gd, md);

    for (int i = 0; i < gd->size; ++i) {
        char *name = getNameFromID(i, gd->size, gd->nameIdPair);
        if (name != NULL) {
            printf("%s %10.10f \n", name, md->probVector[i]);
            free(name);
        } else {
            exit(1);
        }
    }

    free(md->probMatrix); // freeing propability matrix
    free(md->probVector); // freeing prob vector
    free(md); // freeing markow data
}

void runMarkowCalc(GraphData *gd, MarkowData *md) {

    // initiate the prob vector
    double onebyN = (1.0 / gd->size);
    for (int i = 0; i < gd->size; ++i) {
        md->probVector[i] = onebyN;
    }

    // run prob vector calcs
    double *tempProbVec = malloc(sizeof(double) * gd->size);
    for (int i = 0; i < md->rounds; ++i) {
        for (int j = 0; j < gd->size; ++j) {
            double sum = 0.0;
            for (int k = 0; k < gd->size; ++k) {
                sum = sum + md->probVector[k] * getFromDoubleMatrix(gd->size, j, k, md->probMatrix);
            }
            tempProbVec[j] = sum;
        }

        // tansfer old prob vec to new
        for (int j = 0; j < gd->size; ++j) {
            md->probVector[j] = tempProbVec[j];
        }

    }
    free(tempProbVec);


}


void initProbMatrix(GraphData *gd, MarkowData *md) {
    for (int i = 0; i < gd->size; ++i) {
        // i is from
        int getOutGoing = 0;
        int *row = getTosFromIntMatrix(gd->size, i, gd->nodeLinks);
        for (int k = 0; k < gd->size; ++k) {
            int temp = row[k];
            getOutGoing = getOutGoing + temp;
        }
        free(row); // dont need it anymore
        for (int j = 0; j < gd->size; ++j) {
            // j is to
            if (hasOutgoingNodes(i, gd, true)) {
                double prob = 0.0;
                int outgoingTo = getFromIntMatrix(gd->size, j, i, gd->nodeLinks);
                double pn = (md->p / gd->size);
                prob = pn + ((1 - md->p) * outgoingTo / (getOutGoing));
                //printf("Prob from %d to %d, value %f\n", i, j, prob);
                insertToDoubleMatrix(gd->size, i, j, prob, md->probMatrix);
            } else {
                double prob = (1.0 / gd->size);
                insertToDoubleMatrix(gd->size, i, j, prob, md->probMatrix);
            }

        }
    }
}
