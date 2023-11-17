#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void bubbleSortCrescent(int number[]);
void bubbleDecrescent(int number[]);

int main()
{
    int numbers[TAM];
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o valor no vetor %d: ", i); // Escaneando o vetor
        scanf("%d", &numbers[i]);
    }
    bubbleSortCrescent(numbers);
    bubbleDecrescent(numbers);
    return 0;
}

// Func para ordenar o vetor por bubble
void bubbleSortCrescent(int number[])
{
    int aux;
    printf("Vetor sem ordenação: ");
    for (int i = 0; i < TAM; i++)
        printf("%d ", i[number]);
    for (int counter = 1; counter < TAM; counter++)
    {
        for (int i = 0; i < TAM - 1; i++)
        {
            if (number[i] > number[i + 1])
            {
                aux = number[i];
                number[i] = number[i + 1];
                number[i + 1] = aux;
            }
        }
    }
    printf("\n");
    // Printando em ordem crescente
    printf("Algoritmo ordenado: ");
    for (int i = 0; i < TAM; i++)
        printf("%d ", number[i]);
}

// Algoritmo para ordenar em formato decrescente 
void bubbleDecrescent(int number[])
{
    int aux;
    for (int count = 1; count < TAM; count++)
    {
        for (int i = 0; i < TAM - 1; i++)
        {
            if (number[i] < number[i + 1])
            {
                aux = number[i];
                number[i] = number[i + 1];
                number[i + 1] = aux;
            }
        }
    }
    // printando em formato decrescente
    printf("\n");
    printf("Algoritmo decrescente: ");
    for (int i = 0; i < TAM; i++)
        printf("%d ", number[i]);
}
