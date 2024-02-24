#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// função para criar uma fila vazia
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL) {
        fprintf(stderr, "Erro na alocação de memória para a fila\n");
        exit(EXIT_FAILURE);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// função para destruir a fila e liberar memória
void destruirFila(Fila* fila) {
    while (fila->inicio != NULL) {
        Nodo* temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
    }
    free(fila);
}

// função para inserir um elemento no final da fila
void enqueue(Fila* fila, int valor) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = NULL;
    if (fila->inicio == NULL) {  // fila vazia
        fila->inicio = novo;
    } else {  // fila não vazia
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

// função para remover e retornar o elemento da frente (início) da fila
int dequeue(Fila* fila) {
    if (fila->inicio == NULL) {
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo* temp = fila->inicio;
    int data = temp->info;
    fila->inicio = temp->prox;
    free(temp);
    return data;
}

// função para verificar se a fila está vazia
int estaVazio(Fila* fila) {
    return (fila->inicio == NULL);
}

int maiorFila(Fila *f1, Fila* f2)
{
    int contador1 = 0; 
    int contador2 = 0; 
    Nodo* fila1 = (Nodo *)malloc(sizeof(Nodo));
    Nodo* fila2 = (Nodo *)malloc(sizeof(Nodo));
    fila1 = f1->inicio;
    fila2 = f2->inicio;
    while(fila1)
    {
        contador1++; 
        fila1 = fila1->prox;
    }
    while(fila2)
    {
        contador2++;
        fila2 = fila2->prox;
    }
    if(contador1 < contador2)
        return -1;
    else if(contador1 > contador2)
        return 1;
    return 0;
}

/*Dada uma fila de inteiros, escreva um programa que exclua todos os números
negativos da fila sem alterar a posição dos outros elementos da fila. */ 

void excluirNeg(Fila* fila)
{
    Nodo* aux = (Nodo *)malloc(sizeof(Nodo));
    Fila* aux2 = (Fila *)malloc(sizeof(Fila));
    int temp; 
    aux = fila->inicio;
    while(aux)
    {
        if(aux->info > 0){
            printf("%d\n", aux->info);
            enqueue(aux2, aux->info);
            }
        aux = aux->prox;
    }
    printf("\n");
    printarFila(fila);
    printf("\n");
    printarFila(aux2);
    printf("\n");
    fila = aux2;
    //printarFila(fila);
    //return aux2;
}

void printarFila(Fila* f1)
{
    Nodo* aux = (Nodo *)malloc(sizeof(Nodo));
    aux = f1->inicio;
    while(aux)
    {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

/* Faça uma função para retornar o número de elementos da fila que possuem valor
par. */

int quantidadePar(Fila *fila)
{
    Nodo* aux = fila->inicio;
    int quantidade = 0; 
    while(aux)
    {
        if(aux->info % 2 == 0)
            quantidade++;
        aux = aux->prox;
    }
    return quantidade;
}

// Faça uma função que inverta a ordem dos elementos da fila.

void inverter(Fila **fila)
{
    Fila *aux = (Fila *)malloc(sizeof(Fila));
    while(*fila)
    enqueue(aux, dequeue(*fila));
    *fila = aux;
}


/* Escreva uma função que, dado duas filas F1 e F2, concatene as duas filas. Retorne
a fila concatenada em F1. A fila F2 deve ficar vazia. */


void concatenarFila(Fila* f1, Fila* f2)
{
    while(f2->inicio)
        enqueue(f1, dequeue(f2));
}


void concatenarFilaComplexo(Fila* f1, Fila* f2)
{
    Fila *aux = criarFila();
    while(f1->inicio || f2->inicio)
    {
        enqueue(aux, dequeue(f1));
        enqueue(aux, dequeue(f2));
    }
    printarFila(aux);
    f1 = aux;
    printf("--------------\n");
    printarFila(f1);
    
}
// 1 -4 6 8

//até o fim e reseto a fila

/* Implemente a função reverso, a qual reposiciona os elementos na fila de tal forma
que o início da fila torna-se o fim, e vice-versa */

void reverso(Fila *fila)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    int dado;
    Fila* filaAux = criarFila();
    filaAux = fila;
    Fila* final = criarFila();
    while(filaAux->inicio){
        aux->info = filaAux->fim;
        enqueue(final, aux->info);
    }
    printarFila(final);
}
