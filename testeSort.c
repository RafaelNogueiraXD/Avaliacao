#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/ordenacao.h"

int main(){
    srand(time(NULL));
    int i, j;
    int min_size = 10;
    int max_size = 100;
    int increment = 1;
    for (i = min_size; i <= max_size; i += increment) {
        int vetor[i];
        int vetor2[i];
        int vetor3[i];
        // Preencher vetor aleatório
        int cont;
        for (j = 0; j < i; j++) {
            cont = rand() % 10000;
            vetor2[j]= cont;
            vetor[j] = cont;
            vetor3[j] = cont;
        }
        
        // Ordenar o vetor e obter o número de comparações 
        // int compare0 =0;
        // quickSort(vetor,0, i,&compare0);
        // int compare0 =0;
        // mergeSort(vetor,0, i,&compare0);
        // int compare0 =0;
        // heapSort(vetor,i,&compare0);
        printf("tamanho: %d  radix: %d, bb: %d \n",i, radixSort(vetor,i),bubbleSort(vetor2,i));
        // Registrar o número de comparações no arquivo de texto
        // fprintf(arquivo, "%d, %d\n", i, comparisons);
    }
   
}