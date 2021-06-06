#include <stdio.h>

void separarVetor(int vetor[], int tam, int* vetorPar, int* vetorImpar) {
    int j = 0;
    int k = 0;
    for(int i = 0; i < tam; i++) {
        if(vetor[i] % 2 == 0) {
            vetorPar[j] = vetor[i];
            j++;
        } else {
            vetorImpar[k] = vetor[i];
            k++;
        }
    }
}

void trocaMenor(int* vetorPar, int i, int menor) {
    int aux = vetorPar[i];
    vetorPar[i] = vetorPar[menor];
    vetorPar[menor] = aux;
}

void trocaMaior(int* vetorImpar, int i, int maior) {
    int aux = vetorImpar[i];
    vetorImpar[i] = vetorImpar[maior];
    vetorImpar[maior] = aux;
}

void ordenarVetor(int* vetorPar, int* vetorImpar, int tam) {
    for(int i = 0; i < tam - 1; i++) {
        int menor = i;
        int maior = i;
        for(int j = i + 1; j < tam; j++) {
            if(vetorPar[j] < vetorPar[menor]) {
                menor = j;
            }
            if(vetorImpar[j] > vetorImpar[maior]) {
                maior = j;
            }
        }
        trocaMenor(vetorPar, i, menor);
        trocaMaior(vetorImpar, i, maior);
    }
}

void novoVetor(int* vetor, int tam, int* vetorPar, int* vetorImpar) {
    int i = 0;
    int j = 0;
    for(int k = 0; k < tam; k++) {
        if(k % 2 == 0) {
            vetor[k] = vetorPar[i];
            i++;
        } else {
            vetor[k] = vetorImpar[j];
            j++;
        }
    }
}

int main() {
    int vetorOriginal[] = {9, 3, 1, 4, 40, 16, 19, 21, 5, 6, 2, 24};
    int tam  = sizeof(vetorOriginal)/sizeof(int);
    int vetorPar[tam/2];
    int vetorImpar[tam/2];
    separarVetor(vetorOriginal, tam, vetorPar, vetorImpar);
    ordenarVetor(vetorPar, vetorImpar, tam/2);
    novoVetor(vetorOriginal, tam, vetorPar, vetorImpar);

    for(int i = 0; i < tam/2; i++) {
        printf("%d ", vetorPar[i]);
    }
    printf("\n");
    for(int i = 0; i < tam/2; i++) {
        printf("%d ", vetorImpar[i]);
    }

    printf("\n");
    for(int i = 0; i < tam; i++) {
        printf("%d ", vetorOriginal[i]);
    }
    return 0;
}
