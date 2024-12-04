#include <stdio.h>
#include <locale.h>
int interpolationSearch(int arr[], int tamanho, int elemento) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim && elemento >= arr[inicio] && elemento <= arr[fim]) {
        if (inicio == fim) {
            if (arr[inicio] == elemento) return inicio;
            return -1;
        }

        int pos = inicio + ((double)(fim - inicio) / (arr[fim] - arr[inicio])) * (elemento - arr[inicio]);

        if (arr[pos] == elemento) {
            return pos;
        }

        if (arr[pos] < elemento) {
            inicio = pos + 1;
        } else {
            fim = pos - 1; 
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

int main() {
	
		setlocale(LC_ALL, "portuguese");

    int lista_uniforme[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int lista_nao_uniforme[] = {20, 64, 12, 50, 58, 80, 59, 100, 68, 76};
    int tamanho_uniforme = sizeof(lista_uniforme) / sizeof(lista_uniforme[0]);
    int tamanho_nao_uniforme = sizeof(lista_nao_uniforme) / sizeof(lista_nao_uniforme[0]);

    int elemento;

    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &elemento);

    // Testando Interpolation Search
    printf("\n--- Interpolation Search ---\n");
    int resultado_interp_uniforme = interpolationSearch(lista_uniforme, tamanho_uniforme, elemento);
    int resultado_interp_nao_uniforme = interpolationSearch(lista_nao_uniforme, tamanho_nao_uniforme, elemento);

    printf("Resultado em lista uniforme: %d\n", resultado_interp_uniforme);
    printf("Resultado em lista não uniforme: %d\n", resultado_interp_nao_uniforme);

    // Testando Binary Search
    printf("\n--- Binary Search ---\n");
    int resultado_bin_uniforme = binarySearch(lista_uniforme, tamanho_uniforme, elemento);
    int resultado_bin_nao_uniforme = binarySearch(lista_nao_uniforme, tamanho_nao_uniforme, elemento);

    printf("Resultado em lista uniforme: %d\n", resultado_bin_uniforme);
    printf("Resultado em lista não uniforme: %d\n", resultado_bin_nao_uniforme);

    return 0;
}