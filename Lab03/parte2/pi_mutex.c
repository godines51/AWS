#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Variáveis globais
long thread_count = 5;
long long n = 100000000; // 10^8
double sum;
pthread_mutex_t mutex;

// Protótipo da função das threads
void* Thread_sum(void* rank);

int main(int argc, char* argv[]) {
   long thread;
   pthread_t* thread_handles;

   // Aloca espaço para identificadores de threads
   thread_handles = (pthread_t*) malloc (thread_count * sizeof(pthread_t)); 
   pthread_mutex_init(&mutex, NULL);
   sum = 0.0;

   // Cria threads
   for (thread = 0; thread < thread_count; thread++)  
      pthread_create(&thread_handles[thread], NULL,
          Thread_sum, (void*)thread);  

   // Aguarda threads concluírem
   for (thread = 0; thread < thread_count; thread++) 
      pthread_join(thread_handles[thread], NULL); 

   // Calcula a estimativa final de π
   sum = 4.0 * sum;
   printf("mutexes\n");
   printf("com n = %lld termos,\n", n);
   printf("com %ld threads,\n", thread_count);
   printf("pi estimado = %.30f\n", sum);

   // Libera recursos e termina
   pthread_mutex_destroy(&mutex);
   free(thread_handles);
   return 0;
}  /* main */

// Função executada por cada thread
void* Thread_sum(void* rank) {
   long my_rank = (long) rank;
   double factor;
   long long i;
   long long my_n = n / thread_count;
   long long my_first_i = my_n * my_rank;
   long long my_last_i = my_first_i + my_n;
   double my_sum = 0.0;

   // Calcula o fator com base no índice inicial
   if (my_first_i % 2 == 0)
      factor = 1.0;
   else
      factor = -1.0;

   // Calcula a soma parcial da série
   for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
      my_sum += factor / (2.0 * i + 1);
   }

   // Bloqueia o mutex antes de atualizar a variável global sum
   pthread_mutex_lock(&mutex);
   sum += my_sum;
   pthread_mutex_unlock(&mutex);

   return NULL;
}
