#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "myString.h"
#include "sorter.h"
#include "fileReader.h"

int main()
{
    TextFile onegin;
    readTextBuffer(&onegin, "onegin.txt");

    sort(onegin.stringPointers, onegin.stringCount, sizeof(char*), reverseStringComparator);

    printTextInFile(&onegin, "output.txt");

    //runDefaultTests();
    return 0;
}