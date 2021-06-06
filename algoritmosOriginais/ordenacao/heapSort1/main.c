#include <stdio.h>

void rearranjeMaxHeap(int vetor[], int n) {
    int pai = 0;
    int filho = 1;
    while(filho <= n - 1) {
        if(vetor[filho] < vetor[filho + 1]) {
            filho += 1;
        }

        if(vetor[filho] > vetor[pai]) {
            int aux = vetor[pai];
            vetor[pai] = vetor[filho];
            vetor[filho] = aux;
            pai = filho;
            filho *= 2;
        } else {
            filho = n;
        }
    }
}

void maxHeap(int vetor[], int i, int *n) {
    int esq = (2*i) + 1, dir = (2*i) + 2;
    int maior;
    if(esq <= *n && vetor[esq] > vetor[i]) {
        maior = esq;
    } else {
        maior = i;
    }
    if(dir <= *n && vetor[dir] > vetor[maior]) {
        maior = dir;
    }

    if(maior != i) {
        int aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        maxHeap(vetor, maior, n);
    }
}

void construirMaxHeap(int vetor[], int *n) {
    for(int i = *n/2; i>=0; i--) {
        maxHeap(vetor, i, n);
    }
}

void heapSort(int vetor[], int *n) {
    construirMaxHeap(vetor, n);

    for(int i = *n; i > 1; i--) {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        rearranjeMaxHeap(vetor, i-1);
    }
}

int main() {
    int vetor[] = {8, 21, 10, 4 ,1 , 7};
    int tam = 5;
    int *ptrTam = &tam;

    for(int i = 0; i<=tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n------------ Ordenado -----------\n");
    construirMaxHeap(vetor, ptrTam);
    for(int i = 0; i<=tam; i++) {
        printf("%d ", vetor[i]);
    }

    heapSort(vetor, ptrTam);
    printf("\n------------ Ordenado -----------\n");

    for(int i = 0; i<=tam; i++) {
        printf("%d ", vetor[i]);
    }



    return 0;
}
