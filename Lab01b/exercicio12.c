#include <stdio.h>

int posicao_caractere(char *str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}

int main() {
    char str[100];
    char c;
    printf("Digite a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Digite o caractere a ser procurado: ");
    scanf("%c", &c);
    int pos = posicao_caractere(str, c);
    printf("O caractere '%c' está na posição %d da string '%s'.\n", c, pos, str);
    return 0;
}
