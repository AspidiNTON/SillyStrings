#include "flags.h"


void checkFlags(int argc, const char *argv[], int flagsSize, const flag* flags){
    char inputFilename[80] = "input.txt";
    char outputFilename[80] = "output.txt";
    bool reversedSorting = false;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], flags[0].fullName) == 0 || strcmp(argv[i], flags[0].shortName) == 0) {
            for (int j = 0; j < flagsSize; ++j) {
                printf("%s %s: %s\n", flags[j].shortName, flags[j].fullName, flags[j].description);
            }
            return;
        }
        if (strcmp(argv[i], flags[1].fullName) == 0 || strcmp(argv[i], flags[1].shortName) == 0) {
            if (i + 1 < argc) {
                ++i;
                strncpy(inputFilename, argv[i], 80);
            } else {
                printf("No input filename provided\n");
            }
        }
        else if (strcmp(argv[i], flags[2].fullName) == 0 || strcmp(argv[i], flags[2].shortName) == 0) {
            if (i + 1 < argc) {
                ++i;
                strncpy(outputFilename, argv[i], 80);
            } else {
                printf("No output filename provided\n");
            }
        }
        else if (strcmp(argv[i], flags[3].fullName) == 0 || strcmp(argv[i], flags[3].shortName) == 0) {
            reversedSorting = true;
        } else {
            printf("Unknown flag: %s\n", argv[i]);
            return;
        }
    }

    TextFile onegin = {};
    fileErrorType err = readTextBuffer(&onegin, inputFilename);
    switch(err){
        case ERROR_FAILED_TO_READ_FILE_STATS:
            printf("Failed to read %s file stats\n", inputFilename);
            return;
        case ERROR_FAILED_TO_CALLOC:
            printf("Failed to allocate buffer\n");
            return;
        case ERROR_FAILED_TO_OPEN_FILE:
            printf("Failed to open %s\n", inputFilename);
            return;
        default:
            break;
    }

    sort(onegin.stringPointers, onegin.stringCount, sizeof(char*), reversedSorting ? reverseStringComparator : stringComparator);

    if (printTextInFile(&onegin, outputFilename) == ERROR_FAILED_TO_OPEN_FILE) {
        printf("Failed to open %s\n", outputFilename);
            return;
    }
}