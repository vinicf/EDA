//
// Created by vinicius on 27/01/2022.
//

#include "tree.h"
Arvore* cria_arv(int v)
{
    Arvore* a = (Arvore*) malloc(sizeof(Arvore));
    a->v = v;
    a->f = NULL;
    a->prox = NULL;
    return a;
}

Arvore* insere_no(Arvore* a, Arvore* b) /* insere subárvore b como filho de a */
{
    b->f = a->f;
    a->f = b;
}



Arvore* busca_no(Arvore* a, int v)
{
    if(a == NULL){
        return NULL;
    }
    if(a->v==v)
        return a;
    Arvore* f = a->f;
    while(f!=NULL){
        Arvore* r = busca_no(f, v);
        if (r->v == v)
            return r;
        f = f->prox;
    }
    return NULL;
}

void libera(Arvore* a){
    Arvore* f = a->f;
    while(f!=NULL){
        Arvore* p = f->prox;
        libera(f);
        f = p;
    }
    free(a);
}

int altura(Arvore* a)
{
    int h0 = -1;
    Arvore* f = a->f;
    while (f!=NULL){
        int h = altura(f);
        if (h>h0)
            h0 = h;
        f = f->prox;
    }
    return h0 + 1;
}
