#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <locale.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int inicio, int fim, int pivotIndex) {
    int pivot = arr[pivotIndex];
    trocar(&arr[pivotIndex], &arr[fim]); 
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (arr[j] <= pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[fim]); 
    return i + 1;
}

void quickSortPrimeiro(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int pivotIndex = inicio;
        int p = particionar(arr, inicio, fim, pivotIndex);
        quickSortPrimeiro(arr, inicio, p - 1);
        quickSortPrimeiro(arr, p + 1, fim);
    }
}

void quickSortUltimo(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int pivotIndex = fim; 
        int p = particionar(arr, inicio, fim, pivotIndex);
        quickSortUltimo(arr, inicio, p - 1);
        quickSortUltimo(arr, p + 1, fim);
    }
}

void quickSortMeio(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int pivotIndex = inicio + (fim - inicio) / 2; 
        int p = particionar(arr, inicio, fim, pivotIndex);
        quickSortMeio(arr, inicio, p - 1);
        quickSortMeio(arr, p + 1, fim);
    }
}

double calcularTempo(void (*func)(int[], int, int), int arr[], int tamanho) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    func(arr, 0, tamanho - 1);
    gettimeofday(&fim, NULL);
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
}

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
	
    setlocale(LC_ALL, "portuguese");

    int arrQuaseOrdenado[] = {6, 7, 10, 13, 17, 26, 27, 29, 42, 97, 78, 77, 75, 46};
    int arrDesordenado[] = {26, 10, 78, 17, 77, 46, 29, 7, 27, 97, 6, 42, 13, 75};
    int tamanho = sizeof(arrQuaseOrdenado) / sizeof(arrQuaseOrdenado[0]);

    int teste1[tamanho], teste2[tamanho];

    printf("Array quase ordenado:\n");
    imprimirArray(arrQuaseOrdenado, tamanho);
    printf("\n");

    printf("Array desordenado:\n");
    imprimirArray(arrDesordenado, tamanho);
    printf("\n");

    printf("Quick Sort em lista quase ordenada:\n");

    for (int i = 0; i < tamanho; i++) teste1[i] = arrQuaseOrdenado[i];
    double tempo1 = calcularTempo(quickSortPrimeiro, teste1, tamanho);
    printf("Primeiro elemento como pivô: Tempo = %.6f segundos\n", tempo1);

    for (int i = 0; i < tamanho; i++) teste2[i] = arrQuaseOrdenado[i];
    double tempo2 = calcularTempo(quickSortUltimo, teste2, tamanho);
    printf("Último elemento como pivô: Tempo = %.6f segundos\n", tempo2);

    for (int i = 0; i < tamanho; i++) teste1[i] = arrQuaseOrdenado[i];
    double tempo3 = calcularTempo(quickSortMeio, teste1, tamanho);
    printf("Elemento do meio como pivô: Tempo = %.6f segundos\n", tempo3);

    printf("\nQuick Sort em lista desordenada:\n");

    for (int i = 0; i < tamanho; i++) teste1[i] = arrDesordenado[i];
    tempo1 = calcularTempo(quickSortPrimeiro, teste1, tamanho);
    printf("Primeiro elemento como pivô: Tempo = %.6f segundos\n", tempo1);

    for (int i = 0; i < tamanho; i++) teste2[i] = arrDesordenado[i];
    tempo2 = calcularTempo(quickSortUltimo, teste2, tamanho);
    printf("Último elemento como pivô: Tempo = %.6f segundos\n", tempo2);

    for (int i = 0; i < tamanho; i++) teste1[i] = arrDesordenado[i];
    tempo3 = calcularTempo(quickSortMeio, teste1, tamanho);
    printf("Elemento do meio como pivô: Tempo = %.6f segundos\n", tempo3);

    return 0;
}