#include <stdio.h>
#include <math.h>

int encontre(int vetor[], int limEsq, int limDir, int z) {
    if(limEsq == limDir) {
        if(vetor[limEsq] == z) {
            return limEsq;
        } else {
            return -1;
        }
    } else {
        int n = limDir - limEsq;
        int p1 = (int) (limEsq + floor(n/3.0));
        int p2 = (int) (limEsq +  floor((2*n/3.0)));

        if(z <= vetor[p1]) {
            return encontre(vetor, limEsq, p1, z);
        } else if (z > vetor[p2]) {
            return encontre(vetor, p2+1, limDir, z);
        } else {
            return encontre(vetor, p1+1, p2, z);
        }

    }
}

int main() {
    int vetorOriginal[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int limEsq = 0;
    int limDir = sizeof(vetorOriginal)/sizeof(vetorOriginal[0]) - 1;

    int elemento = encontre(vetorOriginal, limEsq, limDir, 6);
    printf("Elemento na posicao: %d", elemento);

    return 0;
}
