#include <stdio.h>
#include <stdlib.h>

int estaOrdenado(int *vetor);
/* Escreva um programa que leia um vetor de 10 posições (.word) da memória
(começando na posição 0x10010000) e verifique se o vetor está ou não ordenado.
Use o registrador $t0 como flag.
Faça $t0 = 1 se o vetor estiver ordenado e $t0 = 0 caso contrário. */
int main()
{
    if(estaOrdenado(1, 5, 10, 20))
        printf("O vetor esta ordenado\n");
    else
        printf("O vetor nao esta ordenado\n");
}

int estaOrdenado(int *vetor)
{
    int vetor[10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            if(vetor[i] > vetor[j])
                return 0;
        }
    }
    return 1;
}