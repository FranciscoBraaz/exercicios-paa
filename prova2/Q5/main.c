#include <stdio.h>
#include "stdlib.h"
#include "time.h"



void embaralha(int n, int cartas[], int k) {
    for(int i = 0; i < k; i++) {
        int c1 = 1 + (rand() % (n - 1));
        int c2 = 1 + (rand() % (n - 1));

        int aux = c1;
        cartas[c1-1] = cartas[c2-1];
        cartas[c2-1] = aux;
    }
}

int main() {
    int n = 52;
    int cartas[n];
    int k = 100;
    for(int i = 0; i < n; i++) {
        cartas[i] = i+1;
    }
    srand(time(0));

    embaralha(n, cartas, k);
    for(int i = 0; i < n; i++) {
        printf("%d ", cartas[i]);
    }

    return 0;
}
