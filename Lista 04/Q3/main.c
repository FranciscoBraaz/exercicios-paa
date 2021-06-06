#include <stdio.h>

void ordenarNumeros(int vetor[], int tam) {
   int i = 0;
   int k = 1;

    while (i < tam-1 && k < tam) {
        if(vetor[i] < 0) {
            i++;
        }
        if(vetor[i] >= 0 && vetor[k] < 0) {
            int aux = vetor[i];
            vetor[i] = vetor[k];
            vetor[k] = aux;
            i++;
        }
        k++;
    }
    i=0;
    k=1;
    while (i < tam-1 && k < tam) {
        if(vetor[i] <= 0) {
            i++;
        } else if(vetor[i] > 0 && vetor[k] == 0) {
            int aux = vetor[i];
            vetor[i] = vetor[k];
            vetor[k] = aux;
            i++;
        }
        k++;
    }
}

int main() {
    int vetor[] = {-1, 0, -1, -5, 0, -6, 0, 0, 10, 0, 1};
    int len = ((sizeof vetor/sizeof vetor[0]));

    for(int i = 0; i <= len-1; i++) {
        printf("%d ", vetor[i]);
    }

    ordenarNumeros(vetor, len);
    printf("\n\n");

    for(int i = 0; i <= len-1; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}
