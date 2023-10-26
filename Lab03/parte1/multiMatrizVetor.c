#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int m, n, thread_count;
int *A;
int *x;
int *y;

void *Pth_mat_vect(void *rank);

int main(int argc, char *argv[]) {
  long thread;
  pthread_t *thread_handles;

  if (argc != 2) {
    fprintf(stderr, "Uso: %s <número de threads>\n", argv[0]);
    exit(1);
  }
  thread_count = strtol(argv[1], NULL, 10);

  printf("Digite o número de linhas da matriz A: ");
  scanf("%d", &m);
  printf("Digite o número de colunas da matriz A: ");
  scanf("%d", &n);

  A = malloc(m * n * sizeof(int));
  x = malloc(n * sizeof(int));
  y = malloc(m * sizeof(int));

  printf("Digite os elementos da matriz A:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i * n + j]);
    }
  }

  printf("Digite os elementos do vetor x:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }

  thread_handles = (pthread_t *)malloc(thread_count * sizeof(pthread_t));

  for (thread = 0; thread < thread_count; thread++) {
    pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void *)thread);
  }

  for (thread = 0; thread < thread_count; thread++) {
    pthread_join(thread_handles[thread], NULL);
  }

  printf("Resultado do produto matriz-vetor:\n");
  for (int i = 0; i < m; i++) {
    printf("y[%d] = %d\n", i, y[i]);
  }

  free(A);
  free(x);
  free(y);
  free(thread_handles);

  return 0;
}

void *Pth_mat_vect(void *rank) {
  long my_rank = (long)rank;
  int i, j;
  int local_m = m / thread_count;
  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank + 1) * local_m - 1;

  for (i = my_first_row; i <= my_last_row; i++) {
    y[i] = 0;
    for (j = 0; j < n; j++) {
      y[i] += A[i * n + j] * x[j];
    }
  }

  return NULL;
}

