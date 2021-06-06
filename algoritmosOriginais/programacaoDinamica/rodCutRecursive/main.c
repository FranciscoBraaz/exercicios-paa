#include <stdio.h>

int max(int x, int y) {
    if(x > y) return x;

    return y;
}

int rodCutting(int P[], int n){
    if( n == 0) return 0;
    int q = -1000;
    for(int i = 1; i <= n; i++) {
        q = max(q, P[i-1] + rodCutting(P, n-i));
    }

    return q;
}

int main() {
    int P[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 4;
    int resp = rodCutting(P, n);
    printf("%d", resp);
    return 0;
}
