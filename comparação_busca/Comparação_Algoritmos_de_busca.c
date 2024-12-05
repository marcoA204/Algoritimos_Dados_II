#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <locale.h>

int binarySearch(int arr[], int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int mid = inicio + (fim - inicio) / 2;
        if (arr[mid] == chave) {
            return mid;
        }
        if (arr[mid] < chave) {
            inicio = mid + 1;
        } else {
            fim = mid - 1;
        }
    }
    return -1; 
}

int interpolationSearch(int arr[], int inicio, int fim, int chave) {
    while (inicio <= fim && chave >= arr[inicio] && chave <= arr[fim]) {
        if (arr[inicio] == arr[fim]) {
            return (arr[inicio] == chave) ? inicio : -1; // Evita divisão por zero
        }

        int pos = inicio + ((double)(fim - inicio) / (arr[fim] - arr[inicio])) * (chave - arr[inicio]);

        if (arr[pos] == chave) {
            return pos;
        }

        if (arr[pos] < chave) {
            inicio = pos + 1;
        } else {
            fim = pos - 1;
        }
    }
    return -1; 
}

int jumpSearch(int arr[], int n, int chave) {
    int step = sqrt(n); 
    int prev = 0;

    while (arr[step - 1] < chave && step < n) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; 
        }
    }

    for (int i = prev; i < step && i < n; i++) {
        if (arr[i] == chave) {
            return i;
        }
    }
    return -1; 
}

int exponentialSearch(int arr[], int n, int chave) {
    if (arr[0] == chave) {
        return 0; 
    }

    int i = 1;
    while (i < n && arr[i] <= chave) {
        i = i * 2; 
    }

    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, chave);
}

double calcularTempo3Parametros(int (*func)(int[], int, int, int), int arr[], int n, int chave) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    func(arr, 0, n - 1, chave);
    gettimeofday(&fim, NULL);
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
}

double calcularTempo2Parametros(int (*func)(int[], int, int), int arr[], int n, int chave) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    func(arr, n, chave);
    gettimeofday(&fim, NULL);
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
}

void imprimirTabelaComparativa(int arr[], int n, int chave) {
    printf("Tamanho da Lista: %d\n", n);
    printf("Algoritmo            | Tempo de Execução (segundos)\n");
    printf("---------------------|-----------------------------\n");

    double tempoBinary = calcularTempo3Parametros(binarySearch, arr, n, chave);
    printf("Binary Search        | %.6f\n", tempoBinary);

    double tempoInterpolation = calcularTempo3Parametros(interpolationSearch, arr, n, chave);
    printf("Interpolation Search | %.6f\n", tempoInterpolation);

    double tempoJump = calcularTempo2Parametros(jumpSearch, arr, n, chave);
    printf("Jump Search          | %.6f\n", tempoJump);

    double tempoExponential = calcularTempo2Parametros(exponentialSearch, arr, n, chave);
    printf("Exponential Search   | %.6f\n", tempoExponential);

    printf("\n");
}

int main() {
	setlocale (LC_ALL, "portuguese");
    int chave = 4999; 

    int lista1[999];
    for (int i = 0; i < 999; i++) lista1[i] = i * 2;

    int lista2[4999];
    for (int i = 0; i < 4999; i++) lista2[i] = i * 2;

    int lista3[9999];
    for (int i = 0; i < 9999; i++) lista3[i] = i * 2;

    imprimirTabelaComparativa(lista1, 999, chave);
    imprimirTabelaComparativa(lista2, 4999, chave);
    imprimirTabelaComparativa(lista3, 9999, chave);

    return 0;
}