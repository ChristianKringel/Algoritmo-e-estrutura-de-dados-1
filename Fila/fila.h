// Estrutura de um nó (nodo) da fila
typedef struct Nodo {
    int info;
    struct Nodo* prox;
} Nodo;

// estrutura da fila
typedef struct {
    Nodo* inicio;
    Nodo* fim;
} Fila;

// Protótipos das funções
Fila* criarFila();
void destruirFila(Fila* fila);
void enqueue(Fila* fila, int data);
int dequeue(Fila* fila);
int estaVazio(Fila* fila);
int maiorFila(Fila *f1, Fila* f2);
void printarFila(Fila* f1);
void excluirNeg(Fila **fila);
int quantidadePar(Fila *fila);
void concatenarFila(Fila* f1, Fila* f2);
void concatenarFilaComplexo(Fila* f1, Fila* f2);
int tamanhoFila(Fila *fila);
void inverterFila(Fila *fila);