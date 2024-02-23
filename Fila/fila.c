#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void enqueue(Fila *fila, int valor)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->info = valor;
    aux->prox = NULL;
    if (fila->inicio == NULL)
        fila->inicio = aux;
    else
        fila->fim->prox = aux;
    
    fila->fim = aux;
}

int dequeue(Fila *fila)
{
    Nodo *aux = fila->inicio;
    int data = aux->info;
    fila->inicio = aux->prox;
    free(aux);
    return data;
}

void printarFila(Fila *fila)
{
    Nodo *aux = fila->inicio;
    while (aux)
    {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}