#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void shakeSort(int *vetor, int tamanho) {
    int esquerda = 0,direita = tamanho - 1,trocou = 1;
	while(trocou){
		trocou = 0;
		for(int i = esquerda; i< direita; i++){
			if(vetor[i] > vetor[i +1]){
				swap(&vetor[i],&vetor[i +1]);
				trocou = 1;
			}
		}
		direita--;
		for (int i = direita; i > esquerda; i--)
		{
			if(vetor[i] < vetor[i -1]){
				swap(&vetor[i],&vetor[i -1]);
				trocou = 1;
			}
		}
		esquerda++;
	}

}
void quickSort(int* arr, int low, int high) { 
	if(low<high){ 
		int p=partition(arr,low,high);
		quickSort(arr,low,p-1); 
		quickSort(arr,p+1,high); } 
} 
int partition(int* arr,int low,int high) {
	 int pivot=arr[high]; int i=low-1; 
	 for(int j=low;j<=high-1;j++){ 
		if(arr[j]<pivot){
			i++; 
			swap(&arr[i],&arr[j]);
		}
		} 
		swap(&arr[i+1],&arr[high]); return (i+1);
}

void sort3(int *vetor, int n){
	for (int i = 0; i < n-1; i++)
		for(int j = 0; j < n-i-1; i++)
			if(vetor[j] > vetor[j+1])swap(&vetor[j],&vetor[j+1]);
	
}
int Sort(int *vetor, int n){
	for(int i = 0; i < n; i++)
		for(int j = i; j > 0 && vetor[j] < vetor[j - 1]; j--)
			swap(&vetor[j],&vetor[j-1]);
}
void Sort2(int *vetor, int n) {
	for(int i = 0, min = 0; i < n - 1 ; i++, min = i){
		for (int j = i + 1; j < n; j++)
			if(vetor[j] < vetor[min])min = j;
		if(min != i)swap(&vetor[min], &vetor[i]);
	}	
}
int buscaBinaria(int *vetor, int valor, int tamanho){
	int meio = 0,direita = tamanho - 1, esquerda = 0; 
	int comparacoes = 0;
	while(esquerda <= direita){
		meio = floor((esquerda + direita) / 2);
		if(vetor[meio] == valor)return comparacoes;
		else if(vetor[meio] < valor) esquerda = meio +1;
		else direita = meio -1; 
	}
}

int main(){
	int vetor[4] = {5, 2 ,4, 2};

	for(int i = 0;i< 4; i++)printf(" %d - ", vetor[i]);
}