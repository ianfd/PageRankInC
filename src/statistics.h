//
// Created by Ian F. Diks on 27.05.21.
//

#ifndef IANFD_STATISTICS_H
#define IANFD_STATISTICS_H

#include "data.h"

int sumUp(int *row, int size);

void calcMinMaxTo(int *min, int *max, GraphData *graphData);

void printStatistics(GraphData *graphData);

void calcMinMaxFrom(int *min, int *max, GraphData *graphData);

#endif //IANFD_STATISTICS_H
