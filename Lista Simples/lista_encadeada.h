// definição da estrutura da lista encadeada simples
typedef struct List {
    int info;
    struct List *prox;
} List;

// protótipos das funções
List *criarLista();
void destruirLista(List *lista);
List *inserirInicio(List *lista, int valor);
List *removerElemento(List *lista, int valor);
List *buscarElemento(List *lista, int valor);
void imprimirLista(List *lista);
int tamanhoLista(List *lista);
void inserirFim(List **lista, int valor); 
List *concatenar(List *lista1, List *lista2);
List *removerPrimeiro(List *lista);
List *removerElementos(List *lista, int quantidade);
