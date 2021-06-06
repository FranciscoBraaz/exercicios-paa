#include <stdio.h>

void achaPadrao(char expressao[], char padrao[], int n, int m, int k) {
    int i = 0, j = 0, index = -1;
    m = k-1;
    while(i <= n) {
        if (expressao[i] == padrao[j]) {
            i = i + 1;
            j = j + 1;
        } else {
            i = i - j + 1;
            j = 0;
        }
        if(j == m+1) {
            index = i-(m+1);
            printf("%d ", index);
        }
    }

    if(index == -1) {
        printf("Padrao nao encontrado");
    }
}

int main() {
    char expressao[] = "Vejam as araras e ararinhas azuis na arvore durante a viagem";
    int tamExpressao = (sizeof expressao/sizeof expressao[0]) - 2;
    char padrao[] = "ara";
    int tamPrefixo = 2;
    int tamPadrao = (sizeof padrao/sizeof padrao[0]) - 2;

    achaPadrao(expressao, padrao, tamExpressao, tamPadrao, tamPrefixo);
    return 0;
}
