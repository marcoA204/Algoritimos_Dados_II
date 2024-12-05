#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arr[i]; j++) {
            printf("█"); 
        }
        printf("\n");
    }
    printf("\n");
    sleep(1); 
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(&arr[i], &arr[minIdx]);
        displayArray(arr, size); 
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right, int size) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        merge(arr, left, mid, right);

        displayArray(arr, size); 
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int size) {
    if (low < high) {
        int pi = partition(arr, low, high);

        displayArray(arr, size); 

        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

int main() {
    setlocale (LC_ALL, "portuguese");
    int arr[] = {7, 3, 8, 2, 5, 1, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Visualização do Selection Sort:\n");
    selectionSort(arr, size);

    int arr2[] = {7, 3, 8, 2, 5, 1, 6, 4};
    printf("\nVisualização do Merge Sort:\n");
    mergeSort(arr2, 0, size - 1, size);

    int arr3[] = {7, 3, 8, 2, 5, 1, 6, 4};
    printf("\nVisualização do Quick Sort:\n");
    quickSort(arr3, 0, size - 1, size);

    return 0;
}
