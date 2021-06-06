#include <stdio.h>

int max(int x, int y){
    if(x > y) return x;

    return y;
}

int knapsack(int V[], int P[], int maxCap, int n){
    int matrixK[n+1][maxCap+1];
    for(int i = 0; i <= n; i++){
        for(int cap = 0; cap <= maxCap; cap++){
            if(i == 0 || cap == 0) {
                matrixK[i][cap] = 0;
            }else if(P[i-1] <= cap){
                matrixK[i][cap] = max(V[i-1] + matrixK[i][cap-P[i-1]],matrixK[i-1][cap]);
            } else {
                matrixK[i][cap] = matrixK[i-1][cap];
            }
        }
    }

    return matrixK[n][maxCap];
}

int main() {
    int V[] = {1, 4, 7, 10};
    int lenV = sizeof V/sizeof V[0];
    int P[] = {1, 2, 3, 5};
    int maxCap = 8;

    int resp = knapsack(V, P, maxCap, lenV);
    printf("%d ", resp);
    return 0;
}
