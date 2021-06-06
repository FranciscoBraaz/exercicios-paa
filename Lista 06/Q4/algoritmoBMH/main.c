#include <stdio.h>
#define MAX 255

int bmh(char T[], int n, char P[], int m) {
    int i = m-1, index = -1;
    int D[MAX];
    for(int j = 0; j <= MAX; j++) {
        D[j] = m;
    }

    for(int j = 1; j < m; j++) {
        int x = P[j-1];
        D[x] = m-j;
    }

    while(i <= n-1 && index == -1) {
        int k = 0;
        while(k<=m-1 && P[m-1-k] == T[i-k]) {
            k = k +1;
        }
        if(k == m) {
            index = i-m+1;
        } else {
            char x = T[i];
            int y = (int) x;
            i = i + D[y];
        }
    }
    return index;
}

void buscaSufixo(char T[], int n, char P[], int m) {
    int index = -1;
    int i = m;
    for(i; i>0 && index == -1; i--){
        index = bmh(T, n, P, i);
    }
    if(index != -1) {
        printf("%d %d", index, index+i);
    } else {
        printf("%d ", -1);
    }

}

int main() {
    char T[] = "Nunca desista cultue a perseveranca";
    int n = sizeof T/sizeof T[0]-1;
    char P[] = "Nunca";
    int m = sizeof P/sizeof P[0]-1;
    buscaSufixo(T, n, P, m);
    return 0;
}
