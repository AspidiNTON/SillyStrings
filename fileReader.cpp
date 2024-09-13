#include "fileReader.h"

void readTextBuffer(TextFile *textFile, const char *filename){
    struct stat sb;
    if (stat(filename, &sb) == -1) {
        printf("Failed to read file size\n");
        exit(EXIT_FAILURE);
    } else {
        textFile->size = sb.st_size;
        printf("%d\n", textFile->size);
        FILE *ptr = fopen(filename, "rb");
        textFile->buff = (char*)calloc(textFile->size + 1, sizeof(char));
        
    }
}