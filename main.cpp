#include <stdlib.h>

#include "sorter.h"
#include "fileReader.h"
#include "flags.h"

const flag flagsQuad[] {
    {"-h", "--help", "shows avalible commands"},
    {"-i", "--input", "name of the input file to sort after the flag"},
    {"-o", "--output", "name of the output file after the flag"},
    {"-r", "--reverse", "reverse string sorting"}
};

int main(int argc, const char *argv[]) {
    int flagsSize = sizeof(flagsQuad) / sizeof(flag);
    checkFlags(argc, argv, flagsSize, flagsQuad);
    return 0;
}
