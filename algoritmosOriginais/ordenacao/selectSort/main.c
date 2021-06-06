#include <stdio.h>

void selectSort(int T[], int n) {
    for(int i=0; i<n-1; i++){
        int smaller = i;
        for(int j = i+1; j<n; j++){
            if(T[j] < T[smaller]){
                smaller = j;
            }
        }
        int aux = T[i];
        T[i] = T[smaller];
        T[smaller] = aux;
    }
}

int main() {
    int array[] = {5, 4, 8, 2, 9, 1};
    int len = sizeof array/sizeof array[0];
    for(int i = 0; i<len; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    selectSort(array, len);
    for(int i = 0; i<len; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
