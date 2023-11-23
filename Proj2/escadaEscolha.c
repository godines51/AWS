#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int t; // Tempo de chegada do usuário
    int d; // Direção do usuário: 0 para esquerda, 1 para direita
} rider;

// Função para obter os dados dos usuários
void getInput(rider* riders, int* n) {
    while (1) {
        printf("Digite o número de usuários (1-10000): ");
        scanf("%d", n);

        if (*n <= 0 || *n > 10000) {
            printf("Por favor, digite um número de usuários dentro do intervalo válido (1-10000).\n");
        } else {
            break; // Sai do loop se o número de usuários estiver dentro do intervalo válido
        }
    }

    printf("Digite os tempos de chegada e direções (0 para esquerda, 1 para direita) para cada usuário:\n");
  
    for (int i = 0; i < *n; i++) {
        printf("Usuario %d (tempo primeiro, depois direção): ", i + 1);

        int tempTempo, tempDirecao;
        while (1) {
            scanf("%d %d", &tempTempo, &tempDirecao);

            if (tempTempo < 0 || (tempDirecao != 0 && tempDirecao != 1)) {
                printf("Entrada inválida. Por favor, insira um número inteiro não negativo para o tempo e 0 ou 1 para a direção.\n");
                printf("Usuario %d (tempo primeiro, depois direção): ", i + 1);
            } else {
                riders[i].t = tempTempo;
                riders[i].d = tempDirecao;
                break; // Sai do loop se a entrada estiver correta
            }
        }
    }
}

// Função para simular o funcionamento da escada rolante
int escalator(rider* riders, int n) {
    // Variáveis para rastrear o estado da simulação
    rider passageirosAtual = riders[0];//Passageiros atualmente usando a escada rolante
    int atualIndex = 0;//Índice de passageiros atualmente em processamento
    int tempoEstimado;//Tempo de chegada estimado
    rider passageirosEsperando[10000];//fila de passageiros esperando
    int restantesPassageiros = n;//número de passageiros restantes
    int horaUltimo = 0;//hora do último evento
    int direcao = -1;//direcao
    int moment = 0; // o horário atual da simulação
    bool esperando = false;//se ha algum passageiro esperando para usar a escada rolante


  //Se houver passageiros esperando e atenderem a certas condições (ou seja, o horário do passageiro for posterior ao horário previsto de chegada ou exceder o número total de passageiros), processe os passageiros em espera: defina o passageiro atual como o primeiro passageiro na fila de espera , aumente o tempo (simule o tempo de funcionamento da escada rolante automática), atualize a direção e o tempo estimado de chegada, reduza o número de passageiros restantes e marque-o como sem passageiros esperando.
    while (restantesPassageiros > 0) {
        if (esperando && (riders[atualIndex].t > tempoEstimado || atualIndex >= n)) {
            // Lógica para lidar com os passageiros pendentes
            passageirosAtual = passageirosEsperando[0];
            moment += 10;
            direcao = passageirosAtual.d;
            tempoEstimado = moment + 10;
            restantesPassageiros--;
            esperando = false;
        } else {
          
            passageirosAtual = riders[atualIndex];

            if (direcao == -1) {
                // Lógica para lidar com o início da movimentação da escada rolante
                moment = passageirosAtual.t < moment ? moment : passageirosAtual.t;
                direcao = passageirosAtual.d;
                tempoEstimado = passageirosAtual.t + 10;

                atualIndex++;
                restantesPassageiros--;
            } else if (direcao == passageirosAtual.d) {
                // Lógica para lidar com o movimento na mesma direção
                moment = passageirosAtual.t;
                tempoEstimado = passageirosAtual.t + 10;

                atualIndex++;
                restantesPassageiros--;
            } else {
                // Lógica para lidar com a mudança de direção
                if (riders[atualIndex + 1].t - riders[atualIndex].t > riders[atualIndex - 1].t) {
                    moment = tempoEstimado;
                    direcao = -1;
                } else if (riders[atualIndex + 1].t <= tempoEstimado) {
                    passageirosEsperando[0] = riders[atualIndex]; 
                    esperando = true;
                    atualIndex++;
                }
            }
        }
    }

    moment += 10;
    horaUltimo = moment;

    return horaUltimo;
}

int main() {
    rider riders[10000]; // Array para armazenar os dados dos usuários
    int n; // Número de usuários

    getInput(riders, &n); // Obter os dados dos usuários
    int lastMoment = escalator(riders, n); // Simular o funcionamento da escada rolante

    printf("A última pessoa sairá da escada rolante no tempo: %d\n", lastMoment);
    return 0;
}
