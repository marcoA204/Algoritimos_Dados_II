#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int binarySearch(int arr[], int inicio, int fim, int elemento) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == elemento) {
            return meio; 
        }

        if (arr[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int exponentialSearch(int arr[], int tamanho, int elemento) {
    if (arr[0] == elemento) {
        return 0; 
    }

    int i = 1;
    while (i < tamanho && arr[i] <= elemento) {
        i *= 2;
    }

    return binarySearch(arr, i / 2, fmin(i, tamanho - 1), elemento);
}

double medirTempo(int (*func)(int[], int, int), int arr[], int tamanho, int elemento) {
    clock_t inicio = clock();
    func(arr, tamanho, elemento);
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC; 
}

int main() {
	setlocale(LC_ALL, "portuguese");
	
    int arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int elemento;

    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &elemento);

    printf("\n--- Exponential Search ---\n");
    int resultado_expo = exponentialSearch(arr, tamanho, elemento);
    if (resultado_expo != -1) {
        printf("Elemento %d encontrado no índice %d.\n", elemento, resultado_expo);
    } else {
        printf("Elemento %d não encontrado.\n", elemento);
    }

    printf("\n--- Comparação de Tempo ---\n");
    double tempo_expo = medirTempo(exponentialSearch, arr, tamanho, elemento);
    printf("Tempo de execução do Exponential Search: %.8f segundos.\n", tempo_expo);

    return 0;
}