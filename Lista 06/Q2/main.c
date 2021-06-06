#include <stdio.h>

void achaPadrao(char expressao[], char padrao[], int n, int m) {
    int i = 0, j = 0, index = -1;
    while(index == -1 && i <= n) {
        if (expressao[i] == padrao[j]) {
            i = i + 1;
            j = j + 1;
        } else {
            if(padrao[j] == '#') {
                j = j + 1;
            } else if(padrao [j-1] == '#') {
               i = i + 1;
            } else {
                i = i + 1;
                j = 0;
            }

        }
        if(j == m+1) {
            index = i-(m);
            printf("Encontrado");
        }
    }

    if(index == -1) {
        printf("Nao encontrado");
    }

}

int main() {
    char expressao[] = "A casa ita";
    int tamExpressao = (sizeof expressao/sizeof expressao[0]) - 2;
    char padrao[] = "#cta#";
    int tamPadrao = (sizeof padrao/sizeof padrao[0]) - 2;

    achaPadrao(expressao, padrao, tamExpressao, tamPadrao);
    return 0;
}
