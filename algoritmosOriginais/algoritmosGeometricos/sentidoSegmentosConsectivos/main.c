#include <stdio.h>

struct ponto{
    int x;
    int y;
};
typedef struct ponto Ponto;

int sentidoSegmento(Ponto p, Ponto q, Ponto r) {
    int prodVetorial = ((r.x - p.x) * (q.y - p.y)) - ((q.x-p.x) * (r.y - p.y));
    if(prodVetorial == 0) return 0;
    else if(prodVetorial > 0) return 1;
    else return -1;
}

int main() {
    Ponto p = {0, 0};
    Ponto q = {1, 1};
    Ponto r = {2, 1};

    int resp = sentidoSegmento(p, q, r);
    printf("%d", resp);
    return 0;
}
