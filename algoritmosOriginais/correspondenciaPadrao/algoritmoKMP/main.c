#include <stdio.h>

void computaNext(char padrao[], int tam, int next[]) {
    next[0] = -1, next[1] = 0;
    int j = 0;
    for(int i = 2; i<=tam; i++) {
        j = next[i-1]+1;
        while(padrao[i-1] != padrao[j-1] && j > 0) {
            j = next[j-1] + 1;
        }
        next[i] = j;
    }

//    for(int i = 0; i <= tam; i++) {
//        printf("%d ", next[i]);
//    }
}

int kmp(char expressao[], int n ,char padrao[], int m, int next[]) {
    int i = 0, j =0, index = -1;
    while(index == -1 && i<=n) {
        if(expressao[i] == padrao[j]) {
            i = i + 1;
            j = j + 1;
        } else {
            j = next[j];
            if(j == -1) {
                j = 0;
                i = i + 1;
            }
        }
        if(j == m+1) {
            index = i-(m+1);
        }
    }

    return index;
}

int main() {
    char expressao[] = "xyxxyxyxyyxyxyxyyxyxyxx";
    char padrao[] = "xyxyyxyxyxy";
    int lenE = sizeof expressao/sizeof expressao[0] -2;
    int lenP = sizeof padrao/sizeof padrao[0] -2;
    int next[lenP];

    computaNext(padrao, lenP, next);
    int index = kmp(expressao, lenE, padrao, lenP, next);
    printf("%d ", index);
    return 0;
}
