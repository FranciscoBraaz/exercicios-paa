#include <stdio.h>

int convertToInt(char x) {
    int y = (int) x;
    return y;
}

void rabinKarp(char T[], int n, char P[], int m) {
    int q = 3354393, d = 32, dM = 1;
    for(int i = 0; i <= m-1; i++) {
        dM = (d*dM) % q;
    }
    int h1 = 0; //hash do padrão
    for(int i = 0; i <= m; i++) {
        h1 = (h1*d + convertToInt(P[i])) % q;
    }

    int h2 = 0; //hash do texto
    for(int i = 0; i <= n; i++) {
        h2 = (h2*d + convertToInt(T[i])) % q;
    }

    if(h1 == h2) {
        printf("igual");
    }

}

int main() {
    char texto[] = "ESTA";
    char padrao[] = "ESTA";
    int lenT = sizeof texto/sizeof texto[0] - 2; // o "-2" é porque a contagem do vetor começa em 0 e porque a linguagem coloca um /0 ao final da string
    int lenP = sizeof padrao/sizeof padrao[0] - 2;

    rabinKarp(texto, lenT, padrao, lenP);
    return 0;
}
