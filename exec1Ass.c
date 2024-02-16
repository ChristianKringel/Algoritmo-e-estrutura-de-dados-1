#include <stdio.h>
#include <stdio.h>

int main()
{
    int valor;
    printf("Digite o valor a ser calculado: ");
    scanf("%d", &valor);
    for(int i = 1; i < 11; i++)
        printf("%dx%d = %d \n", valor, i, valor*i);
    return 0;
}

