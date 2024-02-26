#include <stdio.h>
#include "lista_encadeada.h"

int main() {
    List *lista = criarLista();
    List *lista2 = criarLista();
    List *nova = criarLista();
    int posicao, maior;

    // Inserir elementos no início da lista
    lista = inserirInicio(lista, 11);
    lista = inserirInicio(lista, 20);
    inserirFim(&lista, 50); 
    lista = inserirInicio(lista, 3);
    lista = inserirInicio(lista, 30);

    lista2 = inserirInicio(lista2, 100);
    inserirFim(&lista2, 200);
    lista2 = inserirInicio(lista2, 150);
    //nova = concatenar(lista, lista2);
   // imprimirLista(nova);
    maiorValor(lista, &maior, &posicao);
        printf("O maior valor eh: %d\n a posicao eh: %d\n", maior, posicao);
    printf("A quantidade de numeros pares eh: %d\n", quantidadeDeNPar(lista));
    /*
    printf("\n");
    // Imprimir a lista
    printf("Lista inicial: ");
    imprimirLista(lista);
    lista = removerElemento(lista, 2);
    printf("\n");
    imprimirLista(lista);
    */ 

    printf("Tamanho da lista: %d\n", tamanhoLista(lista));
    // Buscar e imprimir um elemento
    int valorBuscado = 20;
    List *elementoEncontrado = buscarElemento(lista, valorBuscado);
    if (elementoEncontrado != NULL) {
        printf("Elemento %d encontrado na lista.\n", valorBuscado);
    } else {
        printf("Elemento %d não encontrado na lista.\n", valorBuscado);
    }

    // Remover um elemento
    int valorRemover = 30;
    lista = removerElemento(lista, valorRemover);

    // Imprimir a lista após a remoção
    printf("Lista após remover %d: ", valorRemover);
    imprimirLista(lista);

    // Destruir a lista
    destruirLista(lista);

    return 0;
}