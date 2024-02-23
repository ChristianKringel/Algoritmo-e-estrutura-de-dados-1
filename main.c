#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {

    // exemplo de uso da fila
    Fila* fila = criarFila();
    Fila* fila2 = criarFila();

    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);
    enqueue(fila, 5);
    enqueue(fila2, -9);
    enqueue(fila2, 60);
    //printarFila(fila); 
    //concatenarFila(fila, fila2);
    //concatenarFilaComplexo(fila, fila2);
    printarFila(fila); 
    printf("\n");
    reverso(fila);
    //printarFila(fila); 


    /*
    //printf("Quantidade de nrs pares na fila: %d\n", quantidadePar(fila));
    //printarFila(fila);
    //printf("\n");

    //excluirNeg(fila);

    //inverter(&fila);
    //printf("\n");
    
    printf("%d\n", maiorFila(fila, fila));
    printf("Elemento removido da fila: %d\n", dequeue(fila));
    printf("Elemento removido da fila: %d\n", dequeue(fila));
    printf("Elemento removido da fila: %d\n", dequeue(fila));

    */
    if (estaVazio(fila))
    	printf("Fila vazia.\n");
    else 
    	printf("Fila não está vazia.\n");

    destruirFila(fila);

    return 0;
}