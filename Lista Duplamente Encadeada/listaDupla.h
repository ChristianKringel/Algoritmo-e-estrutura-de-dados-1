typedef struct Lista{
    int info; 
    struct Lista *prox; 
    struct Lista *anterior;
} Lista; 

Lista *criaLista();
void *insereInicio(Lista **lista, int valor);
void imprimeLista(Lista *lista);
void insereFim(Lista **lista, int valor);
void inserirMeio(Lista **lista, int valor);
int tamanhoLista(Lista *lista);
void busca(Lista *lista, int elemento);
int removeIndice(Lista *lista, int indice);
void removeDuplicado(Lista *lista);
void removeIntervalo(Lista **lista, int a, int b);
