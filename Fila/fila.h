#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info; 
    struct Nodo* prox;
} Nodo; 

typedef struct{
    Nodo* inicio; 
    Nodo* fim;
} Fila; 

void enqueue(Fila *fila, int valor);
int dequeue(Fila *fila);
void printarFila(Fila *fila);

