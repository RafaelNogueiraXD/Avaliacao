#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
void comparaG1eG2(int min_size,int max_size, int increment, char *caminho){
    int i, j;
    int aux;
    FILE *arquivo = fopen(caminho, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for (i = min_size; i <= max_size; i += increment) {
        int vetor[i];
        int vetor2[i];
        int vetor3[i];
        insereAleatorios(vetor, i, 0 , 1000000);
        memcpy(vetor2, vetor, i);
        memcpy(vetor3, vetor, i);
        
        int compar1 = selectionSort(vetor, i);
        int compar2 = bubbleSort(vetor2, i); 
        int compar3 = insertionSort(vetor3, i); 
        int compare0 = 0;
        quickSort(vetor,0, i,&compare0);
        int compare1 = 0; 
        mergeSort(vetor2, 0, i, &compare1);
        int compare2 = 0; 
        heapSort(vetor3, i , &compare2);
        // Registrar o número de comparações no arquivo de texto
        fprintf(arquivo, "%d %d %d \n",i ,(compare0+compare1+compare2)/3, (compar1+compar2+compar3)/3);
    }
    fclose(arquivo);
}
void comparaG1(int min_size,int max_size, int increment, char *caminho){
    int i, j;
    int aux;
    FILE *arquivo = fopen(caminho, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return ;
    }
    for (i = min_size; i <= max_size; i += increment) {
        int vetor[i];
        int vetor2[i];
        int vetor3[i];
        insereAleatorios(vetor, i, 0 , 1000000);
        memcpy(vetor2, vetor, i);
        memcpy(vetor3, vetor, i);
        
        int compar1 = selectionSort(vetor, i);
        int compar2 = bubbleSort(vetor2, i); 
        int compar3 = insertionSort(vetor3, i); 
        fprintf(arquivo, "%d %d %d %d\n",i , compar1,compar2,compar3);
    }
    fclose(arquivo);
}
void comparaG2(int min_size,int max_size, int increment,char *caminho){
    int i, j;
    int aux;
    FILE *arquivo = fopen(caminho, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return ;
    }
    for (i = min_size; i <= max_size; i += increment) {
        int vetor[i];
        int vetor2[i];
        int vetor3[i];
        insereAleatorios(vetor, i, 0 , 1000000);
        memcpy(vetor2, vetor, i);
        memcpy(vetor3, vetor, i);
        
        int compare0 = 0;
        quickSort(vetor,0, i,&compare0);
        int compare1 = 0; 
        mergeSort(vetor2, 0, i, &compare1);
        int compare2 = 0; 
        heapSort(vetor3, i , &compare2);
        // Registrar o número de comparações no arquivo de texto
        fprintf(arquivo, "%d %d %d %d\n",i , compare0,compare1,compare2);
    }
    fclose(arquivo);
}
