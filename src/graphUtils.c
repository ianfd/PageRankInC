//
// Created by Ian F. Diks on 26.05.21.
//

#include "graphUtils.h"
#include "genUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool nodeExists(int size, char *name, NameIDPair *registry) {
    //fprintf(stderr, "DEBUG | EXISTS (ID) | Searching: %s - size: %d \n", name, size);
    for (int i = 0; i < size; ++i) {
        //fprintf(stderr, "DEBUG | EXISTS (ID) | Searching: %s - found: %s \n", name, registry[i].name);
        int ret = strcmp(name, registry[i].name);
        if (ret == 0) {
            // when the strings to matchfprintf(stderr, "DEBUG | EXISTS (ID) | Searching: %s - size: %d - FOUND \n", name, size);
            return true;
        }
    }
    return false;
}

char *getNameFromID(unsigned int id, int size, NameIDPair *registry) {
    return NULL;
}

int getIDFromName(int size, char *name, NameIDPair *registry) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(name, registry[i].name) == 0) {
            // when the strings to match
            return i;
        }
    }
    return -1;
}

bool existsID(unsigned int id, int size, NameIDPair *registry) {

    return NULL;
}

int registerNewNode(int *increment, char *name, NameIDPair *registry, int *registrySize) {
    if (nodeExists((*increment) + 1, name, registry)) {
        return getIDFromName((*increment) + 1, name, registry);
    } else {
        int newID = (*increment) + 1;
        registry[newID].name = duplicateString(name);
        registry[newID].id = newID;
        *increment = newID;
        return newID;
    }
}

NameIDPair *initRegistry() {
    return NULL;
}


// NODE LINKS STUFF

void registerNodeLink(int from, int to, int *nlIncrement, NodeLinkPair *nl) {
    int newID = (*nlIncrement) + 1;
    nl[newID].to = to;
    nl[newID].from = from;
    *(nlIncrement) = newID;
    fprintf(stderr, "DEBUG | LINK | CREATE from: %d - to: %d\n", from, to);
}

NodeLinkPair *initNodeLinks() {
    return NULL;
}



