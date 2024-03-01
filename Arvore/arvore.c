#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Nodo* criarNodo(int chave)
{
    Nodo* novoNodo = (Nodo *)malloc(sizeof(Nodo));
    novoNodo->chave = chave; 
    novoNodo->dir = NULL;
    novoNodo->esq = NULL; 
    return novoNodo; 
}

Nodo *inserir(Nodo *raiz, int chave)
{
    if(raiz == NULL)
        return criarNodo(chave);
    if(chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else if(chave > raiz->chave)
        raiz->dir = inserir(raiz->dir, chave);
    
    return raiz; 
}

Nodo *buscar(Nodo* raiz, int chave)
{
    if(raiz->chave == chave || raiz == NULL)
        return raiz; 
    if(chave < raiz->chave)
        return buscar(raiz->esq, chave);

    return buscar(raiz->dir, chave);
}   

void printarArvore(Nodo *raiz)
{
    Nodo* aux = raiz;
    if(raiz == NULL)
        printf(("Arvore vazia"));
    while(aux)
    {
        printf("%d\n", aux->chave);
        aux = aux->dir;
    }
}