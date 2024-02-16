typedef struct Lista{
    int info; 
    struct Lista *prox; 
    struct Lista *anterior;
} Lista; 

Lista *criaLista();
void *insereInicio(Lista **lista, int valor);
void imprimeLista(Lista *lista);
void insereFim(Lista **lista, int valor);
