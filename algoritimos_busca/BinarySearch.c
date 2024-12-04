#include <stdio.h>
#include <locale.h>

int binarySearch(int arr[], int tamanho, int elemento){
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


int main(){
	
	setlocale(LC_ALL, "portuguese");
	
	int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int tamanho = sizeof(arr) / sizeof(arr[0]);
	int elemento;
	
	printf ("digite o elemento a ser buscado: ");
	scanf("%d",&elemento);
	
	int resultado = binarySearch(arr, tamanho, elemento);
	
	if (resultado != -1)
	{
		printf("Elemento %d  encontrado no indice %d.\n", elemento, resultado);
	}else
		{
		printf("Elemento %d não encontrado na lista.\n", elemento);
		}
	
	
	return 0;
}