#include <stdio.h>

int main() {
  int impar;

  do {
    printf("Digite um número ímpar máximo: ");
    scanf("%d", &impar);
  } while (impar % 2 == 0);

  int meio = (impar + 1) / 2;
  int espaco = 0;

  for (int i = 1; i <= meio; i++) {
    for (int j = 0; j < espaco; j++) {
      printf("   ");
    }

    for (int j = i; j <= impar - espaco; j++) {
      printf("%2d ", j);
    }

    printf("\n");
    espaco++;
  }

  return 0;
}

