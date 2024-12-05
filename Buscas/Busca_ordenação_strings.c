#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Função para comparar duas strings (usada no Quick Sort)
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Função de ordenação Merge Sort
void merge(char *arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    char *L[n1], *R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(char *arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

// Função de ordenação Quick Sort
void quickSort(char *arr[], int low, int high);

// Função de particionamento (Partition) usada pelo Quick Sort
int partition(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

void quickSort(char *arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Função para Busca Binária
int binarySearch(char *arr[], int size, char *key) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        int res = strcmp(arr[mid], key);
        
        if (res == 0)
            return mid; // Palavra encontrada
        if (res < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Palavra não encontrada
}

int main() {
	setlocale (LC_ALL, "portuguese");
    // Lista de palavras para testar
    char *words[] = {"gorila", "corvo", "tatu", "porco", "aguia", "lula", "gato", "cachorro"};
    int n = sizeof(words) / sizeof(words[0]);
    
    // Ordenando as palavras usando Merge Sort
    mergeSort(words, 0, n - 1);
    printf("Palavras ordenadas com Merge Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }
    
    // Realizando a Busca Binária
    char *searchWord = "porco";
    int result = binarySearch(words, n, searchWord);
    if (result != -1) {
        printf("\nPalavra '%s' encontrada no índice %d.\n", searchWord, result);
    } else {
        printf("\nPalavra '%s' não encontrada.\n", searchWord);
    }
    
    // Ordenando as palavras usando Quick Sort
    quickSort(words, 0, n - 1);
    printf("\nPalavras ordenadas com Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }
    
    // Realizando a Busca Binária novamente após Quick Sort
    result = binarySearch(words, n, searchWord);
    if (result != -1) {
        printf("\nPalavra '%s' encontrada no índice %d.\n", searchWord, result);
    } else {
        printf("\nPalavra '%s' não encontrada.\n", searchWord);
    }
    
    return 0;
}
