//
// Created by vinicius on 27/01/2022.
//

#ifndef EDA_GRAFO_MATRIZ_ADJACENCIA_H
#define EDA_GRAFO_MATRIZ_ADJACENCIA_H

#endif //EDA_GRAFO_MATRIZ_ADJACENCIA_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct grafo {
    int n;
    int** lista;
};
typedef struct grafo Grafo;

struct vertice {
    int n;
    int pai;
    int chave;
};
typedef struct vertice Vertice;

struct lista_vertices {
    int n;
    Vertice** l;
};
typedef struct lista_vertices Vertices;

Grafo* grafo_cria(int size);
void grafo_insere(Grafo* g, int v1, int v2, int w);
void grafo_remove(Grafo* g, int v1, int v2);
int grafo_existe_aresta(Grafo* g, int v1, int v2);
void grafo_libera(Grafo* g);
void grafo_imprime(Grafo* g);
int retorna_peso(Grafo* g, int v1, int v2);


Vertices* cria_lista(int size);
int lista_vazia(Vertices* v);
Vertices* insere_vertice(Vertices* v, int n, int pai, int chave);
Vertices* remove_vertice(Vertices* v);
int menor_vertice(Vertices* v);
Vertices* ordena_lista(Vertices* l);
Vertices* atualiza_vertice(Vertices* v, int n, int pai, int chave);
Vertice* busca_vertice(Vertices* v, int n);
void imprime_lista(Vertices* v);
void libera_lista(Vertices* v);

Vertices* prim(Grafo* g);