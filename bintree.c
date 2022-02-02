//
// Created by vinicius on 29/01/2022.
//

#include "bintree.h"

Arv* cria_arv_vazia(void) {
    return NULL;
}

Arv* cria_arv(int v, Arv* sesq, Arv* sdir){
    Arv* a = (Arv*) malloc(sizeof(Arv));
    a->v = v;
    a->dir = sdir;
    a->esq = sesq;
    return a;
}


int arv_vazia(Arv* a) {
    return a == NULL;
}

void arv_libera(Arv* a) {
    if (!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
}

int arv_pertence(Arv* a, int c) {
    if (arv_vazia(a))
        return 0;
    else
        return a->v==c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
}


int arv_altura(Arv* a) {
    if (arv_vazia(a))
        return -1;
    else
        return 1 + max2(arv_altura(a->esq), arv_altura(a->dir));

}

int max2(int a, int b){
    return (a>b) ? a:b;
}

Arv* insere(Arv* a, int c)
{
    if (arv_vazia(a)){
        a = cria_arv(c, cria_arv_vazia(), cria_arv_vazia());
    } else if(a->v > c){
        a->esq = insere(a->esq, c);
    } else
        a->dir = insere(a->dir, c);
    return a;
}

Arv* busca(Arv* a, int c){
    if (arv_vazia(a))
        return NULL;
    else if (a->v > c) {
        busca(a->esq, c);
    } else if (a->v < c) {
        busca(a->dir, c);
    } else
        return a;
}

Arv* arv_remove(Arv* a, int c) {
    if(arv_vazia(a))
        return a;
    if(a->v > c){
        arv_remove(a->esq, c);
    } else if (a->v < c) {
        arv_remove(a->dir, c);
    } else { /*encontrou o c na árvore*/
        if (arv_vazia(a->dir) && arv_vazia(a->esq)) { /* é um nó folha */
            arv_libera(a);
            a = cria_arv_vazia();
        } else if (arv_vazia(a->esq)) { /* só tem filho a direita */
            Arv* n = a;
            a = a->dir;
            free(n);
        } else if (arv_vazia(a->dir)) { /* só tem filho a esquerda */
            Arv* n = a;
            a = a->esq;
            free(n);
        } else { /* tem filho em ambos os lados */
            /* busca o maior menor filho */
            Arv* n = a->esq;
            while (!arv_vazia(n->dir)){
                n = n->dir;
            }
            a->v = n->v;
            n->v = c;
            a->esq = arv_remove(a, c);
        }
    }
    return a;
}