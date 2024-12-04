#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int jumpSearch(int arr[], int tamanho, int elemento) {
    int salto = (int)sqrt(tamanho); // Tamanho ideal do salto
    int prev = 0;

while (arr[(int)fmin(salto, tamanho) - 1] < elemento) {
    prev = salto;
    salto += (int)sqrt(tamanho);
    if (prev >= tamanho) {
        return -1; // Elemento não encontrado
    }
}

    for (int i = prev; i < fmin(salto, tamanho); i++) {
        if (arr[i] == elemento) {
            return i; 
        }
    }

    return -1; 
}

int binarySearch(int arr[], int tamanho, int elemento) {
    int inicio = 0, fim = tamanho - 1;

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

double medirTempo(int (*func)(int[], int, int), int arr[], int tamanho, int elemento) {
    clock_t inicio = clock();
    func(arr, tamanho, elemento);
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

int main() {
	
	setlocale(LC_ALL, "portuguese");
	
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int elemento;

    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &elemento);

    printf("\n--- Jump Search ---\n");
    int resultado_jump = jumpSearch(arr, tamanho, elemento);
    if (resultado_jump != -1) {
        printf("Elemento %d encontrado no índice %d.\n", elemento, resultado_jump);
    } else {
        printf("Elemento %d não encontrado.\n", elemento);
    }

    printf("\n--- Binary Search ---\n");
    int resultado_bin = binarySearch(arr, tamanho, elemento);
    if (resultado_bin != -1) {
        printf("Elemento %d encontrado no índice %d.\n", elemento, resultado_bin);
    } else {
        printf("Elemento %d não encontrado.\n", elemento);
    }

    printf("\n--- Comparação de Tempo ---\n");
    double tempo_jump = medirTempo(jumpSearch, arr, tamanho, elemento);
    double tempo_bin = medirTempo(binarySearch, arr, tamanho, elemento);

    printf("Tempo de execução do Jump Search: %.8f segundos.\n", tempo_jump);
    printf("Tempo de execução do Binary Search: %.8f segundos.\n", tempo_bin);

    return 0;
}