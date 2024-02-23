#include "circList.h"
#include <stdio.h>
#include <stdlib.h>

Lista *criaLista() { return NULL; }

Lista *insereLista(Lista *prim, Lista **ult, int valor)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL)
  {
    fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
    exit(EXIT_FAILURE);
  }
  novo->info = valor;

  if (prim == NULL)
  {
    novo->prox = novo; // Lista estava vazia, faz apontar para si mesma
    *ult = novo;       // atualiza ponteiro ult
    return novo;       // retorna ponteiro prim atualizado
  }
  else
  {
    novo->prox = prim;
    (*ult)->prox = novo; // atualiza ponteiro prox do ult
    return novo;         // retorna ponteiro prim atualizado
  }
}

void *insereFim(Lista *prim, Lista *ult, int valor)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL)
  {
    printf("Erro ao alocar memoria\n");
    exit(1);
  }
  ult = novo;
  novo->info = valor;
  novo->prox = ult->prox;
  ult->prox = novo;
  // return ult;
}

void imprimeLista(Lista *prim)
{
  if (prim == NULL)
  {
    printf("Lista vazia");
    return;
  }
  Lista *aux = prim;

  do
  {
    printf("Valor: %d\n", aux->info);
    aux = aux->prox;
  } while (aux != prim);
  printf("\n");
}

Lista *remover(Lista *prim, int valor)
{
  Lista *aux = (Lista *)malloc(sizeof(Lista));
  Lista *aux2 = prim;
  if (prim == NULL)
    printf("Lista vazia");
  aux = prim;
  while (aux != NULL && aux->info != valor)
  {
    aux2 = aux;
    aux = aux->prox;
  }
  if (aux != NULL)
    {
      if(aux2 == NULL)
        prim = aux->prox;
      else
      aux2->prox = aux->prox;
    }
    free(aux);
    return prim;
}
