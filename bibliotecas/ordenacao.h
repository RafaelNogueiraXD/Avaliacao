void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int bubbleSort(int *vetor, int n){
    int num_comparacoes, i, j, contador = 0;
    for (i = 0; i < n-1; i++){
        num_comparacoes = n-i-1;
        for (j = 0; j < num_comparacoes; j++){
            contador++;
            if (vetor[j] > vetor[j+1]){
                swap(&vetor[j], &vetor[j+1]);
            }
        }
    }
    return contador;
}

int insertionSort(int *vetor, int n){
    int j;
    int cont = 0;
    for (int i = 1; i < n; i++){
        j = i;
        while (j > 0 && vetor[j - 1] > vetor[j]){
            cont++;
            swap(&vetor[j], &vetor[j-1]);
            j--;
        }
    }
    return cont;
}

void mostraVetor(int *vetor,int n){
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}
int selectionSort(int *vetor, int n){
    int contador = 0;
    for (int j = 0; j < n-1; j++){
        int index_min = j;
        for (int i = j+1; i < n; i++){
            contador++; 
            if (vetor[i] < vetor[index_min]){
                index_min = i;
            }
        }
        if (index_min != j){
            swap(&vetor[j], &vetor[index_min]);
        }
    }
    return contador;
}

void insereAleatorios(int *vetor, int n, int min, int max){
       srand(time(NULL));  
    int i, j, numero,aux;
    for (i = 0; i <  n; i++) 
        vetor[i] = i;       
    for (j = 0; j < n; j++) {  
    
        numero = rand() % n;  
        aux = vetor[numero];
        vetor[numero] = vetor[j];
        vetor[j] = aux;
     }
    
}

int shakeSort(int *vetor, int n){
    int i, j, k, trocou;
    int inicio = 0;
    int fim = n-1;
    int cont = 0;
    while (inicio < fim) {
        trocou = 0;
        for (i = inicio; i < fim; i++) {
            cont++;
            if (vetor[i] > vetor[i + 1]) {
                swap(&vetor[i], &vetor[i + 1]);
                trocou = 1;
            }
        }
         if (!trocou) {
            break;
        }
       fim--;
        trocou = 0;
        for (j = fim; j > inicio; j--) {
            cont++;
            if (vetor[j] < vetor[j - 1]) {
                swap(&vetor[j], &vetor[j - 1]);
                trocou = 1;
            }
        }
        inicio++;
        if (!trocou) {
            break;
        }
    }
     printf("\n contador : %d", cont);
    return cont;
}
int partition(int *vetor, int esquerda, int direita, int *contador){
    int pivo = vetor[direita];
    int i = esquerda - 1;

    for(int j=esquerda; j<=direita-1; j++){
        (*contador)++;
        if(vetor[j] <= pivo){
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i+1], &vetor[direita]);
    return i+1;
}
void quickSort(int *vetor, int esquerda, int direita, int *contador){
    if(esquerda < direita){
        int pivo = partition(vetor, esquerda, direita, contador);
        quickSort(vetor, esquerda, pivo-1, contador);
        quickSort(vetor, pivo+1, direita, contador);
    }
}
void merge(int arr[], int esquerda, int meio, int direita, int *comparador) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++) {
        L[i] = arr[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = esquerda;
    
    while (i < n1 && j < n2) {
        (*comparador)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int esquerda, int direita, int *comparador) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        mergeSort(arr, esquerda, meio, comparador);
        mergeSort(arr, meio + 1, direita, comparador);
        
        merge(arr, esquerda, meio, direita, comparador);
    }
}

void heapify(int arr[], int n, int i, int *comparador) {
    int largest = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
 
    if (esquerda < n && arr[esquerda] > arr[largest]) {
        largest = esquerda;
    }
 
    if (direita < n && arr[direita] > arr[largest]) {
        largest = direita;
    }
 
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        (*comparador)++;
        heapify(arr, n, largest, comparador);
    }
}

void heapSort(int arr[], int n, int *comparador) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparador);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0],arr[i]);
        (*comparador)++;
        heapify(arr, i, 0, comparador);
    }
}

int encontrarMaximo(int vetor[], int tamanho) {
    int max = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    return max;
}
int radixSort(int vetor[], int tamanho) {
    int max = encontrarMaximo(vetor, tamanho);
    int comp = 0;
    int* aux = (int*)malloc(tamanho * sizeof(int));
    for (int base = 1; max / base > 0; base *= 10) {
        int contador[10] = {0};
        for (int i = 0; i < tamanho; i++) {
            int digito = (vetor[i] / base) % 10;
            contador[digito]++;
        }
        for (int i = 1; i < 10; i++)contador[i] += contador[i - 1];
        for (int i = tamanho - 1; i >= 0; i--) {
            int digito = (vetor[i] / base) % 10;
            aux[--contador[digito]] = vetor[i];
            comp++;
        }
        for (int i = 0; i < tamanho; i++)vetor[i] = aux[i];
        
    }
       free(aux);
    return comp;
}
