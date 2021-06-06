#include <stdio.h>

int fatorial(int valor) {
    int fat = 1;
    while(valor > 0) {
        fat = fat * valor;
        valor--;
    }
    return fat;
}

void countingSort(int vetorA[], int tamA, int k) {
    int vetorC[k+1];
    int qtdPares = 0;
    for(int i = 0; i<=k+1; i++) {
        vetorC[i] = 0;
    }
    for(int j = 1; j<=tamA; j++) {
        vetorC[vetorA[j-1]] = vetorC[vetorA[j-1]] + 1;
    }

    for(int i = 1; i<=k+1; i++) {
        int combinacao = fatorial(vetorC[i])/2;
        qtdPares += combinacao;
    }

    printf("\nPares distintos: %d\n", qtdPares);
}

int main() {
    int vetorA[] = {1, 4, 1, 2, 2, 1, 7, 5, 2};
    int tam = sizeof vetorA/sizeof vetorA[0];

    countingSort(vetorA, tam, 8);

    return 0;
}
