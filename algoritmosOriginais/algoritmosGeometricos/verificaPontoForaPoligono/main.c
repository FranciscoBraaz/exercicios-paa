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

bool pontoNoPoligono(Ponto P[], Ponto q, int n) {
    int maiorX = P[0].x, maiorY = P[0].y;
    for(int i = 1; i <= n; i++) {
        if(P[i].x > maiorX) maiorX = P[i].x;
        if(P[i].y > maiorY) maiorY = P[i].y;
    }
    Ponto s;
    s.x = maiorX + 10;
    s.y = maiorY + 10;

    int count = 0;
    for(int i = 0; i <= n-1; i++) {
        if(interseccaoSegmentos(q, s, P[i], P[i+1])){
            count++;
        }
    }

    if(count % 2 == 0) return false;
    else return true;

}

int main() {
    Ponto v1 = {7, 1};
    Ponto v2 = {5, 4};
    Ponto v3 = {6, 6};
    Ponto v4 = {4, 5};
    Ponto v5 = {2, 3};
    Ponto v6 = {3, 1};
    Ponto P[] = {v1, v2, v3, v4, v5, v6};
    int lenP = sizeof P/sizeof P[0] - 1;
    Ponto q = {4, 4};

    if(pontoNoPoligono(P, q, lenP)){
        printf("Faz parte");
    } else {
        printf("Nao faz parte");
    }
    return 0;
}
