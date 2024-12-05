#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
	setlocale (LC_ALL, "portuguese");
    int choice, target;
    clock_t start, end;
    double time_taken;

    int arr[] = {64, 34, 25, 12, 22, 11, 90, 20, 11, 80, 89, 100, 102, 120, 2, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Escolha uma operação:\n");
    printf("1. Ordenar a lista\n");
    printf("2. Procurar um elemento\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Escolha o algoritmo de ordenação:\n");
        printf("1. Selection Sort\n");
        printf("2. Quick Sort\n");
        int sort_choice;
        scanf("%d", &sort_choice);

        if (sort_choice == 1) {
            printf("Usando Selection Sort...\n");
            start = clock();
            selectionSort(arr, size);
            end = clock();
        } else if (sort_choice == 2) {
            printf("Usando Quick Sort...\n");
            start = clock();
            quickSort(arr, 0, size - 1);
            end = clock();
        } else {
            printf("Escolha inválida!\n");
            return 0;
        }

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Array ordenado: \n");
        printArray(arr, size);
        printf("Tempo de execução: %f segundos\n", time_taken);

    } else if (choice == 2) {
        printf("Digite o elemento que deseja procurar: ");
        scanf("%d", &target);

        printf("Ordenando o array antes da busca (Quick Sort)...\n");
        quickSort(arr, 0, size - 1);

        start = clock();
        int result = binarySearch(arr, size, target);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        if (result != -1)
            printf("Elemento encontrado no índice %d.\n", result);
        else
            printf("Elemento não encontrado.\n");

        printf("Tempo de execução da busca: %f segundos\n", time_taken);
    } else {
        printf("Escolha inválida!\n");
    }

    return 0;
}
