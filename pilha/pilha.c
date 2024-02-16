#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// função para criar uma pilha vazia
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL) {
        fprintf(stderr, "Erro na alocação de memória para a pilha\n");
        exit(EXIT_FAILURE);
    }
    pilha->topo = NULL;
    return pilha;
}

// função para destruir a pilha e liberar memória
void destruirPilha(Pilha* pilha) {
    while (pilha->topo != NULL) {
        Nodo* temp = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(temp);
    }
    free(pilha);
}

// função para inserir um elemento no topo da pilha (push)
void push(Pilha* pilha, int valor) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

// função para remover e retornar o elemento do topo da pilha (pop)
int pop(Pilha* pilha) {
    if (pilha->topo == NULL) {
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo* temp = pilha->topo;
    int valor = temp->info;
    pilha->topo = temp->prox;
    free(temp);
    return valor;
}

// função para verificar se a pilha está vazia
int estaVazio(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void check(char par[])
{
    int i = 0;
    int cond = 1;
    Pilha* pilha = criarPilha(); //(Pilha *)malloc(sizeof(Pilha));
    while(par[i] != '\0'){
    if(par[i] == '('){
        push(pilha, 1);
    }
    else if(par[i] == ')'){
        if(estaVazio(pilha)){
            printf("Nao aceita\n ");
            cond = 0;
        }
        else
            pop(pilha);
    }
    i++;
    }
    if(estaVazio(pilha)){
    if(cond)
        printf("Pilha aceita\n");
    }
    else
    printf("Nao aceita\n ");
    destruirPilha(pilha);
}

int saoIguais(Pilha* p1, Pilha* p2)
{
    Nodo* aux1 = p1->topo;
    Nodo* aux2 = p2->topo;
    if(estaVazio(p1) && estaVazio(p2))
        printf("Ambas as pilhas estao vazias\n");
    while(aux1 != NULL && aux2 != NULL){
        if(aux1->info != aux2->info )
            return 0;
            aux1 = aux1->prox;
            aux2 = aux2->prox;
            //pop(aux1);
            //pop(aux2);
    }   
    return 1;
}