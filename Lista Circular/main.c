#include "circList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Lista *primeiro = criaLista();
  Lista *outra = criaLista();
  Lista *outroUlt = NULL;
  Lista *ultimo = NULL;
  // insercoes na primeira lista
  primeiro = insereLista(primeiro, &ultimo, 10);
  primeiro = insereLista(primeiro, &ultimo, 40);
  primeiro = insereLista(primeiro, &ultimo, 70);
  insereFim(primeiro, &ultimo, 60);
  primeiro = insereLista(primeiro, &ultimo, 50);
  primeiro = insereLista(primeiro, &ultimo, 80);
  achaPeloIndice(primeiro, 3);
  printf("O tamanho da lista eh: %d\n", tamanhoLista(primeiro, ultimo));
  imprimeLista(primeiro);
  // insercoes na outra lista
  outra = insereLista(outra, &outroUlt, 10);
  outra = insereLista(outra, &outroUlt, 40);
  outra = insereLista(outra, &outroUlt, 70);
  insereFim(outra, &outroUlt, 60);
  outra = insereLista(outra, &outroUlt, 50);
  outra = insereLista(outra, &outroUlt, 80);
  //imprimeLista(ultimo);
  
  //primeiro = remover(primeiro, 40);
  primeiro = concatenarListas(primeiro, outra);
  printf("Lista apos concatenar\n ");
  imprimeLista(primeiro);
}
