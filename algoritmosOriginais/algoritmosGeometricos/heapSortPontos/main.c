#include <stdio.h>

struct ponto{
    int x;
    int y;
};
typedef struct ponto Ponto;


void maxHeapify(Ponto T[], int n, int i){
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    int maior = 0;
    if(esq <= n && T[esq].x > T[i].x){
        maior = esq;
    } else if (esq <= n && T[esq].x == T[i].x && T[esq].y > T[i].y) {
        maior = esq;
    } else {
        maior= i;
    }

    if(dir <= n && T[dir].x > T[maior].x){
        maior = dir;
    } else if (dir <= n && T[dir].x == T[maior].x && T[dir].y > T[maior].y){
        maior = dir;
    }

    if(maior != i) {
        Ponto aux = T[i];
        T[i] = T[maior];
        T[maior] = aux;
        maxHeapify(T, n, maior);
    }
}

void buildHeap(Ponto T[], int n) {
    for(int i = n/2; i>=0; i--) {
        maxHeapify(T, n, i);
    }
}

void heapSort(Ponto T[], int n) {

    for(int i = n; i > 0; i--) {
        Ponto aux = T[0];
        T[0] = T[i];
        T[i] = aux;
        maxHeapify(T, i-1, 0);
    }
}

int main() {
    Ponto a = {3, 2};
    Ponto b = {3, 6};
    Ponto c = {2, 4};
    Ponto d = {5, 1};
    Ponto array[] = {a, b, d, c};
    int len = sizeof array/sizeof array[0] - 1;

    buildHeap(array, len);

    printf("\n-------------Heap construido------------\n");
    for(int i = 0; i<=len; i++){
        printf("(%d %d)", array[i].x, array[i].y);
    }
    heapSort(array, len);
    printf("\n-------------Vetor ordenado------------\n");
    for(int i = 0; i<=len; i++){
        printf("(%d %d)", array[i].x, array[i].y);
    }
    return 0;
}
