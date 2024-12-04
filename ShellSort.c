#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <locale.h>

void shellSort_Shell(int arr[], int tamanho) {
    int intervalo = tamanho / 2;  

    while (intervalo > 0) {
        for (int i = intervalo; i < tamanho; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= intervalo && arr[j - intervalo] > temp) {
                arr[j] = arr[j - intervalo];
                j -= intervalo;
            }
            arr[j] = temp;
        }
        intervalo /= 2;  
    }
}

void shellSort_Knuth(int arr[], int tamanho) {
    int intervalo = 1;
    while (intervalo < tamanho / 3) {
        intervalo = intervalo * 3 + 1;  
    }

    while (intervalo > 0) {
        for (int i = intervalo; i < tamanho; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= intervalo && arr[j - intervalo] > temp) {
                arr[j] = arr[j - intervalo];
                j -= intervalo;
            }
            arr[j] = temp;
        }
        intervalo = (intervalo - 1) / 3;  
    }
}

void shellSort_Hibbard(int arr[], int tamanho) {
    int intervalo = 1;
    while (intervalo <= tamanho / 3) {
        intervalo = 2 * intervalo + 1;  
    }

    while (intervalo > 0) {
        for (int i = intervalo; i < tamanho; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= intervalo && arr[j - intervalo] > temp) {
                arr[j] = arr[j - intervalo];
                j -= intervalo;
            }
            arr[j] = temp;
        }
        intervalo = (intervalo - 1) / 2;  
    }
}

double medirTempo(void (*func)(int[], int), int arr[], int tamanho) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL); 

    func(arr, tamanho);

    gettimeofday(&fim, NULL); 

    double tempo_decorrido = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
    return tempo_decorrido;
}

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL, "portuguese");


    int arr[] = {28, 73, 31, 76, 70, 68, 85, 1, 87, 43, 9, 67, 12, 20, 47, 78, 4, 44, 57, 67};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, tamanho);

    int arr_shell[tamanho];
    int arr_knuth[tamanho];
    int arr_hibbard[tamanho];

    for (int i = 0; i < tamanho; i++) {
        arr_shell[i] = arr[i];
        arr_knuth[i] = arr[i];
        arr_hibbard[i] = arr[i];
    }

    printf("\n--- Shell Sort (Shell) ---\n");
    double tempo_shell = medirTempo(shellSort_Shell, arr_shell, tamanho);
    printf("Tempo de execução (Shell): %.8f segundos.\n", tempo_shell);
    imprimirArray(arr_shell, tamanho);

    printf("\n--- Shell Sort (Knuth) ---\n");
    double tempo_knuth = medirTempo(shellSort_Knuth, arr_knuth, tamanho);
    printf("Tempo de execução (Knuth): %.8f segundos.\n", tempo_knuth);
    imprimirArray(arr_knuth, tamanho);

    printf("\n--- Shell Sort (Hibbard) ---\n");
    double tempo_hibbard = medirTempo(shellSort_Hibbard, arr_hibbard, tamanho);
    printf("Tempo de execução (Hibbard): %.8f segundos.\n", tempo_hibbard);
    imprimirArray(arr_hibbard, tamanho);

    return 0;
}