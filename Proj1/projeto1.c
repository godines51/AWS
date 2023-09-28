#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct c {
  int saldo;
};
typedef struct c conta;
conta from, to;
int valor;

pthread_mutex_t mutex_from; // Mutex para a conta from
pthread_mutex_t mutex_to;   // Mutex para a conta to

void *transferencia(void *arg) {
  pthread_mutex_lock(&mutex_from); // Bloqueia o mutex da conta from
  pthread_mutex_lock(&mutex_to);   // Bloqueia o mutex da conta to

  if (from.saldo >= valor) {
    from.saldo -= valor;
    to.saldo += valor;
  }

  printf("Transferência concluída com sucesso!\n");
  printf("----------------\n");
  printf("Saldo de c1: %d\n", from.saldo);
  printf("Saldo de c2: %d\n", to.saldo);

  pthread_mutex_unlock(&mutex_to);   // Desbloqueia o mutex da conta to
  pthread_mutex_unlock(&mutex_from); // Desbloqueia o mutex da conta from

  // Troca as contas from e to
   //conta temp = from;
   //from = to;
   //to = temp;

  return NULL;
}

int main() {
  pthread_t threads[10];
  int i;

  pthread_mutex_init(&mutex_from, NULL);
  pthread_mutex_init(&mutex_to, NULL);

  from.saldo = 100;
  to.saldo = 100;

  printf("Transferindo 10 entre c1 e c2\n");
  valor = 10;
  for (i = 0; i < 10; i++) {
    if (pthread_create(&threads[i], NULL, transferencia, NULL) != 0) {
      perror("pthread_create");
      exit(2);
    }
  }

  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex_to);
  pthread_mutex_destroy(&mutex_from);

  printf("Transferências concluídas e memória liberada.\n");
  return 0;
}
