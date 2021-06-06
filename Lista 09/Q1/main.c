#include <stdio.h>

int max(int x, int y) {
    if(x > y) return x;

    return y;
}

int calcMontante(int n, int C[]){
    int M[n+1];
    for(int i = 0; i<=n; i++) {
        if(i == 0) {
            M[i] = 0;
        } else if (i == 1) {
            M[i] = C[i-1];
        } else {
            M[i] = max(C[i-1] + M[i-2], M[i-1]);
        }
    }

    return M[n];
}

int main() {
    int values[] = {5, 1, 9, 10, 9, 2};
    int lenValues = sizeof values/sizeof values[0];
    int resp = calcMontante(lenValues, values);
    printf("%d ", resp);
    return 0;
}
