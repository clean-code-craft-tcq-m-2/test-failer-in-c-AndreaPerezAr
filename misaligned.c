#include <stdio.h>
#include <assert.h>
#include <string.h>

#define FIRSTBLOCK 12
#define SECONDBLOCK 12

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const char PairNum[] = "Pair Number |";
const char MajColor[] = "Major Color |";
const char MinColor[] = "Minor Color";
char strpairIndex[12];
char strMajIndex[12];

int printColorMap() {
    int i = 0, j = 0, pairIndex=0;
    char strMajIndex[12] = {0};
    printf("%s %s %s\n", PairNum, MajColor, MinColor);
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            pairIndex = (i * 5 + j);
            sprintf(strpairIndex, "%d", pairIndex);
            strcat(strpairIndex, " |");
            strcpy(strMajIndex, majorColor[i]);
            strcat(strMajIndex, " |");
            printf("%s %s %s\n", strpairIndex, strMajIndex, minorColor[i]);
            assert(strlen(strpairIndex)==strlen(PairNum));
            assert(strlen(strMajIndex)==strlen(MajColor));
        }
    }
    assert(pairIndex == (i*j));
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
