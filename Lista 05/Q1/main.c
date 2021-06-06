#include <stdio.h>

void rearranjeHeap(int vetor[], int n) {
    int pai = 0;
    int filho = 1;

    while(filho <= n-1) {
        if(vetor[filho] < vetor[filho + 1]){
            filho += 1;
        }

        if(vetor[filho] > vetor[pai]) {
            int aux = vetor[pai];
            vetor[pai] = vetor[filho];
            vetor[filho] = aux;
            pai = filho;
            filho = (filho*2) + 1;
        } else {
            filho = n;
        }
    }

}

void maxHeap(int vetor[], int i, int n) {
    int esq = (2*i) + 1;
    int dir = (2*i) + 2;
    int maior;
    if(esq <= n && vetor[esq] > vetor[i]) {
        maior = esq;
    } else {
        maior = i;
    }

    if(dir <= n && vetor[dir] > vetor[maior]) {
        maior = dir;
    }

    if(maior != i) {
        int aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        maxHeap(vetor, maior ,n);
    }
}

void construirHeap (int vetor[], int n) {
    for(int i = n/2; i >= 0; i--) {
        maxHeap(vetor, i, n);
    }
}

void heapSort(int vetor[], int n) {
    construirHeap(vetor, n);
    for(int i = n; i > 1; i--) {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        rearranjeHeap(vetor, i-1);
    }
}

int encontre(int vetor[], int limEsq, int limDir, int z) {
    if(limEsq >= limDir) {
        if(vetor[limEsq] == z) {
            return limEsq;
        } else {
            return -1;
        }
    } else {

        int meio = (int) (limEsq + (limDir - limEsq)/2.0);

        if(vetor[meio] == z) {
            return meio;
        }
        if(z < vetor[meio]) {
            return encontre(vetor, limEsq, meio-1, z);
        } else {
            return encontre(vetor, meio+1, limDir, z);
        }
    }
}

void interseccao(int vetorA[], int vetorB[], int tamA, int tamB) {
    for(int i = 0; i < tamB; i++) {
        int resp = encontre(vetorA, 0, tamA, vetorB[i]);
        if(resp != -1) {
            printf("%d ", vetorB[i]);
        }
    }
}

int main() {
    int vetorA[] = {10, 4, 15, 6, 7};
    int lenA = sizeof vetorA/sizeof vetorA[0] - 1;
    int vetorB[] = {7, 4, 2, 1, 6, 13};
    int lenB = sizeof vetorB/sizeof vetorB[0] - 1;
    heapSort(vetorA, lenA);
    interseccao(vetorA, vetorB, lenA, lenB);

//    for(int i = 0; i<=lenA; i++) {
//        printf("%d ", vetorA[i]);
//    }
//    printf("\n--------- Divider ---------\n");
//    for(int i = 0; i<=lenB; i++) {
//        printf("%d ", vetorB[i]);
//    }
    return 0;
}
