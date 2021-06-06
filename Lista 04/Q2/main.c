#include <stdio.h>

int intercala(int vetorFinal[], int limEsq, int meio, int limDir) {
    int inversoes = 0;
    int tamA = meio-limEsq+1, tamB  = limDir-meio;
    int vetorA[tamA];
    int vetorB[tamB];
    for(int i = 0; i < tamA; i++) {
        vetorA[i] = vetorFinal[limEsq + i];
    }
    int len = sizeof vetorA/vetorA[0];
    for (int j = 0; j < tamB; j++) {
        vetorB[j] = vetorFinal[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = limEsq;
    int leftSubArray = limEsq;
    while(i < tamA && j < tamB) {

        if(vetorA[i] <= vetorB[j]) {
            vetorFinal[k] = vetorA[i];
            i++;
        } else {
            vetorFinal[k] = vetorB[j];
            j++;
            inversoes += tamA - i;
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

    return inversoes;
}

int mergeSort(int vetorX[], int limEsq, int limDir) {
    int inversoes = 0;
    if(limEsq < limDir) {
        int meio = limEsq + ((limDir - limEsq )/2);
        inversoes += mergeSort(vetorX, limEsq, meio);
        inversoes += mergeSort(vetorX, meio + 1, limDir);
        inversoes += intercala(vetorX , limEsq, meio, limDir);
    }
    return inversoes;
}

int main() {
    int vetor[] = { 4, 3, 7, 2};
    int len = (sizeof vetor/sizeof vetor[0]) - 1;
    int inversoes = mergeSort(vetor, 0, len);

    for(int i = 0; i <= len; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
    printf("%d", inversoes);
    return 0;
}
