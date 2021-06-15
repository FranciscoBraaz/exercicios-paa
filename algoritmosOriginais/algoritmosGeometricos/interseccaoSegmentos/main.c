#include <stdio.h>
#include <stdbool.h>

struct ponto{
    int x;
    int y;
};
typedef struct ponto Ponto;


int max(int x, int y) {
    if(x > y) return x;

    return y;
}

int min(int x, int y) {
    if(x < y) return x;

    return y;
}

int direcao(Ponto v, Ponto w, Ponto z) {
    int prodVetorial = ((z.x - v.x) * (w.y - v.y)) - ((w.x-v.x) * (z.y - v.y));
    if(prodVetorial == 0) return 0;
    else if(prodVetorial > 0) return 1;
    else return -1;
}

bool noSegmento(Ponto v, Ponto w, Ponto z) {
    int menorx = min(v.x, w.x), menory = min(v.y, w.y);
    int maiorx = max(v.x, w.x), maiory = max(v.y, w.y);
    if((menorx <= z.x) && (z.x <= maiorx) && (menory <= z.y) && (z.y <= maiory)){
        return true;
    } else {
        return  false;
    }
}

bool interseccaoSegmentos(Ponto p, Ponto q, Ponto r, Ponto s) {
    int dp = direcao(r, s, p);
    int dq = direcao(r, s, q);
    int dr = direcao(p, q, r);
    int ds = direcao(p, q, s);

    if(((dp > 0 && dq < 0) || (dp < 0 && dq > 0)) && ((dr > 0 && ds < 0) || (dr < 0 && ds> 0))){
        return true;
    } else {
        if( dp == 0 && noSegmento(r,s,p)) return true;
        else if(dq == 0 && noSegmento(r, s, q)) return true;
        else if(dr == 0 && noSegmento(p, q, r)) return true;
        else if(ds == 0 && noSegmento(p, q, s)) return  true;
    }

    return false;
}

int main() {
    Ponto p = {1, 1};
    Ponto q = {6, 6};
    Ponto r = {2, 2};
    Ponto s = {5, 5};

    if(interseccaoSegmentos(p, q, r, s)){
        printf("Existe interseccao");
    } else {
        printf("Nao existe interseccao");
    }
    return 0;
}
