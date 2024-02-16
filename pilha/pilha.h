// estrutura de um nó (nodo) da pilha
typedef struct Nodo {
    int info;
    struct Nodo* prox;
} Nodo;

// estrutura da pilha
typedef struct {
    Nodo* topo;
} Pilha;

// protótipos das funções
void check(char par[]);
Pilha* criarPilha();
void destruirPilha(Pilha* pilha);
void push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int estaVazio(Pilha* pilha);
int saoIguais(Pilha* p1, Pilha* p2);