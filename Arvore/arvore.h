#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int chave; 
    struct Nodo* dir; 
    struct Nodo* esq;
} Nodo; 

Nodo* criarNodo(int chave); 
Nodo *inserir(Nodo *raiz, int chave);
Nodo *buscar(Nodo* raiz, int chave); 