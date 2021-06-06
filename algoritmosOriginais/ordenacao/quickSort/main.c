#include <stdio.h>

int partition(int vetor[], int esq, int dir) {
    int pivo, l, r ,temp;

    pivo = vetor[esq];
    l = esq;
    r = dir;

    while(l < r) {
        while(vetor[l] <= pivo && l < r) {
            l++;
        }
        while(vetor[r] > pivo && r > l) {
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
    printf("\n-----------Divisor----------\n");
    quickSort(vetor, 0, tam-1);
    for(int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
