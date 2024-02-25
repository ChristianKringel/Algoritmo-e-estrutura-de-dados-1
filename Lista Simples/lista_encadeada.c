#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// função para criar uma nova lista vazia
List *criarLista()
{
    return NULL;
}

// função para destruir a lista e liberar memória
void destruirLista(List *lista)
{
    List *atual = lista;
    List *proximo;

    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

// função para inserir um elemento no início da lista
List *inserirInicio(List *lista, int valor)
{
    List *novo = (List *)malloc(sizeof(List));

    if (novo == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }

    novo->info = valor;
    novo->prox = lista;

    return novo;
}

// função para remover um elemento da lista
List *removerElemento(List *lista, int valor)
{
    List *anterior = NULL;
    List *atual = lista;

    while (atual != NULL && atual->info != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        if (anterior == NULL)
        {
            // Remover o primeiro elemento
            lista = atual->prox;
        }
        else
        {
            // Remover elemento no meio ou final
            anterior->prox = atual->prox;
        }
        free(atual);
    }

    return lista;
}

// função para buscar um elemento na lista
List *buscarElemento(List *lista, int valor)
{
    List *atual = lista;

    while (atual != NULL && atual->info != valor)
    {
        atual = atual->prox;
    }

    return atual;
}

// função para imprimir os elementos da lista
void imprimirLista(List *lista)
{
    List *atual = lista;

    while (atual != NULL)
    {
        printf("%d ", atual->info);
        atual = atual->prox;
    }

    printf("\n");
}

int tamanhoLista(List *lista)
{
    List *aux = lista;
    int contador = 0;
    while (aux)
    {
        contador++;
        aux = aux->prox;
    }
    return contador;
}

void inserirFim(List **lista, int valor)
{
    List *novo, *aux = (List *)malloc(sizeof(List));
    if (aux)
    {
        novo = aux;
        novo->prox = NULL;
        novo->info = valor;

        if (*lista == NULL)
            *lista = novo;

        else
        {
            aux = *lista;
            while (aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria\n");
}

List *concatenar(List *lista1, List *lista2)
{
    List *novo = NULL, *aux1 = lista1, *aux2 = lista2; // Inicialize novo como NULL
    aux1 = lista1;
    aux2 = lista2;
    while (aux1 != NULL)
    {
        inserirFim(&novo, aux1->info);
        aux1 = aux1->prox;
    }

    while (aux2 != NULL)
    {
        inserirFim(&novo, aux2->info);
        aux2 = aux2->prox;
    }
    return novo;
}

List *removerPrimeiro(List *lista)
{
    if (!lista)
        printf("\nLista ja esta vazia\n");
    else
    {
        List *temp = lista;
        lista = lista->prox;
        free(temp);
    }
    return lista;
}

/* Implemente uma função para remover os 𝑛 primeiros elementos de uma lista
simples. */

List *removerElementos(List *lista, int quantidade)
{
    List *aux = lista;
    for (int i = 0; i < quantidade; i++)
        lista = removerPrimeiro(lista);
    return lista;
}