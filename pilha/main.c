#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    // exemplo de uso da pilha
    Pilha* pilha = criarPilha();
    //Pilha* pilha2 = criarPilha();

    push(pilha, 4);
    push(pilha, 2);
    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 110);
    push(pilha, 3);
    push(pilha, 1);
    push(pilha, -20);
   // ordenarPilha(pilha);
    sortStack(pilha);
    printarPilha(pilha);
    menorMaiorMedia(pilha);
    /*if(palindromo(pilha))
        printf("A pilha eh palindroma!\n");
    else
        printf("Nao eh palindroma!\n");
    destruirPilha(pilha);
*/
    //push(pilha2, 10);
    //push(pilha2, 20);
    //push(pilha2, 30);
    //push(pilha2, 40);
    /*if(saoIguais(pilha, pilha2))
        printf("As pilhas sao iguais\n");
    else 
        printf("As pilhas sao diferentes\n");*/ 
    //check('()');
    //check(pilha, '(' ')');

    //printf("Elemento removido da pilha: %d\n", pop(pilha));
    //printf("Elemento removido da pilha: %d\n", pop(pilha));
    //printf("Elemento removido da pilha: %d\n", pop(pilha));
    /*
    if (estaVazio(pilha))
    	printf("Pilha vazia.\n");
    else 
    	printf("Pilha não está vazia.\n");
        destruirPilha(pilha);


 */
    return 0;
}