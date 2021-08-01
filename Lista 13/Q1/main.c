#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void gerarSenha(char A[], int n);

char caracterAleatorio(bool *numero, bool *especial, bool *maiscula, bool *minuscula){
    int x = rand() % 95;
    if(x <= 14) {
        *especial = true;
    } else if (x >= 15 && x <= 24) {
        *numero = true;
    } else if (x >= 25 && x <= 31) {
        *especial = true;
    } else if (x >= 32 && x <= 57) {
        *maiscula = true;
    } else if (x >= 58 && x <= 63) {
        *especial = true;
    } else if (x >= 64 && x <= 89) {
        *minuscula = true;
    } else {
        *especial = true;
    }
    x = x + 33;
    char y = x;
    return y;
}

void checarSenha(char A[], int n, bool *numero, bool *especial, bool *maiscula, bool *minuscula) {
    while(!(*numero) || !(*especial) || !(*maiscula) || !(*minuscula)) {
        gerarSenha(A, n);
    }

    for(int i =0; i<=n; i++) {
        printf("%c", A[i]);
    }
    exit(0);
}

void gerarSenha(char A[], int n) {
    bool numero = false;
    bool *ptrNumero = &numero;
    bool especial = false;
    bool *ptrEspecial = &especial;
    bool maiscula = false;
    bool *ptrMaiscula = &maiscula;
    bool minuscula = false;
    bool *ptrMinuscula = &minuscula;

    for(int i = 0; i <= n; i++) {
        A[i] = caracterAleatorio(ptrNumero, ptrEspecial, ptrMaiscula, ptrMinuscula);
    }

    checarSenha(A, n, ptrNumero, ptrEspecial, ptrMaiscula, ptrMinuscula);

}


int main() {
    srand(time(NULL));
    int tam = 10;
    char A[tam];
    gerarSenha(A, tam-1);
    return 0;
}
