#include <stdio.h>
#include <string.h>
int main() {
  char str1[50];
  char str2[50];
  int value;

  printf("Digite o primeiro nome:");
  scanf("%s", str1);
  printf("\nDigite o segundo nome:");
  scanf("%s", str2);

  value = strcmp(str1, str2);
  if (value == 0) {
    printf("Os nomes são iguais.");
  } else if (value < 0) {
    printf("%s\n%s", str1, str2);
  } else {
    printf("%s\n%s", str2, str1);
  }

  return 0;
}

