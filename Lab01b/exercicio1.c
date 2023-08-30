#include <stdio.h>

int main(void) {
  
  int tamanho = 4;
  
  int matriz[tamanho][tamanho];

  printf("Digite os elementos da matriz:");
  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      scanf("%d", &matriz[i][j]);
    }
  }
  int menor = matriz[0][0];
  int menorLinha = 0;

  for(int i = 0; i < tamanho; i++){
    for(int j = 0; j < tamanho; j++){
      if (matriz[i][j] < menor){
        menor = matriz[i][j];
        menorLinha = i;
      }
    }
  }
  printf("A linha com o menor número é: %d\n", menorLinha);
  
  return 0;
}
