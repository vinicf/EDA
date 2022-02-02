//
// Created by vinicius on 27/01/2022.
//

#ifndef EDA_TREE_H
#define EDA_TREE_H

#endif //EDA_TREE_H
#include <stdio.h>
#include <stdlib.h>

struct arv{
    int v;
    struct arv* f;
    struct arv* prox;
};

typedef struct arv Arvore;

Arvore* cria_arv(int v);
Arvore* insere_no(Arvore* a, Arvore* b);
Arvore* busca_no(Arvore* a, int v);
void libera(Arvore* a);
int altura(Arvore* a);