#include <stdio.h>
#include <stdlib.h>

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

void gerarVetor(int** vetor, int a, int b, int *capacidade, int *countTam) {
    int limite = (b-a);
    for(int i = 0; i <= limite; i++) {
        if(*capacidade >= *countTam) {
            *vetor =  realloc(*vetor, ((*capacidade)*2) * sizeof (int));
        }
        ((*vetor)[*countTam]) = a;
        (*capacidade)++;
        (*countTam)++;
        a = a + 1;
    }
}

int encontrePrimeiro(int vetor[], int limEsq, int limDir, int z) {

    if(limEsq >= limDir) {
        if(vetor[limEsq] == z) {
            return limEsq;
        } else {
            return -1;
        }
    } else {
        int meio = (int) (limEsq + (limDir - limEsq)/2.0);
        if(vetor[meio] == z) {
            if(vetor[meio-1] == z) {
                return encontrePrimeiro(vetor, limEsq, meio-1, z);
            } else {
                return meio;
            }
        }
        if(z < vetor[meio]) {
            return encontrePrimeiro(vetor, limEsq, meio-1, z);
        } else {
            return encontrePrimeiro(vetor, meio+1, limDir, z);
        }
    }
}

int encontreUltimo(int vetor[], int limEsq, int limDir, int z) {
    if(limEsq >= limDir) {
        if(vetor[limEsq] == z) {
            return limEsq;
        } else {
            return -1;
        }
    } else {
        int meio = (int) (limEsq + (limDir - limEsq)/2.0);
        if(vetor[meio] == z) {
            if(vetor[meio+1] == z) {
                return encontreUltimo(vetor, meio+1, limDir, z);
            } else {
                return meio;
            }
        }
        if(z < vetor[meio]) {
            return encontreUltimo(vetor, limEsq, meio-1, z);
        } else {
            return encontreUltimo(vetor, meio+1, limDir, z);
        }
    }
}


int main() {
    int numIntervalos = 3;
    int vetorEntradas[][2] = {1, 3, 7, 9, 1, 8};
//    int vetorTeste[] = {1,1,2,2,3,3,4,5,6,7,7,8,8,9};
    int capacidade = 5;
    int *ptrCapacidade = &capacidade;
    int *vetorCompleto;
    vetorCompleto = (int*) malloc(capacidade * sizeof (int));
    int countTam = 0;
    int *ptrCountTam = &countTam;

    for(int i = 0; i<=numIntervalos-1; i++) {
        gerarVetor(&vetorCompleto, vetorEntradas[i][0], vetorEntradas[i][1], ptrCapacidade, ptrCountTam);
    }

    heapSort(vetorCompleto, countTam);
    for(int i = 0; i<countTam; i++) {
        printf("%d ", vetorCompleto[i]);
    }

    int len = countTam-1;
    int firstIndex = encontrePrimeiro(vetorCompleto, 0, len, 1);
    printf("\n--------- First Position --------\n");
    printf("%d ", firstIndex);
    int lastIndex = encontreUltimo(vetorCompleto, 0, len, 1);
    printf("\n--------- Last Position --------\n");
    printf("%d ", lastIndex);

    return 0;
}
