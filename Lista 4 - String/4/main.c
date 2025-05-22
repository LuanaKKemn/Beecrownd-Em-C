#include <stdio.h>
#include <string.h>

// Função para remover o sufixo repetido
void corrigirPalavra(char *palavra) {
    int len = strlen(palavra);
    int repeticao = 0;

    // Encontrar a posição de repetição do sufixo
    for (int i = len - 1; i >= 1; i--) {
        if (palavra[i] == palavra[i - 1]) {
            repeticao = i;
            break;
        }
    }

    // Remover o sufixo repetido
    if (repeticao > 0) {
        palavra[repeticao] = '\0';
    }
}

int main() {
    char palavra[31]; // Cada palavra tem no máximo 30 caracteres

    // Ler as palavras até o fim do arquivo (EOF)
    while (scanf("%30s", palavra) != EOF) {
        corrigirPalavra(palavra);
        printf("%s\n", palavra);
    }

    return 0;
}
