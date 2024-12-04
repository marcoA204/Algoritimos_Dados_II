#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int encontrarMax(int arr[], int tamanho) {
    int max = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int tamanho, int exp, int base) {
    int *output = (int *)malloc(tamanho * sizeof(int)); 
    int *count = (int *)calloc(base, sizeof(int));     

    for (int i = 0; i < tamanho; i++) {
        int digito = (arr[i] / exp) % base;
        count[digito]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        int digito = (arr[i] / exp) % base;
        output[count[digito] - 1] = arr[i];
        count[digito]--;
    }

    for (int i = 0; i < tamanho; i++) {
        arr[i] = output[i];
    }

    free(output);
    free(count);
}

void radixSort(int arr[], int tamanho, int base) {
    int max = encontrarMax(arr, tamanho);

    for (int exp = 1; max / exp > 0; exp *= base) {
        countingSort(arr, tamanho, exp, base);
    }
}

int main() {
	
    setlocale(LC_ALL, "portuguese");

	
    int arr[] = {35, 147, 72, 89, 156, 96, 132, 42, 73, 161, 109, 188, 61, 157, 119, 20, 1, 88, 17, 93};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\n Ordenando com base 10 \n");
    radixSort(arr, tamanho, 10);
    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int arr2[] = {35, 147, 72, 89, 156, 96, 132, 42, 73, 161, 109, 188, 61, 157, 119, 20, 1, 88, 17, 93};
    printf("\n Ordenando com base 2 \n");
    radixSort(arr2, tamanho, 2);
    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}