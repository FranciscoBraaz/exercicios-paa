#include <stdio.h>

int max(int x, int y) {
    if(x > y) return x;

    return y;
}

int cutBread(int n, int C[], int P){
    int M[n+1];
    for(int i = 0; i<=n; i++) {
        if(i == 0) {
            M[i] = 0;
        } else if (i == 1) {
            M[i] = C[i-1];
        } else {
            if(i <= n) {
                if(i*2 <= n) {
                    M[i] = max(C[i-1] + M[i-1], C[i-1]*2);
                } else if((i + (i-1)) <= n ) {
                    M[i] = max(C[i - 1] + M[i-1], C[i-1] + C[i-2]);
                } else {
                    M[i] = C[i-1];
                }
            } else {
                if(C[i-1] > M[i-1]) {
                    M[i] = C[i-1];
                } else {
                    M[i] = M[i-1];
                }
            }
        }
    }

    return M[n];
}

int main() {
    int values[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int P[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int lenValues = 5;
    int resp = cutBread(lenValues, values, P);
    printf("%d ", resp);
    return 0;
}
