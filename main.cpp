#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "myString.h"
#include "sorter.h"
#include "fileReader.h"

int main()
{
    FILE *ptr = fopen("onegin.txt", "r");
    char* v[7000];
    char buff[600];
    int n = 0;
    while (fileGetline(buff, 600, ptr) != EOF) {
        v[n++] = strdup(buff);
    }
    fclose(ptr);


    TextFile onegin;
    readTextBuffer(&onegin, "onegin.txt");



    sort((void**)v, n, sizeof(char*), stringComparator);
    ptr = fopen("output.txt", "w");
    for (int i = 0; i < n; ++i) {
        fputs(v[i], ptr);
        putc('\n', ptr);
    }
    fclose(ptr);
    //runDefaultTests();
    return 0;
}