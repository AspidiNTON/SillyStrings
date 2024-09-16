#ifndef FLAGS_H
#define FLAGS_H

#include <string.h>
#include <stdio.h>

#include "fileReader.h"
#include "sorter.h"
//#include "colorPrint.h"

struct flag {
    const char* shortName;
    const char* fullName;
    const char* description;
};

void checkFlags(int argc, const char *argv[], int flagsSize, const flag* flags);

#endif