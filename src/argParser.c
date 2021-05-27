//
// Created by Ian F. Diks on 26.05.21.
//

#include "argParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "utils.h"
#include "genUtils.h"

void argParsers(unsigned argc, char *const *argv, PRData *prData) {

    for (unsigned i = 1; i < argc; ++i) {
        // parsing through all arguments
        if (argv[i] != NULL) {
            if (argv[i][0] == '-') {
                // when the argument is a command parameter
                char commandParameter = argv[i][1];
                // when one is - the second one should be h, m, p, r or s
                switch (commandParameter) {
                    case 'h':
                        prData->outputHelp = true;
                        break;
                    case 'm':
                        // enable markow series with N (i+1) steps
                        if ((argv[(i + 1)] != NULL)) {
                            if (IsValidNumber(argv[(i + 1)])) {
                                int n = atoi(argv[(i + 1)]);
                                if (n > 0) {
                                    // the value is bigger than 0
                                    prData->n = n;
                                    prData->outputMarkowChain = true;
                                    i++;
                                } else {
                                    // the value n is not acceptable
                                    fprintf(stderr,
                                            "The parameter -m needs a number greater than 0, you've provided %d'.",
                                            n);
                                    fprintf(stderr, "For more information type: %s -h", argv[0]);
                                    exit(1);
                                }
                            } else {
                                // output that if the provided value is not a number
                                fprintf(stderr, "The parameter -m needs a number, you've provided '%s'.",
                                        argv[(i + 1)]);
                                fprintf(stderr, "For more information type: %s -h", argv[0]);
                                exit(1);
                            }
                        } else {
                            fprintf(stderr, "The parameter -m needs a number.");
                            exit(1);
                        }

                        break;
                    case 'r':
                        // enable simulation series with N (i+1) steps
                        if (argv[(i + 1)] != NULL) {
                            if (IsValidNumber(argv[(i + 1)])) {
                                int n = atoi(argv[(i + 1)]);
                                if (n > 0) {
                                    // the value is bigger than 0
                                    prData->n = n;
                                    prData->outputSimulation = true;
                                    i++;
                                } else {
                                    // the value n is not acceptable
                                    fprintf(stderr,
                                            "The parameter -r needs a number greater than 0, you've provided %d'.",
                                            n);
                                    fprintf(stderr, "For more information type: %s -h", argv[0]);
                                    exit(1);
                                }
                            } else {
                                // output that if the provided value is not a number
                                fprintf(stderr, "The parameter -r needs a number, you've provided '%s'.",
                                        argv[(i + 1)]);
                                fprintf(stderr, "For more information type: %s -h", argv[0]);
                                exit(1);
                            }
                        } else {
                            fprintf(stderr, "The parameter -m needs a number.");
                            exit(1);
                        }

                        break;
                    case 'p':
                        if (argv[(i + 1)] != NULL) {
                            if (IsValidNumber(argv[(i + 1)])) {
                                int n = atoi(argv[(i + 1)]);
                                if (n > 0 && n <= 100) {
                                    // the value is bigger than 0
                                    prData->p = n / 100.0;
                                    i++;
                                } else {
                                    // the value n is not acceptable
                                    fprintf(stderr,
                                            "The parameter -p needs a number > 0 and <= 100, you've provided %d'.",
                                            n);
                                    fprintf(stderr, "For more information type: %s -h", argv[0]);
                                    exit(1);
                                }
                            } else {
                                // output that if the provided value is not a number
                                fprintf(stderr, "The parameter -p needs a number, you've provided '%s'.",
                                        argv[(i + 1)]);
                                fprintf(stderr, "For more information type: %s -h", argv[0]);
                                exit(1);
                            }
                        } else {
                            fprintf(stderr, "The parameter -m needs a number.");
                            exit(1);
                        }
                        break;
                    case 's':
                        prData->outputStatistics = true;
                        break;
                }

            } else {
                char *filename = argv[i];
                prData->file = duplicateString(filename); // save the duplicate with dynamic memory allocation
                prData->fileProvided = true;

            }
        } else {
            printf("arg is null");
        }
    }
}
