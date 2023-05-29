
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
void registraContador(FILE* arq, char *nomeSort, int contador,int tamanho){
    printf("\n\tMostra %s", nomeSort);
    printf("\ncomparações: %d", contador);
    fprintf(arq, "\n %s - %d - %d", nomeSort,tamanho, contador);
    // free(nomeSort);
}
void desaloca(int* vetor){
    free(vetor);
}
int main(){
    int n = 20,cont, i = 3;
    FILE *arq;
        
    arq = fopen("database.txt", "a"); 
    fprintf(arq,"\n\tnumero de comparações");
    while(i != 0){
        n = n * 2^i;             
        int *vetor = (int*) malloc(sizeof(int)* n);
        int *vetor2 = (int*) malloc(sizeof(int)* n);
        int *vetor3 = (int*) malloc(sizeof(int)* n);
        int *vetor4 = (int*) malloc(sizeof(int)* n);
        int *vetor5 = (int*) malloc(sizeof(int)* n);
        insereAleatorios(vetor, n, 0, 10000);
        memcpy(vetor2, vetor, sizeof(int)*n);
        memcpy(vetor3, vetor, sizeof(int)*n);
        memcpy(vetor4, vetor, sizeof(int)*n);
        memcpy(vetor5, vetor, sizeof(int)*n);
        
        cont = bubbleSort(vetor, n);
        registraContador(arq,"Selection Sort",n, cont);
        registraContador(arq,"Insertion Sort",n,insertionSort(vetor3,n));
        registraContador(arq,"Shake Sort",n,shakeSort(vetor4, n));
        int contador = 0;
        quickSort(vetor5,0, n-1, &contador);
        registraContador(arq,"Quick Sort",n,contador);
        i--;
        desaloca(vetor);
        desaloca(vetor2);
        desaloca(vetor3);
        desaloca(vetor4);
        desaloca(vetor5);
    }
    return 0;
}   

