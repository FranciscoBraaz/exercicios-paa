#include <stdio.h>

struct ponto{
    int x;
    int y;
};
typedef struct ponto Ponto;

int sentidoSegmento(Ponto p, Ponto q, Ponto r) {
    int prodVetorial = ((q.x - p.x) * (r.y - p.y)) - ((r.x-p.x) * (q.y - p.y));
    if(prodVetorial == 0) return 0;
    else if(prodVetorial > 0) return 1;
    else return -1;
}

int main() {
    Ponto p;
    Ponto q;
    Ponto r;
    p.x = 1;
    p.y = 1;
    q.x = 4;
    q.y = 4;
    r.x = 3;
    r.y = 2;

    int resp = sentidoSegmento(p, q, r);
    printf("%d", resp);
    return 0;
}
