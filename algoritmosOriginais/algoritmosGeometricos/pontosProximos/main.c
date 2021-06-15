#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct ponto{
    int x;
    int y;
};
typedef struct ponto Ponto;


void maxHeapifyEixoX(Ponto T[], int n, int i){
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    int maior = 0;
    if(esq <= n && T[esq].x > T[i].x){
        maior = esq;
    } else if (esq <= n && T[esq].x == T[i].x && (T[esq].y > T[i].y)) {
        maior = esq;
    } else {
        maior= i;
    }

    if(dir <= n && T[dir].x > T[maior].x){
        maior = dir;
    } else if ((dir <= n) && (T[dir].x == T[maior].x) && (T[dir].y > T[maior].y)){
        maior = dir;
    }

    if(maior != i) {
        Ponto aux = T[i];
        T[i] = T[maior];
        T[maior] = aux;
        maxHeapifyEixoX(T, n, maior);
    }
}

void maxHeapifyEixoY(Ponto T[], int n, int i){
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    int maior = 0;
    if(esq <= n && T[esq].y > T[i].y){
        maior = esq;
    } else if (esq <= n && T[esq].y == T[i].y && (T[esq].x > T[i].x)) {
        maior = esq;
    } else {
        maior= i;
    }

    if(dir <= n && T[dir].y > T[maior].y){
        maior = dir;
    } else if (dir <= n && T[dir].y == T[maior].y && (T[dir].x > T[maior].x)){
        maior = dir;
    }

    if(maior != i) {
        Ponto aux = T[i];
        T[i] = T[maior];
        T[maior] = aux;
        maxHeapifyEixoY(T, n, maior);
    }
}

void buildHeapEixoX(Ponto T[], int n) {
    for(int i = n/2; i>=0; i--) {
        maxHeapifyEixoX(T, n, i);
    }
}

void buildHeapEixoY(Ponto T[], int n) {
    for(int i = n/2; i>=0; i--) {
        maxHeapifyEixoY(T, n, i);
    }
}

//Para o parâmetro 'eixo': 0 = eixo x, 1 = eixo y
void heapSort(Ponto T[], int n, int eixo) {
    if(eixo == 0) {
        buildHeapEixoX(T, n);
    } else {
        buildHeapEixoY(T, n);
    }


    for(int i = n; i >= 0; i--) {
        Ponto aux = T[0];
        T[0] = T[i];
        T[i] = aux;
        if(eixo == 0) {
            maxHeapifyEixoX(T, i-1, 0);
        } else {
            maxHeapifyEixoY(T, i-1, 0);
        }
    }
}

double calcDistancia(Ponto a, Ponto b) {
    int r1 = (b.x - a.x);
    int r2 = (b.y - a.y);
    double dist = sqrt((r1*r1) + (r2*r2));

    return dist;
}

double min (double x, double y) {
    if(x < y) return x;

    return y;
}

double calcDistanciaFront(Ponto vetor[], int m, double d) {
    heapSort(vetor, m, 1);

    for(int i=0; i<=m-1; i++){
        int j = i+1;
        while(j <= m && abs(vetor[j].y - vetor[i].y) < d){
            d = min(calcDistancia(vetor[j], vetor[i]), d);
            j++;
        }
    }

    return d;
}


double mergeSort(Ponto vetor[], int limEsq, int limDir, int n) {
    double d;
    Ponto vetorAux[n];
    int cap = 0;
    if(limDir - limEsq == 0) {
        d =  1000.0;
    } else if (limDir - limEsq == 1) {
        d =  calcDistancia(vetor[limEsq], vetor[limDir]);
    } else {
        int meio = limEsq + ((limDir - limEsq )/2);
        double d1 = mergeSort(vetor, limEsq, meio,n );
        double d2 = mergeSort(vetor, meio + 1, limDir,n );
        d = min(d1, d2);
        for(int i = 0; i <= n; i++) {
            if(abs(vetor[i].x - vetor[meio].x) < d) {
                vetorAux[cap] = vetor[i];
                cap++;
            }
        }
        d = calcDistanciaFront(vetorAux, cap-1, d);
    }

    return d;
}

int main() {
    Ponto a = {1, 1};
    Ponto b = {2, 2};
    Ponto c = {3, 2};
    Ponto d = {4, 6};
    Ponto e = {5, 4};
    Ponto f = {6, 1};
    Ponto array[] = {a, b, d, c, e, f};
    int len = sizeof array/sizeof array[0] - 1;

    heapSort(array, len, 0);
    printf("\n-------------Vetor ordenado------------\n");
    for(int i = 0; i<=len; i++){
        printf("(%d %d)", array[i].x, array[i].y);
    }

    double resp = mergeSort(array, 0, len, len);

    printf("\n%.2lf", resp);

    return 0;
}
