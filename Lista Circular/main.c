#include "circList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Lista *primeiro = criaLista();
  Lista *ultimo = NULL;
  //insereFim(primeiro, &ultimo, 5);
  primeiro = insereLista(primeiro, &ultimo, 10);
  primeiro = insereLista(primeiro, &ultimo, 40);
  //insereFim(primeiro, &ultimo, 60);
  //insereFim(primeiro, &ultimo, 5);
  primeiro = insereLista(primeiro, &ultimo, 50); // problema na junção das listas 
  primeiro = insereLista(primeiro, &ultimo, 80);
  //imprimeLista(ultimo);
  imprimeLista(primeiro);
}
