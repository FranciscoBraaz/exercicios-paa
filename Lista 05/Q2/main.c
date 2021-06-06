#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[20];
    int posicao;
};
typedef struct pessoa Pessoa;

void rearranjeHeap(Pessoa vetor[], int n) {
    int pai = 0;
    int filho = 1;

    while(filho <= n-1) {
        if(strlen(vetor[filho].nome) < strlen(vetor[filho+1].nome)) {
            filho += 1;
        } else if(strlen(vetor[filho].nome) == strlen(vetor[filho+1].nome) && vetor[filho+1].posicao > vetor[filho].posicao) {
            filho += 1;
        }

        if(strlen(vetor[filho].nome) >= strlen(vetor[pai].nome)){
            if(strlen(vetor[filho].nome) > strlen(vetor[pai].nome)){
                char aux[20];
                strcpy(aux, vetor[pai].nome);
                strcpy(vetor[pai].nome, vetor[filho].nome);
                strcpy(vetor[filho].nome, aux);
                int auxIndex = vetor[pai].posicao;
                vetor[pai].posicao = vetor[filho].posicao;
                vetor[filho].posicao = auxIndex;
                pai = filho;
                filho = (filho*2) + 1;
            } else if(strlen(vetor[filho].nome) == strlen(vetor[pai].nome) && vetor[filho].posicao > vetor[pai].posicao) {
                char aux[20];
                strcpy(aux, vetor[pai].nome);
                strcpy(vetor[pai].nome, vetor[filho].nome);
                strcpy(vetor[filho].nome, aux);
                int auxIndex = vetor[pai].posicao;
                vetor[pai].posicao = vetor[filho].posicao;
                vetor[filho].posicao = auxIndex;
                pai = filho;
                filho = (filho*2) + 1;
            }
        } else {
            filho = n;
        }
    }
}

void maxHeap(Pessoa vetor[], int i, int n) {
    int esq = (2*i) + 1, dir = (2*i) + 2;
    int maior;

    if(esq <= n && strlen(vetor[esq].nome) >= strlen(vetor[i].nome)) {
        if(strlen(vetor[esq].nome) > strlen(vetor[i].nome)) {
            maior = esq;
        }

        if(strlen(vetor[esq].nome) == strlen(vetor[i].nome) && vetor[esq].posicao > vetor[i].posicao) {
            maior = esq;
        }

    } else  {
        maior = i;
    }

    if(dir <= n && strlen(vetor[dir].nome) >= strlen(vetor[maior].nome)) {
        if(strlen(vetor[dir].nome) > strlen(vetor[maior].nome)) {
            maior = dir;
        }

        if(strlen(vetor[dir].nome) == strlen(vetor[maior].nome) && vetor[dir].posicao > vetor[maior].posicao) {
            maior = dir;
        }
    }
    if(maior != i) {
        char aux[20];
        strcpy(aux, vetor[i].nome);
        strcpy(vetor[i].nome, vetor[maior].nome);
        strcpy(vetor[maior].nome, aux);
        int auxIndex = vetor[i].posicao;
        vetor[i].posicao = vetor[maior].posicao;
        vetor[maior].posicao = auxIndex;
        maxHeap(vetor, maior, n);
    }

}

void construirHeap(Pessoa vetor[], int n) {
    for(int i = n/2; i>= 0; i--){
        maxHeap(vetor, i, n);
    }
}

void heapSort(Pessoa vetor[], int n) {
    construirHeap(vetor, n);
    printf("\n------------ Heap construido -----------\n");
    for(int i = 0; i<=n; i++) {
        printf("%s ", vetor[i].nome);
    }

    for(int i = n; i>=1; i--) {
        char aux[20];
        int auxIndex;

        strcpy(aux, vetor[0].nome);
        auxIndex = vetor[0].posicao;
        strcpy(vetor[0].nome, vetor[i].nome);
        strcpy(vetor[i].nome, aux);
        vetor[0].posicao = vetor[i].posicao;
        vetor[i].posicao = auxIndex;
        rearranjeHeap(vetor, i-1);
    }
}

int main() {
    Pessoa vetorPessoas[9];
    char nomes[][20] = {"Caio", "Ca", "Francisco", "Bo", "Francisoc" , "Bruna", "Peter" , "Gau", "Lau"};
    int tam = 8;

    for(int i = 0; i <=8 ;i++) {
        strcpy(vetorPessoas[i].nome, nomes[i]);
        vetorPessoas[i].posicao = i;
    }

    heapSort(vetorPessoas, tam);
    printf("\n------------ Heap ordenado -----------\n");
    for(int i = 0; i<=tam; i++) {
        printf("%s ", vetorPessoas[i].nome);
    }

    return 0;
}
