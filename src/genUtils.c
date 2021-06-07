//
// Created by Ian F. Diks on 26.05.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "genUtils.h"

bool prefix(const char *pre, const char *str) {
    return strncmp(pre, str, strlen(pre)) == 0;
}

bool IsValidNumber(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        //ASCII value of 0 = 48, 9 = 57. So if value is outside of numeric range then fail
        //Checking for negative sign "-" could be added: ASCII value 45.
        if (string[i] < 48 || string[i] > 57)
            return false;
    }

    return true;
}

char *duplicateString(char *toCopy) {
    if (toCopy != NULL) {
        char *str = malloc(sizeof(char) + (strlen(toCopy) + 4));
        strcpy(str, toCopy);
        return str;
    } else {
        fprintf(stderr, "Failed to duplicate the string, it was NULL.\n");
        exit(1);
    }

}

void printHelp() {

    printf("[----------] HELP [----------]\n");
    printf("syntax: ./pagerank <OPTIONS> <PATH TO FILE>\n");
    printf("Available options:\n");
    printf("    -> -h => shows this help\n");
    printf("    -> -m <NUMBER> => runs a Marcow series <NUMBER> times\n");
    printf("    -> -r <NUMBER> => runs a simulation with <NUMBER> steps\n");
    printf("    -> -p <NUMBER> => sets p, <NUMBER> format: <NUMBER>%s\n", "%");
    printf("[----------] HELP [----------] \n");

}

void checkFile(char *filename) {
    if (filename != NULL) {
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            fprintf(stderr, "There can be no file found under: %s\n", filename);
            exit(1);
        }
        fclose(file);
    } else {
        fprintf(stderr, "There can be no file found under: %s\n", filename);
        exit(1);
    }


}

void removeChar(char *str, char garbage) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}
