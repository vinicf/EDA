//
// Created by vinicius on 29/01/2022.
//

#ifndef EDA_BINTREE_H
#define EDA_BINTREE_H

#endif //EDA_BINTREE_H
#include <stdio.h>
#include <stdlib.h>

struct bintree {
    int v;
    struct bintree* esq;
    struct bintree* dir;
};

typedef struct bintree Arv;

Arv* cria_arv_vazia(void);
Arv* cria_arv(int v, Arv* sesq, Arv* sdir);
int arv_vazia(Arv* a);
void arv_libera(Arv* a);
int arv_pertence(Arv* a, int c);
int arv_altura(Arv* a);
int max2(int a, int b);
Arv* insere(Arv* a, int c);
Arv* busca(Arv* a, int c);
Arv* arv_remove(Arv* a, int c);