#include "circList.h"
#include <stdio.h>
#include <stdlib.h> // Para malloc

Lista *criaLista() { return NULL; }

Lista *insereLista(Lista *prim, Lista **ult, int valor) {
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL) {
    printf("Erro ao alocar memoria");
    exit(1);
  }
  novo->info = valor;

  if (prim == NULL) {
    novo->prox = novo;
    *ult = novo; 
    return novo;
  } else {
    novo->prox = prim;
    (*ult)->prox = novo;
    return novo;
  }
}

Lista *insereFim(Lista *prim, Lista *ult, int valor) {
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL) {
    printf("Erro ao alocar memoria\n");
    exit(1);
  }
  novo->info = valor;
  novo->prox = NULL;

  novo->prox = ult->prox;
  ult->prox = novo;
  return ult;
}

void imprimeLista(Lista *prim) {
  if (prim == NULL) {
    printf("Lista vazia");
    return;
  }
  Lista *aux = prim;
  
  do {
    printf("Valor: %d\n", aux->info);
    aux = aux->prox;
  } while (aux != prim);
  printf("\n");
}
