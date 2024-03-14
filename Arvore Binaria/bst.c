#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// função para criar a árvore a partir da raiz
Nodo *criarArvore(int chave_raiz)
{
    return criaNodo(chave_raiz); // retorna um novo nó com a chave da raiz
}

// função para destruir a árvore
void destruirArvore(Nodo *raiz)
{
    if (raiz != NULL)
    {
        destruirArvore(raiz->sae); // destrói a sae
        destruirArvore(raiz->sad); // destrói a sad
        free(raiz);                // libera o nó atual
    }
}

// função para criar um novo nó com a chave especificada
Nodo *criaNodo(int chave)
{
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo != NULL)
    {
        novo->chave = chave;
        novo->sae = NULL;
        novo->sad = NULL;
    }
    return novo;
}

// função para inserir um novo nó com a chave especificada na árvore
Nodo *inserir(Nodo *raiz, int chave)
{
    if (raiz == NULL)
        return criaNodo(chave);
    else if (chave < raiz->chave) // inserção na sae
        raiz->sae = inserir(raiz->sae, chave);
    else if (chave > raiz->chave) // inserção na sad
        raiz->sad = inserir(raiz->sad, chave);
    return raiz;
}

// função para remover um nó com a chave especificada da árvore
Nodo *remover(Nodo *raiz, int chave)
{
    // caso base: se a árvore está vazia, retorna NULL
    if (raiz == NULL)
    {
        return NULL;
    }

    // procura o nó a ser removido na árvore
    if (chave < raiz->chave)
    {
        raiz->sae = remover(raiz->sae, chave);
    }
    else if (chave > raiz->chave)
    {
        raiz->sad = remover(raiz->sad, chave);
    }
    else
    {
        // caso 1: nó não existe na árvore, não é necessário fazer nada
        if (raiz->sae == NULL && raiz->sad == NULL)
        {
            free(raiz);
            return NULL;
        }
        // caso 2: nó é uma folha / caso 3: nó possui apenas uma subárvore
        else if (raiz->sae == NULL)
        {
            Nodo *temp = raiz->sad;
            free(raiz);
            return temp;
        }
        else if (raiz->sad == NULL)
        {
            Nodo *temp = raiz->sae;
            free(raiz);
            return temp;
        }
        // caso 4: nó possui duas subárvores
        Nodo *temp = menorValor(raiz->sad);
        raiz->chave = temp->chave;
        raiz->sad = remover(raiz->sad, temp->chave);
    }
    return raiz;
}

// função para encontrar o menor valor em uma subárvore
Nodo *menorValor(Nodo *raiz)
{
    Nodo *atual = raiz; // inicializa o nó atual com a raiz fornecida
    // enquanto houver um filho à esquerda, percorre para a esquerda
    while (atual->sae != NULL)
    {
        atual = atual->sae;
    }
    return atual;
}
/*
int maiorValor(Nodo *raiz)
{
    if(raiz == NULL)
        return 0;
    while(raiz->sad != NULL)

}*/
// função para buscar um nó com a chave especificada na árvore
Nodo *buscar(Nodo *raiz, int chave)
{
    if (raiz == NULL || raiz->chave == chave)
        return raiz;              // nó encontrado ou árvore vazia
    else if (chave < raiz->chave) // procura na sae
        return buscar(raiz->sae, chave);
    else if (chave > raiz->chave) // procura na sad
        return buscar(raiz->sad, chave);
}

// função para percorrer a árvore em pré-ordem
void preOrdem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->chave);
        preOrdem(raiz->sae);
        preOrdem(raiz->sad);
    }
}

// função para percorrer a árvore em ordem
void emOrdem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->sae);
        printf("%d ", raiz->chave);
        emOrdem(raiz->sad);
    }
}

// função para percorrer a árvore em pós-ordem
void posOrdem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->sae);
        posOrdem(raiz->sad);
        printf("%d ", raiz->chave);
    }
}

// Desenvolva uma função para contar a quantidade de nós de uma BST
int qntdNos(Nodo *raiz)
{
    // int contador = 0;
    if (raiz == NULL)
        return 0;

    return 1 + qntdNos(raiz->sad) + qntdNos(raiz->sae);
}

