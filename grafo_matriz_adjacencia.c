//
// Created by vinicius on 27/01/2022.
//

#include "grafo_matriz_adjacencia.h"

/* como se trata de um grafo não diretivo, podemos utilizar apenas metade inferior da matriz*/

Grafo* grafo_cria(int size)
{
    Grafo * g = (Grafo*) malloc(sizeof(Grafo));
    g->n = size;
    g->lista = (int**) malloc(g->n * sizeof(int*));
    for (int i = 0; i < g->n; i++){
        g->lista[i] = (int*) malloc((i+1) * sizeof(int)); /*aloca apenas a parte inferior da diagonal principal*/
        for (int j = 0; j < (i+1); j++){
            g->lista[i][j] = 0;
        }
    }
    return g;
}

void grafo_insere(Grafo* g, int v1, int v2, int w)
{
    if(v1 > v2)
        g->lista[v1][v2] = w;
    else
        g->lista[v2][v1] = w;
}

int retorna_peso(Grafo* g, int v1, int v2) {
    if(v1 > v2)
        return g->lista[v1][v2];
    else
        return g->lista[v2][v1];
}

void grafo_remove(Grafo* g, int v1, int v2)
{
    if (v1 > v2)
        g->lista[v1][v2] = 0;
    else
        g->lista[v2][v1] = 0;
}

int grafo_existe_aresta(Grafo* g, int v1, int v2)
{
    if (v1 > v2)
        return (g->lista[v1][v2] != 0);
    else
        return (g->lista[v2][v1] != 0);
}

void grafo_libera(Grafo* g)
{
    for(int i = 0; i < g->n; i++){
        free(g->lista[i]);
    }
    free(g->lista);
    free(g);
}

/*imprime o grafo*/
void grafo_imprime(Grafo* g)
{
    for (int i=0; i < g-> n; i++) {
        if (i==0)
            printf("   %c  ", (i+97));
        else if (i == g->n-1)
            printf("%c\n", (i+97));
        else
            printf("%c  ", (i+97));

    }

    for(int i= 0; i < g->n; i++){
        printf("%c ", (i+97));
        for (int j=0; j < g->n; j++){
            if (i > j)
                printf(" %d ", g->lista[i][j]);
            else
                printf(" %d ", g->lista[j][i]);
        }
        printf("\n");
    }
}

Vertices* cria_lista(int size) {
    Vertices* v = (Vertices*) malloc(sizeof(Vertices));
    v->l = (Vertice**) malloc(size*sizeof(Vertice));
    for (int i = 0; i < size; i++)
        v->l[i] = NULL;
    v->n = 0;
    return v;
}

int lista_vazia(Vertices* v) {
    return (v->n == 0);
}

Vertices* insere_vertice(Vertices* v, int n, int pai, int chave) {
    Vertice* novo = (Vertice *) malloc(sizeof(Vertice));
    novo->n = n;
    novo->pai = pai;
    novo->chave = chave;
    v->l[v->n] = novo;
    v->n++;
    return v;
}

Vertices* remove_vertice(Vertices* v) {
    if (v->n != 0){
        Vertice* menor = v->l[0];
        for (int i = 0; i < v->n; i++) {
            v->l[i] = v->l[i+1];
        }
        v->n--;
        free(menor);
    }
    return v;
}

int menor_vertice(Vertices* v) {
    return v->l[0]->n;
}

Vertice* busca_vertice(Vertices* v, int n) {
    if(v->n != 0) {
        for (int i = 0; i < v->n; i++)
            if (v->l[i]->n == n)
                return v->l[i];
    }

    return NULL;
}

Vertices* atualiza_vertice(Vertices* v, int n, int pai, int chave) {
    Vertice* u = busca_vertice(v, n);
    u->chave = chave;
    u->pai = pai;
    return v;
}

Vertices* ordena_lista(Vertices* v) {
    for(int i = v->n-1; i >=1; i--) {
        for(int j = 0; j<i; j++) {
            if(v->l[j]->chave > v->l[j+1]->chave) {
                Vertice* aux = v->l[j];
                v->l[j] = v->l[j+1];
                v->l[j+1] = aux;
            }
        }
    }

    return v;
}

void imprime_lista(Vertices* v) {
    for (int i=0; i<v->n; i++) {
        if(v->l[i]->pai == -1)
            printf("No: %c \t Pai: Nulo \t Chave: %d \n", (v->l[i]->n+97), v->l[i]->chave);
        else
            printf("No: %c \t Pai: %c \t Chave: %d \n", (v->l[i]->n+97), (v->l[i]->pai+97), v->l[i]->chave);
    }
}

void libera_lista(Vertices* v){
    for (int i = 0; i < v->n; i++) {
        free(v->l[i]);
    }
    free(v);
}

Vertices* prim(Grafo* g) {
    Vertices* A = cria_lista(g->n);
    Vertices* Q = cria_lista(g->n);
    for (int i=0; i<g->n; i++){
        A = insere_vertice(A, i, -1, 100);
        Q = insere_vertice(Q, i, -1, 100);
    }
    Q = atualiza_vertice(Q, 0, -1, 0);
    A = atualiza_vertice(A, 0, -1, 0);
    Q = ordena_lista(Q);
    printf("Lista Q apos inicializacao\n");
    imprime_lista(Q);
    while (!lista_vazia(Q)){
        int n = menor_vertice(Q);
        printf("Vertice %d selecionado como menor vertice\n", n);
        Q = remove_vertice(Q);
        for(int i = 0; i < g->n; i++){
            if(grafo_existe_aresta(g, n, i)){
                int w = retorna_peso(g, n, i);
                Vertice* u = busca_vertice(Q, i);
                if (u != NULL && w < u->chave){
                    A = atualiza_vertice(A, i, n, w);
                    Q = atualiza_vertice(Q, i, n, w);
                    Q = ordena_lista(Q);
                    printf("Após iteracao que verificou a aresta (%d, %d) \n", i,n);
                    imprime_lista(Q);
                }
            }
        }
    }
    libera_lista(Q);
    return A;
}