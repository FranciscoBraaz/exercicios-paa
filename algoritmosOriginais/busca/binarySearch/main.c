#include <stdio.h>
#include "math.h"

int encontre(int vetor[], int limEsq, int limDir, int z) {
    if(limEsq == limDir) {
        if(vetor[limEsq] == z) {
            return limEsq;
        } else {
            return -1;
        }
    } else {
        int meio = (int) ceil((limEsq+limDir)/2.0);

        if(z < vetor[meio]) {
            return encontre(vetor, limEsq, meio - 1, z);
        } else {
            return encontre(vetor, meio, limDir, z);
        }
    }
}

int main() {
    int dados[] = {5, 14, 25, 38, 54, 60};
    int limEsq = 0;
    int limDir = (sizeof dados/sizeof dados[0]) -1;
    int resp = encontre(dados, limEsq, limDir, 38);
    printf("%d ", resp);
    return 0;
}
