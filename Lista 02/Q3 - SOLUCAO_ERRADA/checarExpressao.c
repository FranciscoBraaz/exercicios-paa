#include <stdio.h>
#define MAX 100

int verificaPar(char expressao[]) {
    int qtdPA = 0,qtdPF = 0, qtdCA = 0, qtdCF = 0;
    for(int i = 0; expressao[i] != '\0'; i++) {
        if(expressao[i] == '(' ) {
            qtdPA++;
        } else if (expressao[i] == ')') {
            qtdPF++;
        } else if (expressao[i] == '[') {
            qtdCA++;
        } else if (expressao[i] == ']') {
            qtdCF++;
        }
        if(qtdCF > qtdPF && qtdCF > qtdCA) return 0;
        if(qtdPF > qtdCF && qtdPF > qtdPA) return  0;
    }
    if(qtdCF != qtdCA || qtdPF != qtdPA) return 0;
    return 1;
}

int main() {
    char expressao[MAX] = {"([)]"};
    int resposta = verificaPar(expressao);

    printf("%s", resposta == 1 ? "Expressao correta" : "Expressao incorreta");
    return 0;
}
