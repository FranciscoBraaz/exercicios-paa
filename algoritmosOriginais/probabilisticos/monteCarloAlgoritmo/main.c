#include <stdio.h>
#define infinite -2147483647
#include <stdlib.h>
#include <time.h>

int monteCarlo(int X[], int n, int k) {
    int maior = infinite;
    for(int i = 0; i <= k; i++) {
        int j = (rand()  % (n - 1 + 1)) + 1;
        if(X[j] >= maior) {
            maior = X[j];
        }
    }
    return maior;
}

int main() {
    int k = 100;
    int X[] = {25,0,79,31,93,91,35,81,83,32,32,43,34,78,45,59,1,61,54,97,53,30,51,80,66,56,22,49,85,5,14,76,33,57,34,17,24,31,50,61,90,7,36,28,89,44,79,85,18,43,7,93,61,47,71,71,28,84,85,13,82,57,42,53,10,43,77,25,62,70,70,58,78,4,4,20,97,0,98,29,57,61,94,40,23,97,69,75,64,16,44,54,8,15,43,59,64,38,91,96};
    int len = sizeof X/ sizeof X[0];
    srand(time(0));
    int resp = monteCarlo(X, 100, 19);
    printf("%d ", resp);
    return 0;
}
