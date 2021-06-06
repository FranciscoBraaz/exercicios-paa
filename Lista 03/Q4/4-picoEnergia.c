#include <stdio.h>
#include <math.h>

int encontre(int vetor[], int limEsq, int limDir) {
    if(limEsq == limDir) {
        if(vetor[limEsq]) {
            return limEsq;
        } else {
            return -1;
        }
    } else {
        int meio = (int) ceil((limEsq + limDir)/2.0);

        if(vetor[meio-1] > vetor[meio]) {
            return encontre(vetor, limEsq, meio-1);
        } else {
            return encontre(vetor, meio, limDir);
        }
    }
}

int main() {
    int dados[] = {20, 17, 16, 15, 14, 13, 12, 10};
    int limEsq = 0;
    int limDir = (sizeof dados/sizeof dados[0]) -1;

    int pico = encontre(dados, limEsq, limDir);

    printf("O pico encontra-se na posicao: %d", pico);

    return 0;
}
