#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    enqueue(fila, 10);
    enqueue(fila, 8);
    enqueue(fila, 6);
    enqueue(fila, 4);
    printarFila(fila);
    printf("Elemento removido: %d\n", dequeue(fila));
}