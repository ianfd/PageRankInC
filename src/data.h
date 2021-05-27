//
// Created by Ian F. Diks on 26.05.21.
//

#ifndef IANFD_DATA_H
#define IANFD_DATA_H

#include "stdbool.h"

struct PRData {
    bool outputStatistics;
    bool outputSimulation;
    bool outputMarkowChain;
    bool outputHelp;
    bool fileProvided;
    double p;
    int n;
    char *file;
};

struct NameIDPair {
    int id;
    char *name;
};

typedef struct NameIDPair NameIDPair;

// all information from the file parse
struct GraphData {
    char* title; // title of the graph
    int *nodeLinks; // link of all nodes
    NameIDPair* nameIdPair; // link node ID to node name
    int size; // will be initiated with 0
};
typedef struct GraphData GraphData;

struct NodeLinkPair{
    unsigned int from; // id of from node
    unsigned int to; // id of to node
};

typedef struct NodeLinkPair NodeLinkPair;

typedef struct PRData PRData;

// Defining all data required for the Markow series
struct MarkowData {
    GraphData *graph;
    double *probMatrix; // probability matrix
    double *probVector; // probability vector for current position will be calculated with the matrix
    int rounds; // how many rounds should this calculation have
};

typedef struct MarkowData MarkowData;

struct SurferData {
    GraphData *graphData;
};

typedef struct SurferData SurferData;

#endif //IANFD_DATA_H
