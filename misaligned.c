#include <stdio.h>
#include <assert.h>


const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const int numOfMajColors = sizeof(majorColor) / sizeof(majorColor[0]);
const int numOfMinColors = sizeof(minorColor) / sizeof(minorColor[0]);
const int totColors = numOfMajColors * numOfMinColors;

void evaluationColorMap(int pairIndex) {
    static int correctPairNumIdx = 0;
    assert(pairIndex == correctPairNumIdx);
    assert(pairIndex <= totColors);
    printf("%d == %d ? Tot colors %d\n", pairIndex, correctPairNumIdx, totColors);
    correctPairNumIdx++;
}


int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0, pairIndex=0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            pairIndex = (i * 5 + j);
            printf("%d | %s | %s\n", pairIndex, majorColor[i], minorColor[i]);
            evaluationColorMap(pairIndex);
        }
    }
    assert(pairIndex == (i*j));
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == totColors);
    printf("All is well (maybe!)\n");
    return 0;
}
