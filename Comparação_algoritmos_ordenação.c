#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <locale.h>

long comparacoes = 0; 

double calcularTempo(void (*func)(int[], int), int arr[], int n) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    func(arr, n);
    gettimeofday(&fim, NULL);
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && (++comparacoes && arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparacoes++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortAux(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortAux(arr, l, m);
        mergeSortAux(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int arr[], int n) {
    mergeSortAux(arr, 0, n - 1);
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        trocar(&arr[min_idx], &arr[i]);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        comparacoes++;
        if (arr[j] <= pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortAux(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortAux(arr, low, pi - 1);
        quickSortAux(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSortAux(arr, 0, n - 1);
}

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (++comparacoes && arr[i] > max) max = arr[i];
    }

    int bucketCount = 10;
    int buckets[bucketCount][n];
    int bucketSizes[bucketCount];
    for (int i = 0; i < bucketCount; i++) bucketSizes[i] = 0;

    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * bucketCount) / (max + 1);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    for (int i = 0; i < bucketCount; i++) {
        selectionSort(buckets[i], bucketSizes[i]);
    }

    int idx = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (++comparacoes && arr[i] > max) max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void imprimirResultados(int arr[], int n, const char *algoritmo, void (*func)(int[], int)) {
    int *arrCopia = (int *)malloc(n * sizeof(int));
    if (arrCopia == NULL) {
        fprintf(stderr, "Erro ao alocar memória para arrCopia\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) arrCopia[i] = arr[i];

    comparacoes = 0;
    double tempo = calcularTempo(func, arrCopia, n);
    printf("%-15s | Tempo: %.6f s | Comparacoes: %ld\n", algoritmo, tempo, comparacoes);

    free(arrCopia);
}

int main() {
	setlocale (LC_ALL, "portuguese");
    int n = 1000; 
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    printf("Algoritmo       | Tempo de Execução | Número de Comparacoes\n");
    printf("---------------------------------------------------------\n");

    imprimirResultados(arr, n, "Shell Sort", shellSort);
    imprimirResultados(arr, n, "Merge Sort", mergeSort);
    imprimirResultados(arr, n, "Selection Sort", selectionSort);
    imprimirResultados(arr, n, "Quick Sort", quickSort);
    imprimirResultados(arr, n, "Bucket Sort", bucketSort);
    imprimirResultados(arr, n, "Radix Sort", radixSort);

    return 0;
}
