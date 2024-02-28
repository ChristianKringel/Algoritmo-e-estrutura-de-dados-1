
typedef struct Lista {
  int info;
  struct Lista *prox;
} Lista;


Lista *criaLista();
void imprimeLista(Lista *prim);
void insereFim(Lista *prim, Lista **ult, int valor);
Lista *insereLista(Lista *prim, Lista **ult, int valor); 
Lista *remover(Lista *prim, int valor);
int tamanhoLista(Lista *prim, Lista *ult);
void achaPeloIndice(Lista *prim, int indice);
Lista *concatenarListas(Lista *ini1, Lista *ini2);