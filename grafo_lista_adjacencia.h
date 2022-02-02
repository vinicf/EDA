//
// Created by vinicius on 27/01/2022.
//

#ifndef EDA_GRAFO_LISTA_ADJACENCIA_H
#define EDA_GRAFO_LISTA_ADJACENCIA_H

#endif //EDA_GRAFO_LISTA_ADJACENCIA_H

struct node {
    int v;
    struct node* prox;
};

typedef struct node Node;

struct grafo
{
    int n;
    Node** lista;
};

typedef struct grafo Grafo;



Grafo* grafo_cria(int size);
void grafo_insere(Grafo* g, int v1, int v2);
int grafo_existe_aresta(Grafo* g, int v1, int v2);
Node* lista_remove(Node* l, int v);
void grafo_remove(Grafo* g, int v1, int v2);
void grafo_imprime(Grafo* g);
void grafo_libera(Grafo* g);