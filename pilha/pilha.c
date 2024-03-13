#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// função para criar uma pilha vazia
Pilha *criarPilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória para a pilha\n");
        exit(EXIT_FAILURE);
    }
    pilha->topo = NULL;
    return pilha;
}

// função para destruir a pilha e liberar memória
void destruirPilha(Pilha *pilha)
{
    while (pilha->topo != NULL)
    {
        Nodo *temp = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(temp);
    }
    free(pilha);
}

// função para inserir um elemento no topo da pilha (push)
void push(Pilha *pilha, int valor)
{
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória para novo elemento\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

// função para remover e retornar o elemento do topo da pilha (pop)
int pop(Pilha *pilha)
{
    if (pilha->topo == NULL)
    {
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo *temp = pilha->topo;
    int valor = temp->info;
    pilha->topo = temp->prox;
    free(temp);
    return valor;
}

// função para verificar se a pilha está vazia
int estaVazio(Pilha *pilha)
{
    return (pilha->topo == NULL);
}

// exercicio de testar parenteses
void check(char par[])
{
    int i = 0;
    int cond = 1;
    Pilha *pilha = criarPilha(); //(Pilha *)malloc(sizeof(Pilha));
    while (par[i] != '\0')
    {
        if (par[i] == '(')
        {
            push(pilha, 1);
        }
        else if (par[i] == ')')
        {
            if (estaVazio(pilha))
            {
                printf("Nao aceita\n ");
                cond = 0;
            }
            else
                pop(pilha);
        }
        i++;
    }
    if (estaVazio(pilha))
    {
        if (cond)
            printf("Pilha aceita\n");
    }
    else
        printf("Nao aceita\n ");
    destruirPilha(pilha);
}

// testa se duas pilhas são iguais 
int saoIguais(Pilha *p1, Pilha *p2)
{
    Nodo *aux1 = p1->topo;
    Nodo *aux2 = p2->topo;
    if (estaVazio(p1) && estaVazio(p2))
        printf("Ambas as pilhas estao vazias\n");
    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->info != aux2->info)
            return 0;
        aux1 = aux1->prox;
        aux2 = aux2->prox;
        // pop(aux1);
        // pop(aux2);
    }
    return 1;
}

// testa se uma pilha é palindroma (usando int)
int palindromo(Pilha *pilha)
{
    Pilha *aux2 = criarPilha();
    Nodo *aux = pilha->topo;

    // aux 2 é o contrario da pilha
    while (aux)
    {
        push(aux2, aux->info);
        aux = aux->prox;
    }

    aux = pilha->topo; // Resetando aux para o topo de pilha

    // Comparando os elementos de pilha e aux2
    while (aux)
    {
        if (aux->info != pop(aux2))
        {
            destruirPilha(aux2);
            return 0;
        }
        aux = aux->prox;
    }

    destruirPilha(aux2);
    return 1;
}

// tentativa de ordenar uma pilha, n funciona
void ordenar(Pilha *pilha)
{
    Nodo *aux2 = pilha->topo;
    Nodo *aux = pilha->topo;
    Pilha *reserva = criarPilha();
    int auxiliar;
    aux = aux->prox;
    while (aux2)
    {
        if (aux->info > aux2->info)
            aux->info = aux2->info;
        aux2 = aux2->prox;
        aux = aux->prox;
    }
    while (aux)
    {
        push(reserva, aux->info);
        aux = aux->prox;
    }
    pilha = reserva;
}

// printa a pilha
void printarPilha(Pilha *pilha)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux = pilha->topo;
    while (aux)
    {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

//pega a maior e a menor media dos valores na pilha
void menorMaiorMedia(Pilha *p1)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Pilha));
    aux = p1->topo;
    Nodo *aux2 = (Nodo *)malloc(sizeof(Pilha));
    aux2 = p1->topo;
    int media = 0;
    int menor = aux->info;
    int maior = aux->info;
    ;
    int contador = 0;
    while (aux->prox != NULL)
    {
        if (aux->info >= maior)
            maior = aux->info;
        if (aux->info <= menor)
            menor = aux->info;
        media = media + aux->info;
        aux = aux->prox;
        contador++;
    }
    printf("O menor elemento eh: %d\n", menor);
    printf("O maior elemento eh: %d\n", maior);
    printf("A media dos elementos eh: %d\n", (media / contador));
}

// pega o info do topo 
int peek(Pilha *pilha)
{
    if (estaVazio(pilha))
    {
        printf("Pilha vazia.\n");
        exit(1);
    }
    return pilha->topo->info;
}

// tentativa errada
void ordenarPilha(Pilha *pilha)
{
    Pilha tempPilha;
    criarPilha(&tempPilha);

    while (!estaVazio(pilha))
    {
        int temp = pop(pilha);

        while (!estaVazio(&tempPilha) && peek(&tempPilha) > temp)
        {
            push(pilha, pop(&tempPilha));
        }

        push(&tempPilha, temp);
    }

    while (!estaVazio(&tempPilha))
    {
        push(pilha, pop(&tempPilha));
    }
}

void sortStack(Pilha *pilha)
{
    Pilha* tempStack = (Pilha *)malloc(sizeof(Pilha));
    while(!estaVazio(pilha))
    {
        int currentElement = pop(pilha);
        while(!estaVazio(tempStack) && peek(tempStack) > currentElement)
            push(pilha, pop(tempStack));
        push(tempStack, currentElement);
    }
    while(!estaVazio(tempStack))
        push(pilha, pop(tempStack));
}

void inverter(Pilha *pilha)
{
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    while(pilha->topo)
        push(aux, pop(pilha));
    printarPilha(aux);
}