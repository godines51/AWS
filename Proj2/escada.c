#include <stdio.h>
#include <stdlib.h>

#define MAX_RIDERS 10000

typedef struct {
    int t; // Tempo de chegada do usuário
    int d; // Direção do usuário: 0 para esquerda, 1 para direita
} rider;

// Função para ler os dados do arquivo
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

// Função que simula o funcionamento da escada rolante
int escalator(rider* riders, int n) {
    int moment = 0;
    int direction = -1;
    int waiting = 0;

    for (int i = 0; i < n; i++) {
        if (riders[i].t < moment) {
            // Usuário chegou antes do momento atual
            if (riders[i].d == direction) {
                moment = riders[i].t + 10;
            } else {
                waiting = 1; // Alguém está esperando na fila
            }
        } else {
            // Usuário chegou no momento ou depois do momento atual
            if (waiting) {
                // Se alguém estava esperando, incrementa 10 no tempo e reseta direção
                moment += 10;
                direction = -1;
                i--; // Reprocessa a mesma pessoa
            } else {
                // Se não havia ninguém esperando, atualiza o tempo e direção
                moment = riders[i].t + 10;
                direction = riders[i].d;
            }
            waiting = 0; // Reseta a flag de espera
        }
    }

    if (waiting) {
        moment += 10; // Se há alguém esperando no final, incrementa 10 no tempo
    }

    return moment;
}

int main() {
    // Loop para processar os arquivos de 1 a 58
    for (int fileNumber = 1; fileNumber <= 58; fileNumber++) {
        char fileName[20];
        sprintf(fileName, "input/E_%d", fileNumber);

        rider riders[MAX_RIDERS];
        int n;

        // Chama a função para ler os dados do arquivo
        readData(fileName, riders, &n);

        // Chama a função para simular o funcionamento da escada rolante
        int lastMoment = escalator(riders, n);

        // Imprime o resultado para o arquivo específico
        printf("Resultado para o arquivo %s: O último momento em que a escada para é %d\n", fileName, lastMoment);
    }

    return 0;
}
