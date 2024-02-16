#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

Lista *criaLista()
{
    return NULL;
}

void *insereInicio(Lista **lista, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    if (novo == NULL)
        printf("Erro ao alocar memoria");

    novo->info = valor;
    novo->anterior = NULL;
    novo->prox = *lista;

    if (*lista != NULL)
        (*lista)->anterior = novo;

    *lista = novo;
}

void imprimeLista(Lista *lista)
{
    Lista *aux = (Lista *)malloc(sizeof(Lista));
    if (lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    aux = lista;
    while (aux != NULL)
    {
        printf("Valor: %d\n", aux->info);
        aux = aux->prox;
    }
}

void insereFim(Lista **lista, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    novo->info = valor;
    novo->prox = NULL; // O novo nó será o último, então o próximo é NULL

    if (*lista == NULL) {
        // Se a lista estiver vazia, o novo nó será o primeiro e o último
        *lista = novo;
    } else {
        // Encontra o último nó da lista
        Lista *temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        // Insere o novo nó após o último nó
        temp->prox = novo;
    }
}
