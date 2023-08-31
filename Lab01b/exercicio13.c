#include <stdio.h>
#include <string.h>

void remover_caractere(char *str, int pos) {
    int len = strlen(str);
    if (pos < 0 || pos >= len) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = pos; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = '\0';
}

int main() {
    char str[100];
    int pos;
    printf("Digite a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Digite a posição do caractere a ser removido: ");
    scanf("%d", &pos);
    printf("String original: %s\n", str);
    remover_caractere(str, pos);
    printf("String modificada: %s\n", str);
    return 0;
}
