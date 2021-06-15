#include <stdio.h>

void maxHeapify(int T[], int n, int i){
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    int maior = 0;
    if(esq <= n && T[esq] > T[i]){
        maior = esq;
    } else {
        maior= i;
    }

    if(dir <= n && T[dir] > T[maior]){
        maior = dir;
    }

    if(maior != i) {
        int aux = T[i];
        T[i] = T[maior];
        T[maior] = aux;
        maxHeapify(T, n, maior);
    }
}

void buildHeap(int T[], int n) {
    for(int i = n/2; i>=0; i--) {
        maxHeapify(T, n, i);
    }
}

void heapSort(int T[], int n) {

    for(int i = n; i > 0; i--) {
        int aux = T[0];
        int teste = T[i];
        T[0] = T[i];
        T[i] = aux;
        maxHeapify(T, i-1, 0);
    }
}

int main() {
    int array[] = {2, 3, 4, 5};
    int len = sizeof array/sizeof array[0]-1;;

    buildHeap(array, len);

    printf("\n-------------Heap construido------------\n");
    for(int i = 0; i<=len; i++){
        printf("%d ", array[i]);
    }
    heapSort(array, len);
    printf("\n-------------Vetor ordenado------------\n");
    for(int i = 0; i<=len; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
