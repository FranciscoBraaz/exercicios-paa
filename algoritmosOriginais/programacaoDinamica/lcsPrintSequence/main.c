#include <stdio.h>

struct item{
    int tam;
    char dir;
};
typedef struct item Item;


void imprime2(char X[], int m, char Y[], int n, Item matriz[m+1][n+1]) {
    int index = matriz[m][n].tam;

    char lcs[index+1];
    int tam = sizeof lcs/sizeof lcs[0] - 1;
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--; j--; index--;
        }

        else if (matriz[i-1][j].tam > matriz[i][j-1].tam)
            i--;
        else
            j--;
    }

    for (int k = 0; k < tam; k++) {
        printf("%c", lcs[k]);
    }
}

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
            if(X[i-1] == Y[j-1]) {
                matriz[i][j].tam = matriz[i-1][j-1].tam + 1;
                matriz[i][j].dir = 'D';
            } else {
                if(matriz[i-1][j].tam >= matriz[i][j-1].tam) {
                    matriz[i][j].tam = matriz[i-1][j].tam;
                    matriz[i][j].dir = 'A';
                } else {
                    matriz[i][j].tam = matriz[i][j-1].tam;
                    matriz[i][j].dir = 'E';
                }
            }
        }
    }

    imprime2(X, m, Y, n, matriz);
}

int main() {
    char X[] = "ABCB";
    int m = sizeof X/sizeof X[0] - 1;
    char Y[] = "BDCAB";
    int n = sizeof Y/sizeof Y[0] - 1;
    Item matriz[m+1][n+1];

    calculaLCS(X,m, Y, n, matriz);
//    printf("%d ", resp);
    return 0;
}
