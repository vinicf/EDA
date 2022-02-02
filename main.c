#include <stdio.h>
#include <stdlib.h>
#include "grafo_matriz_adjacencia.h"
#define N = 10; /*número de vértices do grafo ou |V|*/

int main() {
    Grafo* g = grafo_cria(5);
    grafo_insere(g, 0, 1, 3);
    grafo_insere(g, 0, 4, 2);
    grafo_insere(g, 1, 4, 1);
    grafo_insere(g, 1, 2, 1);
    grafo_insere(g, 2, 3, 4);
    grafo_insere(g, 2, 4, 3);
    grafo_insere(g, 3, 4, 2);
    grafo_imprime(g);

    Vertices* A = prim(g);
    printf("Resultado final do prim: \n");
    imprime_lista(A);
    grafo_libera(g);
    return 0;
}
