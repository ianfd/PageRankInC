//
// Created by Ian F. Diks on 26.05.21.
//

#ifndef IANFD_MATRIXUTILS_H
#define IANFD_MATRIXUTILS_H


int *initIntMatrix(int size);

double *initDoubleMatrix(int size);

double getFromDoubleMatrix(int size, int h, int w, double *matrix);

int getFromIntMatrix(int size, int h, int w, int *matrix);

void incrementAtInt(int size, int x, int y, int *matrix);

int *getTosFromIntMatrix(int size, int to, int *matrix);

int *getFromsFromIntMatrix(int size, int from, int *matrix);

#endif //IANFD_MATRIXUTILS_H
