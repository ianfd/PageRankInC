//
// Created by Ian F. Diks on 26.05.21.
//

#ifndef IANFD_GRAPHUTILS_H
#define IANFD_GRAPHUTILS_H

#include "data.h"
#include <string.h>

bool nodeExists(int size, char* name, NameIDPair* registry);
char* getNameFromID(unsigned int id, int size, NameIDPair* registry);
int registerNewNode(int *increment, char *name, NameIDPair *registry, int *registrySize); // with failsafe
NameIDPair *initRegistry();
bool existsID(unsigned int id, int size, NameIDPair *registry);
int getIDFromName(int size, char *name, NameIDPair *registry);
NodeLinkPair* initNodeLinks();
void registerNodeLink(int from, int to, int *nlIncrement, NodeLinkPair *nl);

#endif //IANFD_GRAPHUTILS_H
