//
// Created by vinicius on 27/01/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista_adjacencia.h"


/*cria grafo*/

Grafo* grafo_cria(int size)
{
    Grafo* g = (Grafo *) malloc(sizeof(Grafo));
    Node** l = (Node**) malloc(size*sizeof(Node*));
    g->lista = l;
    for (int i = 0; i < size; i++){
        g->lista[i] = NULL;
    }
    g->n = size;
    return g;
}


/*insere uma aresta no grafo*/
void grafo_insere(Grafo* g, int v1, int v2)
{
    Node* n = g->lista[v1];
    while(n!=NULL){
        if (n->v == v2)
            return;
        n = n->prox;
    }

    Node* n1 = (Node *) malloc(sizeof(Node));
    n1->v = v2;
    n1->prox = g->lista[v1];
    g->lista[v1] = n1;

    Node* n2 = (Node *) malloc(sizeof(Node));
    n2->v = v1;
    n2->prox = g->lista[v2];
    g->lista[v2] = n2;
}

int grafo_existe_aresta(Grafo* g, int v1, int v2)
{
    Node* n = g->lista[v1];
    while(n!=NULL){
        if(n->v == v2)
            return 1;
        n->prox;
    }
    return 0;
}

Node* lista_remove(Node* l, int v)
{
    Node* atual = l;
    Node* ant = NULL;

    while(atual!=NULL && atual->v != v){
        ant = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("No %d nao encontrado na lista.\n", v);
        return l;
    }

    if(ant == NULL){
        l = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    return l;
}

/* remove uma aresta do grafo */
void grafo_remove(Grafo* g, int v1, int v2)
{
    Node* n1 = g->lista[v1];
    n1 = lista_remove(n1, v2);
    g->lista[v1] = n1;

    Node* n2 = g->lista[v2];
    n2 = lista_remove(n2, v1);
    g->lista[v2] = n2;
}


/*imprime o grafo*/
void grafo_imprime(Grafo* g){
    for(int i= 0; i < g->n; i++){
        Node* n = g->lista[i];
        printf("%d - ", i);
        while(n != NULL){
            printf(" %d ", n->v);
            n = n->prox;
        }
        printf("\n");
    }
}

void grafo_libera(Grafo* g)
{
    for (int i=0; i < g->n; i++){
        Node* n = g->lista[i];
        while (n!=NULL){
            Node* prox = n->prox;
            free(n);
            n = prox;
        }
    }
    free(g->lista);
    free(g);
}
