#include "flags.h"


int checkFlags(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData){
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], flags[0].fullName) == 0 || strcmp(argv[i], flags[0].shortName) == 0) {
            for (int j = 0; j < flagsSize; ++j) {
                printf("%s %s: %s\n", flags[j].shortName, flags[j].fullName, flags[j].description);
            }
            return 1;
        }
        if (strcmp(argv[i], flags[1].fullName) == 0 || strcmp(argv[i], flags[1].shortName) == 0) {
            if (i + 1 < argc) {
                ++i;
                strncpy(fileFlagData->inputFilename, argv[i], 80);
            } else {
                printf("No input filename provided\n");
                return 2;
            }
        }
        else if (strcmp(argv[i], flags[2].fullName) == 0 || strcmp(argv[i], flags[2].shortName) == 0) {
            if (i + 1 < argc) {
                ++i;
                strncpy(fileFlagData->outputFilename, argv[i], 80);
            } else {
                printf("No output filename provided\n");
                return 2;
            }
        }
        else if (strcmp(argv[i], flags[3].fullName) == 0 || strcmp(argv[i], flags[3].shortName) == 0) {
            fileFlagData->isReverse = true;
        } else {
            printf("Unknown Flag: %s\n", argv[i]);
            return 2;
        }
    }
    return 0;
}