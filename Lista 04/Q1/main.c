#include <stdio.h>

void intercala(int vetorFinal[], int limEsq, int meio, int limDir) {
    int tamA = meio-limEsq+1, tamB  = limDir-meio;
    int vetorA[tamA];
    int vetorB[tamB];
    for(int i = 0; i < tamA; i++) {
        vetorA[i] = vetorFinal[limEsq + i];
    }
    for (int j = 0; j < tamB; j++) {
        vetorB[j] = vetorFinal[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = limEsq;
    while(i < tamA && j < tamB) {
        if(vetorA[i] <= vetorB[j]) {
            vetorFinal[k] = vetorA[i];
            i++;
        } else {
            vetorFinal[k] = vetorB[j];
            j++;
        }
        k++;
    }

    while(i<tamA) {
        vetorFinal[k] = vetorA[i];
        i++;
        k++;
    }

    while(j<tamB) {
        vetorFinal[k] = vetorB[j];
        j++;
        k++;
    }
}

void mergeSort(int vetorX[], int limEsq, int limDir) {
    if(limEsq < limDir) {
        int meio = (limDir + limEsq )/2;
        mergeSort(vetorX, limEsq, meio);
        mergeSort(vetorX, meio + 1, limDir);
        intercala(vetorX , limEsq, meio, limDir);
    }
}

int verificaSoma(int vetorA[], int vetorB[], int tamA, int tamB,int x,int numeros[]) {
    int i = 0, j = tamB;
    while(i <= tamA && j >= 0 ) {
        int soma = vetorA[i] + vetorB[j];
        if(soma == x) {
            numeros[0] = vetorA[i];
            numeros[1] = vetorB[j];
            return 1;
        } else if (soma > x) {
            j--;
        } else {
            i++;
        }
    }
    return 0;
}

int main() {
    int vetorA[] = {15, 1 , 6, 7};
    int vetorB[] = {0, 14 , 15, 3};
    int x = 8;
    int numeros[2];
    int lenA = (sizeof vetorA/sizeof vetorA[0]) - 1;
    int lenB = (sizeof vetorB/sizeof vetorB[0]) - 1;

    mergeSort(vetorA, 0, lenA);
    mergeSort(vetorB, 0, lenB);
    int resp = verificaSoma(vetorA, vetorB, lenA, lenB, x, numeros);
    printf("\n");
    printf("%d ", resp);
    printf("\n\n");
    if(resp == 0) {
        printf("Nao encontrado");
    } else {
        for(int i = 0; i < 2; i++) {
            printf("%d ", numeros[i]);
        }
    }

    return 0;
}

