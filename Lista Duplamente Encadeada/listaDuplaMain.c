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
    imprimeLista(lista);
    return 0;
}