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
void ordenar(Pilha *pilha);
void printarPilha(Pilha *pilha);
void destruirPilha(Pilha* pilha);
void menorMaiorMedia(Pilha *p1);
void push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int estaVazio(Pilha* pilha);
int saoIguais(Pilha* p1, Pilha* p2);
int palindromo(Pilha* pilha);
void ordenarPilha(Pilha *pilha);
void sortStack(Pilha *pilha);
void inverter(Pilha *pilha);