#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calcularPi(int n){
    double qtd = 0.0;
    for(int i = 0; i < n; i++) {
        double x = rand() / (double)RAND_MAX;
        double y = rand() / (double)RAND_MAX;

        if(((x*x) + (y*y)) <= 1){
            qtd++;
        }
    }
    printf("\n");
    double pi = (double) 4 * (qtd / n);
    return pi;
}

int main() {
    srand(time(0));

    double resp = calcularPi(10000);
    printf("%f ", resp);
    return 0;
}
