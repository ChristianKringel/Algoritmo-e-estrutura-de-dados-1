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

// func pra inserir no fim
// precisa ser ** pra alterar diretamente o ultimo
void insereFim(Lista *prim, Lista **ult, int valor)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL)
  {
    printf("Erro ao alocar memoria\n");
    exit(1);
  }

  novo->info = valor;

  if (*ult == NULL)
  {
    // lista vazia, logo, ele eh o prim no
    *ult = novo;
    novo->prox = novo; // o prox dele, eh ele mesmo
  }
  else
  {
    // n esta vazia
    novo->prox = (*ult)->prox; // o prox do novo eh o prim no
    (*ult)->prox = novo;       // o prox do ult passa a ser o novo
    *ult = novo;               // novo no eh o ult
  }
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

// remove a prim ocorrencia do valor
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
    if (aux2 == NULL)
      prim = aux->prox;
    else
      aux2->prox = aux->prox;
  }
  free(aux);
  return prim;
}

/* Implemente uma função que inverta uma lista encadeada circular. */
void inverterLista(Lista *prim, Lista *ult)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  Lista *aux1, *aux2;
}

/* 6. Desenvolva uma função que conte quantos nodos existem em uma lista circular. */

int tamanhoLista(Lista *prim, Lista *ult)
{
  int contador = 0;
  Lista *aux = prim;
  if (prim == NULL)
    return 0;
  while (aux->prox != prim)
  {
    contador++;
    aux = aux->prox;
  }
  contador++;
  return contador;
}

/* Implemente uma função que imprime o 𝑛-ésimo elemento de uma lista circular */
// Levando em conta que comeca pelo indice 0

void achaPeloIndice(Lista *prim, int indice)
{
  Lista *aux = prim;
  for (int i = 0; i < indice && aux->prox != prim; i++, aux = aux->prox)
    ;
  printf("O elemento no indice %d eh: %d\n", indice, aux->info);
}

/* Escreva uma função que, dada duas listas encadeadas circulares L1 e L2, realize
a concatenação das duas listas em uma nova lista encadeada circular. */

Lista *concatenarListas(Lista *ini1, Lista *ini2)
{
  if (ini1 == NULL) {
        return ini2;
    }
    if (ini2 == NULL) {
        return ini1;
    }

    Lista *fim1 = ini1->prox;
    Lista *fim2 = ini2->prox;

    fim1->prox = ini2;
    fim2->prox = ini1;

    return ini1;
  /*
  Lista *aux1 = ini1, *aux2 = ini2;
  Lista *novaIni = NULL, *novaFim = NULL;

  // Concatenar elementos da primeira lista
  do
  {
    insereFim(novaIni, &novaFim, aux1->info);
    aux1 = aux1->prox;
  } while (aux1 != ini1);

  // Concatenar elementos da segunda lista
  do
  {
    insereFim(novaIni, &novaFim, aux2->info);
    aux2 = aux2->prox;
  } while (aux2 != ini2);

  return novaIni;
  */
}
