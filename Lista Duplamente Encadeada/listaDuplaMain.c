#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

int main()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista = criaLista();
    insereInicio(&lista, 10);
    insereInicio(&lista, 10);
    insereFim(&lista, 2);
    insereInicio(&lista, 5); 
    insereInicio(&lista, 50);
    insereInicio(&lista, 20);
    insereFim(&lista, 8);
    insereInicio(&lista, 500);
    inserirMeio(&lista, 1010);
    imprimeLista(lista);
    removeDuplicado(lista);
    //printf("Removido o valor: %d, da posicao %d\n", removeIndice(lista, 1), 1);
    /*
    printf("O tamanho da lista eh: %d\n", tamanhoLista(lista));
    printf("\n");
    busca(lista, 2);
    printf("\n");
    */ 
    imprimeLista(lista);
    return 0;
}