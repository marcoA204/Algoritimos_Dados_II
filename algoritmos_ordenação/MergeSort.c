#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void mergeInteiros(int arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
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

void mergeSortInteiros(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSortInteiros(arr, inicio, meio);
        mergeSortInteiros(arr, meio + 1, fim);

        mergeInteiros(arr, inicio, meio, fim);
    }
}

void mergeStrings(char* arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    char* L[n1];
    char* R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) { 
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

void mergeSortStrings(char* arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSortStrings(arr, inicio, meio);
        mergeSortStrings(arr, meio + 1, fim);

        mergeStrings(arr, inicio, meio, fim);
    }
}

void imprimirArrayInteiros(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void imprimirArrayStrings(char* arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
	
    setlocale(LC_ALL, "portuguese");
	
    int arr_inteiros[] = {92, 47, 42, 55, 59, 34, 57, 47, 24, 35, 20, 49, 28, 91, 35};
    int tamanho_inteiros = sizeof(arr_inteiros) / sizeof(arr_inteiros[0]);

    printf("Array original de inteiros:\n");
    imprimirArrayInteiros(arr_inteiros, tamanho_inteiros);

    mergeSortInteiros(arr_inteiros, 0, tamanho_inteiros - 1);

    printf("Array ordenado de inteiros:\n");
    imprimirArrayInteiros(arr_inteiros, tamanho_inteiros);

    char* arr_strings[] = {"banana", "apple", "orange", "grape", "cherry"};
    int tamanho_strings = sizeof(arr_strings) / sizeof(arr_strings[0]);

    printf("\nArray original de strings:\n");
    imprimirArrayStrings(arr_strings, tamanho_strings);

    mergeSortStrings(arr_strings, 0, tamanho_strings - 1);

    printf("Array ordenado de strings:\n");
    imprimirArrayStrings(arr_strings, tamanho_strings);

    return 0;
}