//
// Created by Ian F. Diks on 26.05.21.
//

#ifndef IANFD_GENUTILS_H
#define IANFD_GENUTILS_H


#include <stdbool.h>
#include "data.h"

bool prefix(const char *pre, const char *str);
bool IsValidNumber(char *string);
char* duplicateString(char* toCopy);
void printHelp();
void checkFile(char* filename);
void removeChar(char *str, char garbage);
#endif //IANFD_GENUTILS_H
