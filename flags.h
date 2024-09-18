#ifndef FLAGS_H
#define FLAGS_H

#include <string.h>
#include <stdio.h>

#include "fileReader.h"
#include "sorter.h"
//#include "colorPrint.h"

struct Flag {
    const char* shortName;
    const char* fullName;
    const char* description;
};

struct FileFlagData {
    bool isReverse = false;
    char inputFilename[80] = "input.txt";
    char outputFilename[80] = "output.txt";
};

int checkFlags(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData);

#endif