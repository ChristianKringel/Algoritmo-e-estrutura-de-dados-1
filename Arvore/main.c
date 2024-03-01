#include <stdio.h>
#include "arvore.h"

int main()
{
    Nodo* raiz = NULL; 
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 35);
    raiz = buscar(raiz, 25);
    
}