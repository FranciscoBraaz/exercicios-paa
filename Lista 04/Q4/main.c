#include <stdio.h>

int partition(int vetor[], int esq, int dir) {
    int pivo, l, r ,temp;

    pivo = vetor[esq];
    l = esq;
    r = dir;


    while(l < r) {
        if (pivo % 2 == 0) {
            while (vetor[l] <= pivo && l <= r) {
                l++;
            }
            while (vetor[r] > pivo && r >= l) {
                r--;
            }

            if (l < r) {
                temp = vetor[l];
                vetor[l] = vetor[r];
                vetor[r] = temp;
            }
        } else {
            while (vetor[l] >= pivo && l <= r) {
                l++;
            }
            while (vetor[r] < pivo && r >= l) {
                r--;
            }

            if (l < r) {
                temp = vetor[l];
                vetor[l] = vetor[r];
                vetor[r] = temp;
            }
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

void separar(int vetor[], int tam) {
    int i = 0, j = tam-1;
    while(i < j) {
        if(vetor[i] % 2 != 0 && vetor[j] % 2 == 0) {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        } else if(vetor[i] % 2 != 0) {
            j--;
        } else if (vetor[i] % 2 == 0) {
            i++;
        }
    }
}

void defineQuickSort(int vetor[], int tam) {
    int index = 0;
    int encontrou = 0;
    for(int i = 0; i<tam && encontrou == 0; i++) {
        if(vetor[i] % 2 == 0 && vetor[i+1] % 2 != 0) {
            index = i;
            encontrou = 1;
        }
    }

    quickSort(vetor, 0, index);
    quickSort(vetor, index+1, tam-1);
}

int main() {
    int vetor[] = {13, 11, 9, 57, 19,0, 4, 17, 37, 2, 33, 11};
    int tam = sizeof vetor/sizeof vetor[0];
    printf("\n-----------Original----------\n");
    for(int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }

    separar(vetor, tam);
    printf("\n-----------Separado----------\n");
    for(int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }

    defineQuickSort(vetor, tam);
    printf("\n-----------Final----------\n");
    for(int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
