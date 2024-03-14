#include <stdio.h>
#include "bst.h" 

int main() {
    Nodo* raiz = NULL; // inicializa a raiz da árvore como NULL
    Nodo *raiz2 = NULL;
    int qntdPar = 0;
    int qntdImpar = 0;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);
    //raiz2 = inserir(raiz2, 30);
    //raiz2= inserir (raiz2, 70);
    // insere valores na árvore
    /*
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);
    */ 
   printf("A soma de todos nos eh: %d\n", somaNos(raiz));
   printf("O tamanho da raiz eh: %d\n", tamanhoRaiz(raiz));
    printf("A soma das folhas da arvore eh: %d\n", somaFolhas(raiz));
    

    if(ehIgual(raiz, raiz2))
        printf("As arvores sao iguais!\n");
    else
        printf("As arvores sao diferentes\n");
    //achaValor(raiz, 20);
    //printf("\n");
    //printf("O no %d esta na altura: %d\n", 50, tamanhoNo(raiz, 50));
    
    // quantidade de nos na arvore
    printf("Quantidade de nos da arvore: %d", qntdNos(raiz));
    printf("\n");

    // quantidade de impares e pares na arvore
    qntdImparEPar(raiz, &qntdPar, &qntdImpar);
    printf("%d nos sao pares!\n", qntdPar);
    printf("%d nos sao impares!\n", qntdImpar);

    printf("Árvore em ordem: ");
    emOrdem(raiz2);
    printf("\n");

    // imprime a árvore em ordem
    printf("Árvore em ordem: ");
    emOrdem(raiz);
    printf("\n");

    // imprime a árvore em pré-ordem
    printf("Árvore em pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    // imprime a árvore em pós-ordem"
    printf("Árvore em pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    // busca por um valor na árvore
    int chave_busca = 40;
    Nodo* resultado_busca = buscar(raiz, chave_busca);
    if (resultado_busca != NULL) {
        printf("Valor %d encontrado na árvore.\n", chave_busca);
    } else {
        printf("Valor %d não encontrado na árvore.\n", chave_busca);
    }

    // remove um nó com chave 30
    raiz = remover(raiz, 30);

    // imprime a árvore em ordem após a remoção
    printf("Árvore em ordem após a remoção: ");
    emOrdem(raiz);
    printf("\n");

    // insere mais valores na árvore
    raiz = inserir(raiz, 55);
    raiz = inserir(raiz, 65);

    // imprime a árvore em ordem após inserção adicional
    printf("Árvore em ordem após inserções adicionais: ");
    emOrdem(raiz);
    printf("\n");

    // libera a memória alocada pela árvore
    destruirArvore(raiz);

    return 0;
}