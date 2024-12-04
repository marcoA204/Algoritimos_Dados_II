#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimirArray(float arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void insertionSort(float arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        float chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

void bucketSortFloat(float arr[], int tamanho) {
    int numBaldes = tamanho;
    float **baldes = (float **)malloc(numBaldes * sizeof(float *));
    int *contagem = (int *)calloc(numBaldes, sizeof(int));

    for (int i = 0; i < numBaldes; i++) {
        baldes[i] = (float *)malloc(tamanho * sizeof(float));
    }

    for (int i = 0; i < tamanho; i++) {
        int idx = (int)(arr[i] * numBaldes); 
        baldes[idx][contagem[idx]++] = arr[i];
    }

    int pos = 0;
    for (int i = 0; i < numBaldes; i++) {
        if (contagem[i] > 0) {
            insertionSort(baldes[i], contagem[i]);
            for (int j = 0; j < contagem[i]; j++) {
                arr[pos++] = baldes[i][j];
            }
        }
    }

    for (int i = 0; i < numBaldes; i++) {
        free(baldes[i]);
    }
    free(baldes);
    free(contagem);
}

void bucketSortInteiros(int arr[], int tamanho) {
    int max = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int numBaldes = tamanho;
    int **baldes = (int **)malloc(numBaldes * sizeof(int *));
    int *contagem = (int *)calloc(numBaldes, sizeof(int));

    for (int i = 0; i < numBaldes; i++) {
        baldes[i] = (int *)malloc(tamanho * sizeof(int));
    }

    for (int i = 0; i < tamanho; i++) {
        int idx = (arr[i] * numBaldes) / (max + 1); 
        baldes[idx][contagem[idx]++] = arr[i];
    }

    int pos = 0;
    for (int i = 0; i < numBaldes; i++) {
        if (contagem[i] > 0) {
            insertionSort((float *)baldes[i], contagem[i]);
            for (int j = 0; j < contagem[i]; j++) {
                arr[pos++] = baldes[i][j];
            }
        }
    }

    for (int i = 0; i < numBaldes; i++) {
        free(baldes[i]);
    }
    free(baldes);
    free(contagem);
}

int main() {
	
    setlocale(LC_ALL, "portuguese");

	
    float arrFloat[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int tamanhoFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);
    
    printf("\n--- teste com numeros em pontos flutuantes---\n");
    printf("Array original (float): ");
    imprimirArray(arrFloat, tamanhoFloat);

    bucketSortFloat(arrFloat, tamanhoFloat);

    printf("Array ordenado (float): ");
    imprimirArray(arrFloat, tamanhoFloat);

    int arrInt[] = {54, 21, 90, 33, 48, 72, 11, 5, 17, 64};
    int tamanhoInt = sizeof(arrInt) / sizeof(arrInt[0]);

    printf("\n--- teste com numeros inteiros---\n");
    printf("\nArray original (inteiros): ");
    for (int i = 0; i < tamanhoInt; i++) {
        printf("%d ", arrInt[i]);
    }
    printf("\n");

    bucketSortInteiros(arrInt, tamanhoInt);

    printf("Array ordenado (inteiros): ");
    for (int i = 0; i < tamanhoInt; i++) {
        printf("%d ", arrInt[i]);
    }
    printf("\n");

    return 0;
}
