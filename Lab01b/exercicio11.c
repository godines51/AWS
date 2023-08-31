#include <stdio.h>
#define MAX 100 

void soma_linhas (int matriz [][MAX], int L1, int L2, int colunas) {

  int i; 
  for (i = 0; i < colunas; i++) {
    matriz [L2] [i] = matriz [L1] [i] + matriz [L2] [i];
  }
}

void multiplica_linhas (int matriz [][MAX], int L1, int L2, int colunas) {

  int i; 
  for (i = 0; i < colunas; i++) {
    matriz [L2] [i] = matriz [L1] [i] * matriz [L2] [i];
  }
}

int main () {
  int matriz [MAX][MAX]; 
  int colunas; 
  int L1, L2; 
  int i, j; 
  printf ("soma: ");
  printf ("Insira o número de colunas da matriz: ");
  scanf ("%d", &colunas); 

  printf ("Insira o número de linha L1 da matriz:\n");
  for (j = 0; j < colunas; j++) {
    printf ("digito elemento da %d colunas: ", j+1); 
    scanf ("%d", &matriz [0] [j]); 
  }

  printf ("Insira o número de linha L2 da matriz:\n");
  for (j = 0; j < colunas; j++) {
    printf ("digito elemento da %d colunas: ", j+1); 
    scanf ("%d", &matriz [1] [j]); 
  }

  L1 = 0; 
  L2 = 1; 

  soma_linhas (matriz, L1, L2, colunas); 
  

  printf ("resultado:\n");
  
    for (j = 0; j < colunas; j++) {
      printf ("%d ", matriz [L2] [j]); 
    }
    printf ("\n");
  
  printf ("multiplica: ");
  printf ("Insira o número de colunas da matriz: ");
  scanf ("%d", &colunas); 

  printf ("Insira o número de linha L1 da matriz:\n");
  for (j = 0; j < colunas; j++) {
    printf ("digito elemento da %d colunas: ", j+1); 
    scanf ("%d", &matriz [0] [j]); 
  }

  printf ("Insira o número de linha L2 da matriz:\n");
  for (j = 0; j < colunas; j++) {
    printf ("digito elemento da %d colunas: ", j+1); 
    scanf ("%d", &matriz [1] [j]); 
  }

  L1 = 0; 
  L2 = 1; 
  
  multiplica_linhas (matriz, L1, L2, colunas);
  
  printf ("resultado:\n");
  
    for (j = 0; j < colunas; j++) {
      printf ("%d ", matriz [L2] [j]); 
    }
    printf ("\n");
  return 0;
}
