#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// função para criar uma fila vazia
Fila *criarFila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória para a fila\n");
        exit(EXIT_FAILURE);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// função para destruir a fila e liberar memória
void destruirFila(Fila *fila)
{
    while (fila->inicio != NULL)
    {
        Nodo *temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
    }
    free(fila);
}

// função para inserir um elemento no final da fila
void enqueue(Fila *fila, int valor)
{
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = NULL;
    if (fila->inicio == NULL)
    { // fila vazia
        fila->inicio = novo;
    }
    else
    { // fila não vazia
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

// função para remover e retornar o elemento da frente (início) da fila
int dequeue(Fila *fila)
{
    if (fila->inicio == NULL)
    {
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo *temp = fila->inicio;
    int data = temp->info;
    fila->inicio = temp->prox;
    free(temp);
    return data;
}

// função para verificar se a fila está vazia
int estaVazio(Fila *fila)
{
    return (fila->inicio == NULL);
}

int maiorFila(Fila *f1, Fila *f2)
{
    int contador1 = 0;
    int contador2 = 0;
    Nodo *fila1 = (Nodo *)malloc(sizeof(Nodo));
    Nodo *fila2 = (Nodo *)malloc(sizeof(Nodo));
    fila1 = f1->inicio;
    fila2 = f2->inicio;
    while (fila1)
    {
        contador1++;
        fila1 = fila1->prox;
    }
    while (fila2)
    {
        contador2++;
        fila2 = fila2->prox;
    }
    if (contador1 < contador2)
        return -1;
    else if (contador1 > contador2)
        return 1;
    return 0;
}

/*Dada uma fila de inteiros, escreva um programa que exclua todos os números
negativos da fila sem alterar a posição dos outros elementos da fila. */

void excluirNeg(Fila **fila)
{
    Nodo *aux = (*fila)->inicio;
    Nodo *prev = NULL;

    while (aux != NULL)
    {
        if (aux->info <= 0)
        {
            Nodo *temp = aux;
            if (prev == NULL)
            { // se for o prim
                (*fila)->inicio = aux->prox;
            }
            else
            {
                prev->prox = aux->prox;
            }
            aux = aux->prox;
            free(temp); 
        }
        else
        {
            prev = aux;
            aux = aux->prox;
        }
    }
}

void printarFila(Fila *f1)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux = f1->inicio;
    while (aux)
    {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

/* Faça uma função para retornar o número de elementos da fila que possuem valor
par. */

int quantidadePar(Fila *fila)
{
    Nodo *aux = fila->inicio;
    int quantidade = 0;
    while (aux)
    {
        if (aux->info % 2 == 0)
            quantidade++;
        aux = aux->prox;
    }
    return quantidade;
}

/* Escreva uma função que, dado duas filas F1 e F2, concatene as duas filas. Retorne
a fila concatenada em F1. A fila F2 deve ficar vazia. */

void concatenarFila(Fila *f1, Fila *f2)
{
    while (f2->inicio)
        enqueue(f1, dequeue(f2));
}

void concatenarFilaComplexo(Fila *f1, Fila *f2)
{
    Fila *aux = f1;
    Nodo *fila1;
    Nodo *fila2;
    for (fila1 = f1->inicio, fila2 = f2->inicio; fila1 != NULL, fila2 != NULL; fila1 = fila1->prox, fila2 = fila2->prox)
    {
        enqueue(f1, fila1->info);
        enqueue(f1, fila2->info);
    }
    /*
    while (aux->inicio)
    {
        enqueue(f1, dequeue(aux));
        if (aux2->inicio)
            enqueue(f1, dequeue(aux2));
    } */
    // printarFila(f1);
}
// 1 -4 6 8

// até o fim e reseto a fila

/* Implemente a função reverso, a qual reposiciona os elementos na fila de tal forma
que o início da fila torna-se o fim, e vice-versa */
void inverterFila(Fila *fila)
{
    Nodo *anterior = NULL, *atual = fila->inicio, *proximo;
    fila->fim = fila->inicio; // fim da fila
    while (atual != NULL)
    {
        proximo = atual->prox;  // proximo no (apos o atual)
        atual->prox = anterior; // o proximo recebe o anterior
        anterior = atual;       // o anterior vira o atual pra armazenar pro proximo loop
        atual = proximo;        // percorre pro prox
    }
    fila->inicio = anterior; // o inicio volta um
    // printarFila(fila);
}

int tamanhoFila(Fila *fila)
{
    int contador;
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux = fila->inicio;
    while (aux)
    {
        aux = aux->prox;
        contador++;
    }
    return contador;
}
// o primeiro elemento eh sempre o ultimo
// o ultimo eh o primeiro
