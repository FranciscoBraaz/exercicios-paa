#include <stdio.h>
#include <math.h>

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
        int meio = limEsq + ((limDir - limEsq )/2);
        mergeSort(vetorX, limEsq, meio);
        mergeSort(vetorX, meio + 1, limDir);
        intercala(vetorX , limEsq, meio, limDir);
    }
}

int main() {
    int vetor[] = {38, 16 , 27, 39, 12, 27};
    int len = (sizeof vetor/sizeof vetor[0]) - 1;
    for(int i = 0; i <= len; i++) {
        printf("%d ", vetor[i]);
    }
    mergeSort(vetor, 0, len);
    printf("\n\n");
    for(int i = 0; i <= len; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
