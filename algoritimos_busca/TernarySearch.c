#include <stdio.h>
#include <sys/time.h>
#include <locale.h>

int ternarySearch(int arr[], int esquerda, int direita, int chave) {
    if (direita >= esquerda) {
        int mid1 = esquerda + (direita - esquerda) / 3;
        int mid2 = direita - (direita - esquerda) / 3;

        if (arr[mid1] == chave)
            return mid1;
        if (arr[mid2] == chave)
            return mid2;

        if (chave < arr[mid1]) {
            return ternarySearch(arr, esquerda, mid1 - 1, chave); 
        } else if (chave > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, direita, chave); 
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, chave); 
        }
    }
    return -1; 
}

int binarySearch(int arr[], int esquerda, int direita, int chave) {
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] == chave)
            return meio;

        if (arr[meio] < chave)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }
    return -1;
}

double calcularTempo(int (*func)(int[], int, int, int), int arr[], int tamanho, int chave) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    int resultado = func(arr, 0, tamanho - 1, chave);
    gettimeofday(&fim, NULL);

    printf("Resultado: ");
    if (resultado != -1)
        printf("Chave encontrada no índice %d\n", resultado);
    else
        printf("Chave não encontrada\n");

    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
}

int main() {
	
    setlocale(LC_ALL, "portuguese");

	
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int chave;
    printf("Digite a chave a ser encontrada: ");
    scanf("%d", &chave);

    printf("\nTernary Search:\n");
    double tempoTernary = calcularTempo(ternarySearch, arr, tamanho, chave);
    printf("Tempo de execução do Ternary Search: %.6f segundos\n", tempoTernary);

    printf("\nBinary Search:\n");
    double tempoBinary = calcularTempo(binarySearch, arr, tamanho, chave);
    printf("Tempo de execução do Binary Search: %.6f segundos\n", tempoBinary);

    return 0;
}