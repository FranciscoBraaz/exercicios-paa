#include <stdio.h>

void printConjunto(int i, int n, int conj[]) {
    printf("Nivel %d: ", i);
    for(int j = 0; j <= i; j++) {
        printf("%d ", conj[j]);
        if(j == n) {
            return;
        }
    }
    printf("\n");

    printConjunto(i+1, n, conj);

}

int main() {
    int conj[] = {0, 1, 5, 9};
    printConjunto(0, 3, conj);
    return 0;
}
