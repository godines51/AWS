#include <stdio.h>
#include <stdlib.h>

#define MAX_RIDERS 10000

typedef struct {
    int t;
    int d;
} rider;

int solve(rider* riders, int n) {
    int moment = riders[0].t + 10;
    int waiting = 0;
    int direction = riders[0].d;

    for (int i = 1; i < n; i++) {
        if (riders[i].t <= moment) {
            if (riders[i].d == direction) {
                moment = riders[i].t + 10;
            } else {
                waiting = 1;
            }
        } else {
            if (waiting) {
                moment += 10;
                direction = (direction == 1) ? 0 : 1;
                i--;
            } else {
                moment = riders[i].t + 10;
                direction = riders[i].d;
            }
            waiting = 0;
        }
    }

    if (waiting) {
        moment += 10;
    }

    return moment;
}

void readData(char* filePath, rider* riders, int* n) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filePath);
        exit(1);
    }

    fscanf(file, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d %d", &riders[i].t, &riders[i].d);
    }

    fclose(file);
}

void readExpectedOutput(char* filePath, int* expected) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filePath);
        exit(1);
    }

    fscanf(file, "%d", expected);
    fclose(file);
}

int main() {
    for (int fileNumber = 1; fileNumber <= 58; fileNumber++) {
        char inputFileName[20];
        char outputFileName[20];

        sprintf(inputFileName, "input/E_%d", fileNumber);
        sprintf(outputFileName, "output/E_%d", fileNumber);

        rider riders[MAX_RIDERS];
        int n;
        int expectedOutput;

        readData(inputFileName, riders, &n);
        readExpectedOutput(outputFileName, &expectedOutput);

        int lastMoment = solve(riders, n);

        printf("Para %s: Último momento em que a escada para: %d. Resposta esperada: %d\n", inputFileName, lastMoment, expectedOutput);
    }

    return 0;
}
