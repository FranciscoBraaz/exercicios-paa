#include <stdio.h>

int fibonacci(int n, int F[]){
    for(int i = 0; i <= n; i++) {
        if(i <= 1) {
            F[i] = i;
        } else {
            F[i] = F[i-1] + F[i-2];
        }
    }

    return F[n];
}

int main() {
    int num = 5;
    int F[num+1];

    int resp = fibonacci(num, F);
    printf("%d ", resp);
    return 0;
}
