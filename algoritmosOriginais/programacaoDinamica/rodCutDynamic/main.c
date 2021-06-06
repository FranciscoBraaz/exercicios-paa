#include <stdio.h>

int max(int x, int y) {
    if(x > y) return x;

    return y;
}

int breadCut(int P[], int n) {
    int A[n+1];
    A[0] = 0;
    for(int i = 1; i <= n; i++) {
        int q = -1;
        for(int j = 1; j <= i; j++) {
            q = max(q, P[j-1] + A[i-j]);
        }
        A[i] = q;
    }

    return A[n];
}

int main() {
//    int P[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int P[] = {3, 7, 10, 11, 12, 15, 17};
    int n = 4;
    int resp = breadCut(P, n);
    printf("%d", resp);
    return 0;
}
