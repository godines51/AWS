#include <stdio.h>

int main(void) {

  float n1, n2, n3, mediaAproveitamento, mediaExercicios;
  float *p1 = &n1;
  float *p2 = &n2;
  float *p3 = &n3;
  float *pA = &mediaAproveitamento;
  float *pE = &mediaExercicios;
  printf("Digite as notas:");
  scanf("%f%f%f%f", p1, p2, p3, pE);
  float media = (*p1 + (*p2 * 2) + (*p3 * 3) + *pE) / 7;
  pA = &media;
  if (*pA >= 9) {
    printf("A media de Aproveitamento é : A\n");
  } else if (*pA >= 7.5 && *pA < 9) {
    printf("A media de Aproveitamento é : B\n");
  } else if (*pA >= 6 && *pA < 7.5) {
    printf("A media de Aproveitamento é : C\n");
  } else if (*pA >= 4 && *pA < 6) {
    printf("A media de Aproveitamento é : D\n");
  } else {
    printf("A media de Aproveitamento é : E\n");
  }

  return 0;
}
