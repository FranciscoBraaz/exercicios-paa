#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "time.h"

bool posicaoValida(int rainha, int coluna, int X[]) {
    for(int k = 1; k <= rainha-1; k++) {
        if(X[k] == coluna || (abs(X[k] - coluna) == abs(k-rainha))) {
            return false;
        }
    }

    return true;
}

void nq(int i, int n, int X[],int k){
    for(int l = k; l <k; k++) {
        for(int j = 1; j <= n; j++) {
            if(X[0] == 1) return;
            int pos = 1 + (rand() % (n - 1));
            if( posicaoValida(i, pos, X)){
                X[i] = pos;
                if(i == n) {
                    X[0] = 1;
                    return;
                } else {
                    nq(i+1, n, X, k);
                }
            }
        }
    }

}

int main() {
    int n = 4; //tamanho do tabuleiro: 4X4
    int X[n+1];
    srand(time(0));
    int k = 1000;

    for(int i = 0; i <= n; i++) {
        X[i] = 0;
    }

    nq(1, n, X, k);
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
