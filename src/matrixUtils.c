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

double getFromDoubleMatrix(int size, int x, int y, double *matrix) {
    if (size > x || size > y) {
        return matrix[(x + (y * size))];
    }
    return -1.0;
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
