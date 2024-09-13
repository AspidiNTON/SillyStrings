#ifndef FILE_READER_H
#define FILE_READER_H

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

struct TextFile{
    char *buff;
    int size;
    int stringCount;
    char **text;
    char **stringEnds;
};

void readTextBuffer(TextFile *textFile, const char *filename);


#endif