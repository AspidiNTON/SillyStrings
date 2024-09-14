#include "fileReader.h"

void readTextBuffer(TextFile *textFile, const char *filename){
    struct stat sb;
    if (stat(filename, &sb) == -1) {
        printf("Failed to read file size\n");
        exit(EXIT_FAILURE);
    } else {
        textFile->size = sb.st_size;
        textFile->buff = (char*)calloc(textFile->size + 2, sizeof(char));
        FILE *ptr = fopen(filename, "rb");
        fread(textFile->buff + 1, sizeof(char), textFile->size, ptr);
        fclose(ptr);
        textFile->stringCount = 0;
        for (int i = 1; i <= textFile->size; ++i) {
            if (textFile->buff[i] == '\r' || textFile->buff[i] == '\n'){
                textFile->buff[i] = '\0';
            } else if (textFile->buff[i - 1] == '\0') ++textFile->stringCount;
        }
        textFile->stringPointers = (char**)calloc(textFile->stringCount, sizeof(char*));
        //textFile->stringEnds = (char**)calloc(textFile->stringCount, sizeof(char*));
        int x = 0, y = 0;
        for (int i = 1; i <= textFile->size; ++i) {
            if (textFile->buff[i] != '\0' && textFile->buff[i - 1] == '\0'){
                textFile->stringPointers[x++] = &textFile->buff[i];
            }
            /*if (textFile->buff[i] != '\0' && textFile->buff[i + 1] == '\0'){
                textFile->stringEnds[y++] = &textFile->buff[i];
            }*/
        }
    }
}

void printTextInFile(TextFile *textFile, const char *filename){
    FILE *ptr = fopen("output.txt", "w");
    for (int i = 0; i < textFile->stringCount; ++i) {
        fputs(textFile->stringPointers[i], ptr);
        putc('\n', ptr);
    }
    fclose(ptr);
}