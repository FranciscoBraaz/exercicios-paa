#include <stdio.h>

//int max(int x, int y) {
//    if (x > y) return x;
//
//    return y;
//}

int calculateLis(int X[], int n) {
    int lis[n];

    for(int i=0; i <= n; i++) {
        lis[i] = 1;
    }

    int bigger = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(X[i] > X[j] && lis[i] < lis[j] + 1) { // 'lis[j] + 1' significa o tamanho da sequência que temos até a posição j mais o novo elemento que estamos verificando no momento atual
                lis[i] = lis[j] + 1;
                if(lis[j] > lis[i]) {
                    bigger = j;
                } else {
                    bigger = i;
                }
            }
        }
    }

    return lis[bigger];
}

int main() {
    int X[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int lenX = sizeof X/sizeof X[0] - 1;
    int resp = calculateLis(X, lenX);

    printf("%d ", resp);
    return 0;
}
