#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void selectionSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
        printf("Iteração %d: ", i + 1);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

double medirTempo(void (*func)(int[], int), int arr[], int tamanho) {
    clock_t inicio = clock();
    func(arr, tamanho);
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC; 
}

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
	
    setlocale(LC_ALL, "portuguese");

	
    int arr_pequeno[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho_pequeno = sizeof(arr_pequeno) / sizeof(arr_pequeno[0]);

    printf("Array original (pequeno): ");
    imprimirArray(arr_pequeno, tamanho_pequeno);
    printf("\n");

    printf("Ordenando o array pequeno...\n");
    double tempo_pequeno = medirTempo(selectionSort, arr_pequeno, tamanho_pequeno);
    printf("Tempo de execução para o array pequeno: %.8f segundos.\n\n", tempo_pequeno);

    int arr_medio[] = {64, 34, 25, 12, 22, 11, 90, 41, 32, 56, 87, 53};
    int tamanho_medio = sizeof(arr_medio) / sizeof(arr_medio[0]);

    printf("Array original (médio): ");
    imprimirArray(arr_medio, tamanho_medio);
    printf("\n");

    printf("Ordenando o array médio...\n");
    double tempo_medio = medirTempo(selectionSort, arr_medio, tamanho_medio);
    printf("Tempo de execução para o array médio: %.8f segundos.\n\n", tempo_medio);

    int arr_grande[80];
    for (int i = 0; i < 80; i++) {
        arr_grande[i] = rand() % 100;
    }
    int tamanho_grande = sizeof(arr_grande) / sizeof(arr_grande[0]);

    printf("Array original (grande): ");
    printf("%d ...\n", arr_grande[0]);

    printf("Ordenando o array grande...\n");
    double tempo_grande = medirTempo(selectionSort, arr_grande, tamanho_grande);
    printf("Tempo de execução para o array grande: %.8f segundos.\n", tempo_grande);

    return 0;
}