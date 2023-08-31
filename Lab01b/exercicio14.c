#include <stdio.h>
#include <string.h>

void inserir_caractere(char *str, int pos, char c) {
    int len = strlen(str);
    if (pos < 0 || pos > len) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = len; i > pos; i--) {
        str[i] = str[i - 1];
    }
    str[pos] = c;
}

int main() {
    char str[100];
    int pos;
    char c;
    printf("Digite a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Digite a posição onde o caractere será inserido: ");
    scanf("%d", &pos);
    getchar();
    printf("Digite o caractere a ser inserido: ");
    scanf("%c", &c);
    printf("String original: %s\n", str);
    inserir_caractere(str, pos, c);
    printf("String modificada: %s\n", str);
    return 0;
}
