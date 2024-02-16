#include <stdio.h>

int main()
{

}

void mergeSort(int *v, int esq, int dir)
{
    if(esq < dir)
    {
        int meio = (esq + dir) / 2; 
        mergeSort(v, esq, meio);
        mergeSort(v, meio+1, dir);

        merge(v, esq, meio, dir);
    }
}

void merge(int *v, int esq, int meio, int dir)
{
    
}