#include <stdio.h>

struct item{
    int tam;
    char dir;
};
typedef struct item Item;


void calculaLCS(char X[], int m, char Y[], int n, Item matriz[m+1][n+1]) {
    for(int i = 0; i <= m; i++) {
        matriz[i][0].tam = 0;
        matriz[i][0].dir = '*';
    }

    for(int j = 0; j <= n; j++) {
        matriz[0][j].tam = 0;
        matriz[0][j].dir = '*';
    }

    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++) {
            char teste1 = X[i-1];
            char teste2 = Y[j-1];
            int valueB0 = matriz[2][0].tam;
            int valueC0 = matriz[3][0].tam;
            if(X[i-1] == Y[j-1]) {
                matriz[i][j].tam = matriz[i-1][j-1].tam + 1;
                int teste3 = matriz[i][j].tam;
                matriz[i][j].dir = 'D';

            } else {
                int tamTeste1 = matriz[i-1][j].tam;
                int tamTeste2 = matriz[i][j-1].tam;
                if(matriz[i-1][j].tam >= matriz[i][j-1].tam) {
                    matriz[i][j].tam = matriz[i-1][j].tam;
                    matriz[i][j].dir = 'A';
                } else {
                    matriz[i][j].tam = matriz[i][j-1].tam;
                    int teste4  = matriz[i][j].tam;
                    matriz[i][j].dir = 'E';
                }
            }
        }
    }

    for(int i = 0; i<=m; i++) {
        for(int j = 0; j<=n; j++) {
            printf("%d ", matriz[i][j].tam);
        }
        printf("\n");
    }

//    return matriz[m][n].tam;
}

int main() {
    char X[] = "ABCB";
    int m = (sizeof X/sizeof X[0]) - 1;
    char Y[] = "BDCAB";
    int n = sizeof Y/sizeof Y[0] - 1;
    Item matriz[m+1][n+1];

    calculaLCS(X,m, Y, n, matriz);
//    printf("%d ", resp);
    return 0;
}
