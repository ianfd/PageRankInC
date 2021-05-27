//
// Created by Ian F. Diks on 27.05.21.
//

#include "statistics.h"
#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include "matrixUtils.h"
#include "fileParser.h"


void printStatistics(GraphData *graphData) {
    if (graphData != NULL) {
        printf("%s:\n", graphData->title);
        printf("- num nodes: %d\n", graphData->size);
        printf("- num edges: %d\n", graphData->amountEdges);
        int *max = malloc(sizeof(int));
        int *min = malloc(sizeof(int));
        calcMinMaxFrom(min, max, graphData);
        printf("- indegree: %d-%d \n", *min, *max);
        calcMinMaxTo(min, max, graphData);
        printf("- outdegree: %d-%d", *min, *max);
        free(min);
        free(max);
    } else {
        fprintf(stderr, "Graph data is null! ... aborting");
        exit(1);
    }
}

void calcMinMaxFrom(int *min, int *max, GraphData *graphData) {
    int currMax = 0;
    int currMin = -1;
    for (int i = 0; i < graphData->size; ++i) {
        int *row = getFromsFromIntMatrix(graphData->size, i, graphData->nodeLinks);
        int sum = sumUp(row, graphData->size);
        if (currMin < 0) currMin = sum;
        if (currMax < sum) currMax = sum;
        if (currMin > sum) currMin = sum;
        free(row);
    }
    *min = currMin;
    *max = currMax;
}

void calcMinMaxTo(int *min, int *max, GraphData *graphData) {
    int currMax = 0;
    int currMin = -1;
    for (int i = 0; i < graphData->size; ++i) {
        int *row = getTosFromIntMatrix(graphData->size, i, graphData->nodeLinks);
        int sum = sumUp(row, graphData->size);
        if (currMin < 0) currMin = sum;
        if (currMax < sum) currMax = sum;
        if (currMin > sum) currMin = sum;
    }
    *min = currMin;
    *max = currMax;

}

int sumUp(int *row, int size) {
    int s = 0;
    for (int i = 0; i < size; ++i) {
        int cur = row[i];
        s = s + cur;
    }
    return s;
}


