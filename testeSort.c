#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/ordenacao.h"

int main(){
    srand(time(NULL));
    int i, j;
    FILE *arquivo;
    arquivo = fopen("../txt/radixt-p.txt","a");
    int min_size = 1;
    int max_size = 10000;
    int increment = 1;
    for (i = min_size; i <= max_size; i += increment) {
        int vetor[i];
        int vetor2[i];
        int vetor3[i];
        int vetor4[i];
        // Preencher vetor aleatório
        int cont;
        for (j = 0; j < i; j++) {
            cont = rand() % 10000;
            vetor[j] = cont;
            vetor2[j]= cont;
            vetor3[j] = cont;
            vetor4[j] = cont;
        }
        
        // Ordenar o vetor e obter o número de comparações 
        int compare0 = bubbleSort(vetor,i);
        int compare2 = selectionSort(vetor,i);
        int compare1 = insertionSort(vetor,i);
        fprintf(arquivo,"%d %d %d\n",i,radixSort(vetor,i),(compare0+compare1+compare2)/3);
        // Registrar o número de comparações no arquivo de texto
        // fprintf(arquivo, "%d, %d\n", i, comparisons);
    }
   
}