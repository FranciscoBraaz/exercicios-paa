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

void remover(int vetor[], int *n){
    int aux = vetor[0];
    vetor[0] = vetor[*n];
    vetor[*n] = aux;
    *n = *n - 1;
    int tam = *n;
    rearranjeMaxHeap(vetor, tam);
}

void inserirHeap(int vetor[], int *n, int elemento) {
    *n = *n + 1;
    int filho = *n;
    int pai = (*n/2)-1;
    vetor[*n] = elemento;
    while (pai >= 0) {
        if(vetor[pai] < vetor[filho]) {
            int aux = vetor[pai];
            vetor[pai] = vetor[filho];
            vetor[filho] = aux;
            filho = pai;
            pai = (pai/2) - 1;
        } else {
            pai = -1;
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

int main() {
    int vetor[] = {8, 21, 10, 4 ,1 , 7};
    int tam = 5;
    int *ptrTam = &tam;

    for(int i = 0; i<=tam; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n------------ Heap construido -----------\n");
    construirMaxHeap(vetor, ptrTam);
    for(int i = 0; i<=tam; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
