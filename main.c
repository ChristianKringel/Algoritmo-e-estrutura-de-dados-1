#include "circList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Lista *primeiro = criaLista();
  Lista *ultimo = NULL;
  ultimo = insereFim(primeiro, ultimo, 5);
  primeiro = insereLista(primeiro, &ultimo, 10);
  primeiro = insereLista(primeiro, &ultimo, 40);
  ultimo = insereFim(primeiro, ultimo, 60);
  imprimeLista(ultimo);
  imprimeLista(primeiro);
}
