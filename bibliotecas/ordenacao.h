void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int *vetor, int n){
    int num_comparacoes,i, j, contador=0;
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
    int j ;
    int cont = 0;
    for (int i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && vetor[j - 1] > vetor[j]){
            swap(&vetor[j], &vetor[j-1]);
            cont++;
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
    int i,j,index_min;
    long int contador = 0;
    for (int j = 0; j < n-1; j++)
    {
        index_min = j;
        for ( i = j+1; i < n; i++)
        {
            contador++;
            if(vetor[i] < vetor[index_min])index_min = i;
        }
        if(index_min != 0){
            swap(&vetor[j],&vetor[index_min]);
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
            if (vetor[i] > vetor[i + 1]) {
                swap(&vetor[i], &vetor[i + 1]);
                trocou = 1;
                cont++;
            }
        }
         if (!trocou) {
            break;
        }
       fim--;
        trocou = 0;
        for (j = fim; j > inicio; j--) {
            if (vetor[j] < vetor[j - 1]) {
                swap(&vetor[j], &vetor[j - 1]);
                trocou = 1;
                cont++;
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
void merge(int arr[], int left, int middle, int right, int *comparisons) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        (*comparisons)++;
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

void mergeSort(int arr[], int left, int right, int *comparisons) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        mergeSort(arr, left, middle, comparisons);
        mergeSort(arr, middle + 1, right, comparisons);
        
        merge(arr, left, middle, right, comparisons);
    }
}

void heapify(int arr[], int n, int i, int *comparisons) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        (*comparisons)++;

    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        (*comparisons)++;
    }
 
    if (largest != i) {
        swap(&arr[i],&arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(int arr[], int n, int *comparisons) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }
 
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        heapify(arr, i, 0, comparisons);
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
    int digitos = 0;  
    int base = 1;  
    while (max > 0) {
        digitos++;
        max /= 10;
    }

    int comp = 0;  
    int* aux = (int*)malloc(tamanho * sizeof(int));  

    
    for (int d = 0; d < digitos; d++) {
        int contador[10] = {0};  
        for (int i = 0; i < tamanho; i++) {
            int digito = (vetor[i] / base) % 10;
            contador[digito]++;
        }
        for (int i = 1; i < 10; i++) {
            contador[i] += contador[i - 1];
        }        
        for (int i = tamanho - 1; i >= 0; i--) {
            int digito = (vetor[i] / base) % 10;
            aux[contador[digito] - 1] = vetor[i];
            contador[digito]--;
            comp++;  
        }
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = aux[i];
        }

        base *= 10;  
    }

    free(aux);  

    return comp;  
}
