//
// Created by Ian F. Diks on 27.05.21.
//

#ifndef IANFD_SURFER_H
#define IANFD_SURFER_H

#include "data.h"
#include "stdbool.h"

bool hasOutgoingNodes(int position, GraphData *gd, bool includeSelfLink);

void runSurfer(GraphData *graphData, SurferData *surferData);

int selectRandomPosition(int size);

void insertRun(int run, int toID, int *savedPositions);

bool doRandMove(double p);

int getRandomOutgoingEdge(int position, GraphData *gd);

#endif //IANFD_SURFER_H
