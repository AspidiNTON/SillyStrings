#include "sorter.h"

int binarySearch(void *base, void *elem, size_t elemSize, int l, int r, compareFunction comporator) {
    
    while (l < r) {
        size_t m = l + (r - l) / 2;
        if ((*comporator)((char*)base + m * elemSize, (char*)elem)) l = m + 1;
        else r = m;
    }
    return l;
}

void assign(void *f, void *s, size_t elemSize) {
    for (size_t i = 0; i < elemSize; ++i) {
        *((char*)f + i) = *((char*)s + i);
    }
}

void sort(void *base, size_t n, size_t elemSize, compareFunction comporator){
    int i, loc, j;
    void *s = calloc(elemSize, sizeof(char));
    for (i = 1; i < (int)n; ++i) {
        j = i - 1;
        for (int k = 0; k < (int)elemSize; ++k) *((char*)s + k) = *((char*)base + i * elemSize + k);

        loc = binarySearch(base, s, elemSize, 0, i, comporator);

        while (j >= loc) {
            assign((char*)base + (j + 1) * elemSize, (char*)base + j * elemSize, elemSize);
            --j;
        }
        assign((char*)base + (j + 1) * elemSize, (char*)s, elemSize);
    }
}

bool stringComparator(void *f, void *s){
    char *x = *(char**)f;
    char *y = *(char**)s;
    while (*x != '\0' && *y != '\0') {
        while (*x != '\0' && !isalpha(*x)) ++x;
        if (*x == '\0') break;
        while (*y != '\0' && !isalpha(*y)) ++y;
        if (*y == '\0') break;
        if (tolower(*x) == tolower(*y)) {
            ++x;
            ++y;
            continue;
        }
        if (tolower(*x) < tolower(*y)) return true;
        else return false;
    }
    if (*x == '\0' && *y == '\0') return false;
    if (*x == '\0') return true;
    else return false;
}

bool intComp(void *f, void *s){
    int x = *(int*)f;
    int y = *(int*)s;
    return x < y;
}