/* Desenvolva uma função que imprima a quantidade de valores pares e primos
presente em uma BST. */
void qntdImparEPar(Nodo *raiz, int *qntdPar, int *qntdImpar)
{
    if (!raiz)
        return;

    if (raiz->chave % 2 == 0)
        (*qntdPar)++;
    else
        (*qntdImpar)++;

    qntdImparEPar(raiz->sad, qntdPar, qntdImpar);
    qntdImparEPar(raiz->sae, qntdPar, qntdImpar);
}

// Implemente uma função para computar a altura de um nó de uma BST.
int tamanhoNo(Nodo *raiz, int valor)
{
    if (raiz == NULL)
        return 0;
    if (valor < raiz->chave)
        return tamanhoNo(raiz->sae, valor) + 1; // Adiciona 1 para contar o próprio nó
    else if (valor > raiz->chave)
        return tamanhoNo(raiz->sad, valor) + 1; // Adiciona 1 para contar o próprio nó
    else
        return 1;
}

// Funcao que retorna o tamanho da raiz comparado ao ultimo no
int tamanhoRaiz(Nodo *raiz)
{
    if(raiz == NULL)
        return -1;
    int esquerda = tamanhoRaiz(raiz->sae); 
    int direita = tamanhoRaiz(raiz->sad);
    
    return 1+(esquerda > direita ? esquerda : direita); // esquerda eh maior que direita? se sim retorna esq se nao dir
}

/* Implemente uma função que, dado um valor, imprime se o mesmo está presente
na BST. Em caso positivo, então devem ser impressos os seus ancestrais. */
int achaValor(Nodo *raiz, int valor)
{
    Nodo *aux;
    //
    if (raiz == NULL)
        return 0;

    // se a chave for igual ao valor, entao printa e retorna 1
    if (raiz->chave == valor)
    {
        printf("%d ", raiz->chave);
        return 1;
    }

    // se o valor for menor que a chave, vai pra esquerda
    if (valor < raiz->chave)
    {
        if (achaValor(raiz->sae, valor)) // vai pra esquerda e printa o valor da esquerda
        {
            printf("%d ", raiz->chave);
            return 1;
        }
    }
    else
    {
        if (valor > raiz->chave)
            if (achaValor(raiz->sad, valor))
                printf("%d ", raiz->chave);
        return 1;
    }
}

// Implemente uma função que some todos os valores nas folhas de uma BST.
int somaFolhas(Nodo *raiz)
{
    if (raiz == NULL)
        return 0;

        // se os dois prox sao nulos, ent retorna a chave
    if (raiz->sae == NULL && raiz->sad == NULL)
        return raiz->chave;
        // retorna a soma da esq com a dir
    return somaFolhas(raiz->sae) + somaFolhas(raiz->sad);
}


// Implemente uma função que compara se duas BSTs são iguais.
int ehIgual(Nodo *arvore1, Nodo *arvore2)
{
    // se as duas sao nulas ent eh igual
    if (arvore1 == NULL && arvore2 == NULL)
        return 1;

    // se so uma arvore eh nula ent sao diferentes
    if (arvore1 == NULL || arvore2 == NULL)
        return 0;

    // se as chaves sao diferentes ent nao eh igual
    if (arvore1->chave != arvore2->chave)
        return 0;

    if (!ehIgual(arvore1->sae, arvore2->sae) || !ehIgual(arvore1->sad, arvore2->sad))
        return 0;

    // retorna 1 se tudo foi correto
    return 1;
}

// funcao que escreve a soma de todos nos da arvore
int somaNos(Nodo *raiz)
{
    if(raiz == NULL)
        return 0;
        
    return raiz->chave + somaNos(raiz->sad) + somaNos(raiz->sae);
}



/*  Escreva uma função que, para um dado um valor de entrada, verifica se o valor
informado e os seus divisores inteiros estão presentes em uma BST. */







/*

Desenho da arvore

          50
        /    \
      30      70
     /  \    /  \
    20  40  60  80
   /
  5

*/