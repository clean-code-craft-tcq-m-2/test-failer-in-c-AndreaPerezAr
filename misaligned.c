#include <stdio.h>
#include <assert.h>

void evaluationColorMap(int pairIndex) {
    static int correctPairNumIdx = 1;
    assert(pairIndex == correctPairNumIdx++);
}


int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0, pairIndex=0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            pairIndex = (i * 5) + (j+1);
            printf("%d | %s | %s\n", pairIndex, majorColor[i], minorColor[i]);
            evaluationColorMap(pairIndex);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
