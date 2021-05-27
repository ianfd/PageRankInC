//
// Created by Ian F. Diks on 26.05.21.
//

#ifndef IANFD_FILEPARSER_H
#define IANFD_FILEPARSER_H

#include "data.h"
#include "stdio.h"

GraphData *initGraphData();

char* parseFileHeader(FILE *file, char *tit);

GraphData *parseGraphContent(FILE *file, NameIDPair *nip, NodeLinkPair *nl, int *nlSize, int *nlIncrement, int *regSize,
                             int *regIncrement);

void printRegistry(int size, NameIDPair *nid);

GraphData *parseGraphFile(char *filename);

NodeLinkPair *nlpInit(const int *sizeOfNlpArray);

NameIDPair *nidInit(const int *sizeOfNidArray);

void printLinkMatrix(int size, int *matrix);

#endif //IANFD_FILEPARSER_H
