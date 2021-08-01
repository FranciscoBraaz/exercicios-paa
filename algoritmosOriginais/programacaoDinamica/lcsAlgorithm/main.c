#include <stdio.h>

int max(int x, int y) {
    if (x > y) return x;

    return y;
}

int calculaLCS(char X[], int m, char Y[], int n, int matriz[m+1][n+1]) {
    for(int i = 0; i <= m; i++) {
        matriz[i][0] = 0;
    }

    for(int j = 0; j <= n; j++) {
        matriz[0][j] = 0;
    }

    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++) {
            if(X[i-1] == Y[j-1]) {
                matriz[i][j] = matriz[i-1][j-1] + 1;
            } else {
                matriz[i][j] = max(matriz[i-1][j], matriz[i][j-1]);
            }
        }
    }

    return matriz[m][n];
}

int main() {
    char X[] = "ABCBA";
    int m = sizeof X/sizeof X[0] - 1;
    char Y[] = "BDCABCEA";
    int n = sizeof Y/sizeof Y[0] - 1;
    int matriz[m+1][n+1];

    int resp = calculaLCS(X,m, Y, n, matriz);
    printf("%d ", resp);
    return 0;
}
