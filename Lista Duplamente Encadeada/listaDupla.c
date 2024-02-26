#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

Lista *criaLista()
{
    return NULL;
}

void *insereInicio(Lista **lista, int valor) // Se usa ** pq somente um ponteiro não é alterado o original
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
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    novo->info = valor;
    novo->prox = NULL; // O novo nó será o último, então o próximo é NULL

    if (*lista == NULL)
    {
        // Se a lista estiver vazia, o novo nó será o primeiro e o último
        *lista = novo;
    }
    else
    {
        // Encontra o último nó da lista
        Lista *temp = *lista;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        // Insere o novo nó após o último nó
        temp->prox = novo;
    }
}

/* Considere uma lista encadeada dupla contendo 𝑛 elementos. Implemente uma
função para inserir um elemento no meio de uma lista duplamente encadeada (ou
seja, na posição 𝑛/2. Para o caso de 𝑛 ímpar, insira na metade esquerda da lista). */

// primeiro, função que conta quantos elementos possui a lista
int tamanhoLista(Lista *lista)
{
    int contador = 0;
    Lista *aux = lista;
    while (aux)
    {
        contador++;
        aux = aux->prox;
    }
    return contador;
}

// agora vou usar esta funcao pra saber o meio dela e percorrer até la
// chegando no meio, faco a insercaoo

void inserirMeio(Lista **lista, int valor)
{
    Lista *aux = *lista, *nova, *aux2;
    nova = (Lista *)malloc(sizeof(Lista));

    if (nova == NULL)
    {
        printf("Erro ao alocar memória\n");
        return;
    }
    nova->info = valor;
    int tamanho = tamanhoLista(aux);
    for (int i = 0; i < (tamanho / 2); i++, aux = aux->prox)
        ;

    if (aux->anterior != NULL)
    {
        aux2 = aux->anterior;
        aux2->prox = nova;
    }
    else               // se for o primeiro no
        *lista = nova; // lista = nova
    nova->prox = aux;
    aux->anterior = nova;
}

/* Implemente uma função que busca um elemento em uma lista encadeada dupla.
A função deve imprimir a distância que o elemento se encontra a partir do início
e do final da lista. */

void busca(Lista *lista, int elemento)
{
    Lista *aux = lista;
    int i = 0;
    while (aux && aux->info != elemento)
    {
        i++; // posicao do elemento
        aux = aux->prox;
    }
    printf("Levando em consideracao o indice 0: ");
    printf("O elemento esta na posicao %d\n", i);
    printf("Logo, ele esta a %d posicoes do inicio\n", i - 1);
    printf("O elemento esta a %d posicoes do final da lista\n", tamanhoLista(lista) - i - 1);
}

/* Desenvolva uma função que remove dados duplicados de uma lista duplamente
encadeada. */

// primeiro funcao remover pelo indice
int removeIndice(Lista *lista, int indice)
{
    int valor;
    Lista *aux = lista, *aux2;
    for (int i = 0; i < indice; i++, aux = aux->prox)
        ;
    valor = aux->info;
    aux2 = aux->anterior;
    aux2->prox = aux->prox;
    return valor;
}

void removeDuplicado(Lista *lista)
{
    Lista *aux1 = lista, *aux2, *temp;
    int valor;

    while (aux1 != NULL && aux1->prox != NULL)
    {
        aux2 = aux1;    // recebe o valor dele pq n faz sentido ser outra coisa

        while (aux2->prox != NULL)
        {
            if (aux1->info == aux2->prox->info)
            {
                temp = aux2->prox;
                aux2->prox = aux2->prox->prox;
                valor = temp->info;
                free(temp);
                printf("Removido valor duplicado: %d\n", valor);
            }
            else
                aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
}

/* Escreva uma função removeIntervalo que receba dois parâmetros a e b e
remova todos os elementos que possuem valor (campo info) no intervalo [a, b]
em uma lista duplamente encadeada. */
/* 
void removeIntervalo(Lista *lista, int a, int b)
{

}
 */ 