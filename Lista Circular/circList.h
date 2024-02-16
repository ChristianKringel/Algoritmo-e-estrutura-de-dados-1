
typedef struct Lista {
  int info;
  struct Lista *prox;
} Lista;


Lista *criaLista();
void imprimeLista(Lista *prim);
void *insereFim(Lista *prim, Lista **ult, int valor);
Lista *insereLista(Lista *prim, Lista **ult, int valor); 
