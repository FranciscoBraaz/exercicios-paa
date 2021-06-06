#include <stdio.h>

int achaPadrao(char expressao[], char padrao[], int n, int m) {
    int i = 0, j = 0, index = -1;
    while(index == -1 && i <= n) {
        if (expressao[i] == padrao[j]) {
            i = i + 1;
            j = j + 1;
        } else {
            i = i - j + 1;
            j = 0;
        }
        if(j == m+1) {
            index = i-(m+1);
        }
    }
    return index;
}

int main() {
    char expressao[] = "A casa dos recem-casados e bonita";
    int tamExpressao = (sizeof expressao/sizeof expressao[0]) - 2;
    char padrao[] = "casados";
    int tamPadrao = (sizeof padrao/sizeof padrao[0]) - 2;

    int index = achaPadrao(expressao, padrao, tamExpressao, tamPadrao);
    printf("%d ", index);
    return 0;
}
