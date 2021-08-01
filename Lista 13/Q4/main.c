#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int vetor[], int esq, int dir) {
    int pivo, l, r ,temp;

    int index =  esq + (rand() % (dir  - esq));

    //troca o valor escolhido aleatório com o valor da primeira posição, que para onde o pivo aponta
    int aux = vetor[esq];
    vetor[esq] = vetor[index];
    vetor[index] = aux;

    pivo = vetor[esq];
    l = esq;
    r = dir;

    while(l < r) {
        while(vetor[l] <= pivo && l < r) {
            l++;
        }
        while(vetor[r] > pivo) {
            r--;
        }

        if(l < r) {
            temp = vetor[l];
            vetor[l] = vetor[r];
            vetor[r] = temp;
        }

    }
    vetor[esq] = vetor[r];
    vetor[r] = pivo;
    return r;
}

void quickSort(int vetor[], int esq, int dir) {
    if(esq < dir) {
        int pos = partition(vetor, esq, dir);
        quickSort(vetor, esq, pos-1);
        quickSort(vetor, pos+1, dir);
    }
}

int main() {
    int vetor[] = {25 ,57, 48, 37, 12, 92, 33};
    int tam = sizeof vetor/sizeof vetor[0];
    for(int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }

    srand(time(NULL));

    printf("\n-----------Divisor----------\n");
    quickSort(vetor, 0, tam-1);
    for(int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
