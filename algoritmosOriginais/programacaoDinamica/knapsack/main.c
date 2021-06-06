#include <stdio.h>

int max(int x, int y){
    if(x > y) return x;

    return y;
}

int knapsack(int V[], int P[], int maxCap, int n){
    int matrixK[n+1][maxCap+1];
    for(int i = 0; i < n+1; i++){
        for(int cap = 0; cap < maxCap+1; cap++){
            if(i == 0 || cap == 0) {
                matrixK[i][cap] = 0;
            }else if(P[i-1] <= cap){
                matrixK[i][cap] = max(V[i-1] + matrixK[i-1][cap-P[i-1]],matrixK[i-1][cap]);
            } else {
                matrixK[i][cap] = matrixK[i-1][cap];
            }
        }
    }

    return matrixK[n][maxCap];
}

int main() {
    int V[] = {60, 100, 120};
    int lenV = sizeof V/sizeof V[0];
    int P[] = {1, 2, 3};
    int maxCap = 5;

    int resp = knapsack(V, P, maxCap, lenV);
    printf("%d ", resp);
    return 0;
}
