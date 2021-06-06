#include <stdio.h>

void insertionSort(int T[], int n) {
    for(int i = 1; i<n; i++){
        int aux = T[i];
        int j = i - 1;
        while(j >= 0 && aux < T[j]) {
            T[j+1] = T[j];
            j--;
        }
        T[j+1] = aux;
    }
}

int main() {
    int array[] = {4, 8, 10, 2, 5, 1, 7};
    int len = sizeof array/sizeof array[0];
    for(int i = 0; i<len; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    insertionSort(array, len);

    for(int i = 0; i<len; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
