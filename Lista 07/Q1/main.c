#include <stdio.h>

int converteParaInt(char x) {
    int y = (int) x;
    return y;
}

void rabinKarp(char T[], int n, int k, int m, char P[][m+1]) {
    int q = 3354393, d = 32, dM = 1;
    for(int i = 0; i <= m-1; i++) {
        dM = (d*dM) % q;
    }

    int h2 = 0; //hash do texto
    for(int i = 0; i <= m; i++) {
        h2 = (h2*d + converteParaInt(T[i])) % q;
    }
    int arrayH1[k]; //hash dos padrões
    int recorrencias[k];
    for(int j = 0; j<k; j++) {
        arrayH1[j] = 0;
        recorrencias[j] = -1;
        for (int i = 0; i <= m; i++) {
            arrayH1[j] = (arrayH1[j] * d + converteParaInt(P[j][i])) % q;
        }
    }
    int i = 0;
    while(i <= n-m) {
        for(int j=0; j < k; j++) {
            if(arrayH1[j] == h2){
                printf("Padrao %d ocorre em: %d\n", j, i);
                recorrencias[j] = 1;
            }
        }
        h2 = (h2+ d*q - converteParaInt(T[i])*dM) % q;
        h2 = (h2*d + converteParaInt(T[i+m+1])) % q;
        i = i + 1;
    }

    for(int j = 0; j<k;j++) {
        if(recorrencias[j] == -1){
            printf("Padrao inexistente\n");
        }
    }
}


int main() {
    char texto[] = "A AULA ESTA FICANDO INTERESSANTE";
    char padroes[][4] = {"ESTA", "FICA", "INTE", "A FI"};
    int tamT = sizeof texto/sizeof texto[0] - 2; // o "-2" é porque a contagem do vetor começa em 0 e porque a linguagem coloca um /0 ao final da string
    int tamP = 4;
    int qtdPadroes = sizeof padroes/sizeof padroes[0];

    //m = tamP-1 porque a contagem do vetor começa em 0
    rabinKarp(texto, tamT, qtdPadroes, tamP-1, padroes);
    return 0;
}
