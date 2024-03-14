// estrutura de um nó (nodo) da árvore
typedef struct Nodo {
    int chave;
    struct Nodo* sae;
    struct Nodo* sad;
} Nodo;

// protótipos das funções
Nodo* criarArvore(int chave_raiz);
void destruirArvore(Nodo* raiz);
Nodo* criaNodo(int chave);
Nodo* inserir(Nodo* raiz, int chave);
Nodo* remover(Nodo* raiz, int chave);
Nodo* menorValor(Nodo* raiz);
Nodo* buscar(Nodo* raiz, int chave);
void preOrdem(Nodo* raiz);
void emOrdem(Nodo* raiz);
void posOrdem(Nodo* raiz);
int qntdNos(Nodo *raiz);
void qntdImparEPar(Nodo *raiz, int *qntdPar, int *qntdImpar);
int tamanhoNo(Nodo *raiz, int valor);
int achaValor(Nodo *raiz, int valor);
int ehIgual(Nodo *arvore1, Nodo *arvore2);
int somaFolhas(Nodo *raiz);
int tamanhoRaiz(Nodo *raiz);
int somaNos(Nodo *raiz);