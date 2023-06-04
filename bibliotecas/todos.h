#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
void comparaG1eG2(int min_size, int max_size, int increment, const char* caminho) {
    FILE* arquivo = fopen(caminho, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = min_size; i <= max_size; i += increment) {
        int vetor[i];
        int vetor2[i];
        int vetor3[i];
        insereAleatorios(vetor, i, 0, 100000);
        
        memcpy(vetor2, vetor, sizeof(int) * i);
        memcpy(vetor3, vetor, sizeof(int) * i);
        
        int compar1 = selectionSort(vetor, i);
        int compar2 = bubbleSort(vetor2, i); 
        int compar3 = insertionSort(vetor3, i); 
        
        int compare0 = 0;
        int vetor4[i];
        memcpy(vetor4, vetor, sizeof(int) * i);
        quickSort(vetor4, 0, i - 1, &compare0);
        
        int compare1 = 0;
        int vetor5[i];
        memcpy(vetor5, vetor, sizeof(int) * i);
        mergeSort(vetor5, 0, i - 1, &compare1);
        
        int compare2 = 0;
        int vetor6[i];
        memcpy(vetor6, vetor, sizeof(int) * i);
        heapSort(vetor6, i, &compare2);
        
        
        int comparacao_media = (compare0 + compare1 + compare2) / 3;
        int comparacao_media_sorts = (compar1 + compar2 + compar3) / 3;
        fprintf(arquivo, "%d %d %d\n", i, comparacao_media, comparacao_media_sorts);
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
        int *vetor = (int*) malloc(sizeof(int) *i);
        int *vetor2 = (int*) malloc(sizeof(int) *i);
        int *vetor3 = (int*) malloc(sizeof(int) *i);
        
        insereAleatorios(vetor, i, 0, 100000);
        
        memcpy(vetor2, vetor, sizeof(int) * i);
        memcpy(vetor3, vetor, sizeof(int) * i);

        int compar1 = selectionSort(vetor, i);
        int compar2 = bubbleSort(vetor2, i); 
        
        
        int compar3 = insertionSort(vetor3, i); 
        fprintf(arquivo, "%d %d %d %d\n",i , compar1,compar2,compar3);
        free(vetor);
        free(vetor2);
        free(vetor3);
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
        insereAleatorios(vetor, i, 0, 100000);
        
        memcpy(vetor2, vetor, sizeof(int) * i);
        memcpy(vetor3, vetor, sizeof(int) * i);
        
        int compare0 = 0;
        quickSort(vetor,0, i,&compare0);
        int compare1 = 0; 
        mergeSort(vetor2, 0, i, &compare1);
        int compare2 = 0; 
        heapSort(vetor3, i , &compare2);
        
        fprintf(arquivo, "%d %d %d %d\n",i , compare0,compare1,compare2);
    }
    fclose(arquivo);
}
