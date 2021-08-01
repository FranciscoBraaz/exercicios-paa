#include <stdio.h>

// Esse algoritmo é baseado na técnica da aula:
// https://www.youtube.com/watch?v=vdVpRjO7g84
// Fonte do algoritmo original: https://www.programmersought.com/article/81891628942/

void knapsack(int i, int cw, int cv, int* values, int* weights, int n, int w, int *ptrMaxV){

    printf("i:%d value:%d\n", i, cv);

    if (cw == w || i == n){
        if (cv > *ptrMaxV) {
            *ptrMaxV = cv;
        }
        return;
    }
    knapsack(i+1, cw, cv, values, weights, n, w, ptrMaxV);
    if (cw + weights[i] <= w){
        knapsack(i+1, cw+weights[i], cv+values[i], values, weights, n, w, ptrMaxV);
    }
}

int main() {
    int v[] = {60, 100, 120};
    int w[] = {1, 2, 3};

    int qtdElements = sizeof v/sizeof v[0];
    int maxV = 0;
    int *ptrMaxV = &maxV;

    knapsack(0, 0, 0, v, w,qtdElements, 5, ptrMaxV);
    printf("Valor maximo: %d", *ptrMaxV);
    return 0;
}