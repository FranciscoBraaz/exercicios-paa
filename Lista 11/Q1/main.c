#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct ponto{
    int x;
    int y;
};
typedef struct ponto Ponto;

int intercala(Ponto V[], Ponto Y[], int limEsq, int meio, int limDir, int tamY) {
    int tamA = meio-limEsq+1, tamB  = limDir-meio;
    Ponto vetorA[tamA];
    Ponto vetorB[tamB];
    for(int i = 0; i < tamA; i++) {
        vetorA[i] = V[limEsq + i];
    }
    for (int j = 0; j < tamB; j++) {
        vetorB[j] = V[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = limEsq;
    while(i < tamA && j < tamB) {
        if(vetorA[i].y < vetorB[j].y) {
            Y[k] = vetorA[i];
            i++;
        } else if(vetorA[i].y == vetorB[j].y && vetorA[i].x < vetorB[j].x) {
            Y[k] = vetorA[i];
            i++;
        } else {
            Y[k] = vetorB[j];
            j++;
        }
        k++;
    }

    while(i<tamA) {
        Y[k] = vetorA[i];
        i++;
        k++;
    }

    while(j<tamB) {
        Y[k] = vetorB[j];
        j++;
        k++;
    }

    tamY++;
    return tamY;
}


void maxHeapify(Ponto T[], int n, int i){
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
        maxHeapify(T, n, maior);
    }
}


void buildHeap(Ponto T[], int n) {
    for(int i = n/2; i>=0; i--) {
        maxHeapify(T, n, i);
    }
}

void heapSort(Ponto T[], int n) {
    buildHeap(T, n);

    for(int i = n; i >= 0; i--) {
        Ponto aux = T[0];
        T[0] = T[i];
        T[i] = aux;
        maxHeapify(T, i-1, 0);

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

double verificaFronteira(Ponto V[], int m, Ponto Y[], int k, double d) {
    for(int i=0; i<=m-1; i++){
        int j = i+1;
        while(j <= m && abs(Y[j].y - Y[i].y) < d){
            d = min(calcDistancia(Y[j], Y[i]), d);
            j++;
        }
    }

    return d;
}


double mergeSort(Ponto S[], Ponto Y[], int esq, int dir, int n, int tamY) {
    double d;
    Ponto vetorAux[n];
    int cap = 0;
    if(dir - esq == 0) {
        d =  1000.0;
    } else if (dir - esq == 1) {
        d =  calcDistancia(S[esq], S[dir]);
    } else {
        int meio = esq + ((dir - esq )/2);
        double d1 = mergeSort(S, Y, esq, meio,n, 0 );
        double d2 = mergeSort(S, Y, meio + 1, dir,n,0 );
        tamY = intercala(S, Y, esq, meio, dir, tamY);
        d = min(d1, d2);
        for(int i = 0; i <= n; i++) {
            if(abs(S[i].x - S[meio].x) < d) {
                vetorAux[cap] = S[i];
                cap++;
            }
        }
        d = verificaFronteira(vetorAux, cap-1, Y, 2+tamY-1,  d);
    }

    return d;
}

int main() {
//    Ponto a = {1, 1};
//    Ponto b = {2, 2};
//    Ponto c = {3, 2};
//    Ponto d = {4, 6};
//    Ponto e = {5, 4};
//    Ponto f = {6, 1};
    Ponto a = {2, 3};
    Ponto b = {12, 30};
    Ponto c = {40, 50};
    Ponto d = {5, 1};
    Ponto e = {12, 10};
    Ponto f = {3, 4};
    Ponto V[] = {a, b, d, c, e, f};

    int n = sizeof V/sizeof V[0] - 1;
    Ponto Y[n];
    for(int i = 0; i <= n; i++) {
        Y[i].x = 1000;
        Y[i].y = 1000;
    }

    heapSort(V, n);

    double resp = mergeSort(V, Y, 0, n, n, 0);

    printf("\n%.2lf", resp);

    return 0;
}
