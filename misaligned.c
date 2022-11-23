#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const char PairNum[] = "Pair Number |";
const char MajColor[] = "Major Color |";
const char MinColor[] = "Minor Color";
static char strpairIndex[15];
static char strMajIndex[15];

void AddSpaceFunc() {
if(strlen(strMajIndex)<(strlen(MajColor)-3)) {
    do {
        strcat(strMajIndex, " ");
        }while(strlen(strMajIndex)<(strlen(MajColor)-2));
     }
}

void CheckAlignPairNumFunc(int pairIndex) {
    sprintf(strpairIndex, "%11d", pairIndex);
    strcat(strpairIndex, " |");
    assert(strlen(strpairIndex)==strlen(PairNum));
}

void CheckAlignMajorColor(int i) {
    strcpy(strMajIndex, majorColor[i]);
    AddSpaceFunc();
    strcat(strMajIndex, " |");
    assert(strlen(strMajIndex)==strlen(MajColor));
}

int printColorMap() {
    int i = 0, j = 0, pairIndex=0;
    printf("%s %s %s\n", PairNum, MajColor, MinColor);
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            pairIndex = (i * 5 + j)+1;
            assert(pairIndex!=0);
            CheckAlignPairNumFunc(pairIndex);
            CheckAlignMajorColor(i);
            printf("%s %s %s\n", strpairIndex, strMajIndex, minorColor[j]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well\n");
    return 0;
}
