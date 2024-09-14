#ifndef FILE_READER_H
#define FILE_READER_H

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

struct TextFile{
    char *buff;
    int size;
    int stringCount;
    char **stringPointers;
    //char **stringEnds;
};

void readTextBuffer(TextFile *textFile, const char *filename);

void printTextInFile(TextFile *textFile, const char *filename);

#endif