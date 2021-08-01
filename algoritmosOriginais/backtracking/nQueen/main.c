#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool posicaoValida(int rainha, int coluna, int X[]) {
    for(int k = 1; k <= rainha-1; k++) {
        if(X[k] == coluna || (abs(X[k] - coluna) == abs(k-rainha))) {
            return false;
        }
    }

    return true;
}

void nq(int i, int n, int X[]){
    for(int j = 1; j <= n; j++) {
        if(X[0] == 1) return;
       if( posicaoValida(i, j, X)){
           X[i] = j;
           if(i == n) {
               X[0] = 1;
               return;
           } else {
               nq(i+1, n, X);
           }
       }
    }
}

int main() {
    int n = 4; //tamanho do tabuleiro: 4X4
    int X[n+1];

    for(int i = 0; i <= n; i++) {
        X[i] = 0;
    }

    nq(1, n, X);
    if(X[0] == 1) {
        printf("Solucao: ");
        for(int i = 1; i<=n; i++) {
            printf("%d ", X[i]);
        }
    } else {
        printf("Nao existe solucao");
    }

    return 0;
}
