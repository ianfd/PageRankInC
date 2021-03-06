//
// Created by Ian F. Diks on 26.05.21.
//

#include "matrixUtils.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int *initIntMatrix(int size) {
    int *matrix = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        matrix[i] = 0;
    }
    return matrix;
}

double *initDoubleMatrix(int size) {
    double *matrix = malloc(size * sizeof(double));
    for (int i = 0; i < size; ++i) {
        matrix[i] = 0.0;
    }
    return matrix;
}

// y is from, x is to
double getFromDoubleMatrix(int size, int x, int y, double *matrix) {
    if (size > x || size > y) {
        return matrix[(x + (y * size))];
    }
    return -1.0;
}

void insertToDoubleMatrix(int size, int from, int to, double value, double *matrix) {
    if (size > to || size > from) {
        matrix[(to  + from * size)] = value;
    } else {
        fprintf(stderr, "Tried to access unassigned matrix!");
    }
}

void incrementAtInt(int size, int x, int y, int *matrix) {
    if (size > x || size > y) {
        int temp = matrix[(x + (y * size))];
        matrix[(x + (y * size))] = temp + 1;
    } else {
        fprintf(stderr, "You tried to access an unknown region! w: %d h: %d size: %d", x, y, size);
    }
}

int getFromIntMatrix(int size, int x, int y, int *matrix) {
    if (size > x || size > y) {
        return matrix[(x + (y * size))];
    }
    return -1;
}

// gets all outgoing connections from a node with amount
int *getTosFromIntMatrix(int size, int to, int *matrix) {
    if (to < size) {
        int *retMatrix = malloc(sizeof(int) * size);
        for (int i = 0; i < size; ++i) {
            int valAtTo = matrix[(to * size + i)];
            retMatrix[i] = valAtTo;
        }
        return retMatrix;
    } else {
        fprintf(stderr, "You tried to access an unknown ID! (TO search) to: %d size: %d", to, size);
        return NULL;
    }
}

int *getFromsFromIntMatrix(int size, int from, int *matrix) {
    if (from < size) {
        int *retMatrix = malloc(sizeof(int) * size);
        for (int i = 0; i < size; ++i) {
            int valAtFrom = matrix[(i * size + from)];
            retMatrix[i] = valAtFrom;
        }
        return retMatrix;
    } else {
        fprintf(stderr, "You tried to access an unknown ID! (TO search) to: %d size: %d", from, size);
        return NULL;
    }
}
