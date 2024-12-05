#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char name[50];
    int grade;
} Student;

void printStudents(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s - %d\n", students[i].name, students[i].grade);
    }
}

void bubbleSort(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (students[j].grade > students[j + 1].grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void selectionSort(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (students[j].grade < students[minIndex].grade) {
                minIndex = j;
            }
        }
        Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
}

int main() {
	setlocale (LC_ALL, "portuguese");
    Student students[] = {
        {"Alice", 85},
        {"Bob", 75},
        {"Charlie", 85},
        {"David", 90},
        {"Eva", 75}
    };
    
    int size = sizeof(students) / sizeof(students[0]);
    
    printf("Antes da ordenação (Bubble Sort - Estável):\n");
    printStudents(students, size);
    
    bubbleSort(students, size);
    printf("\nApós a ordenação (Bubble Sort - Estável):\n");
    printStudents(students, size);
    
    Student students2[] = {
        {"Alice", 85},
        {"Bob", 75},
        {"Charlie", 85},
        {"David", 90},
        {"Eva", 75}
    };
    
    printf("\nAntes da ordenação (Selection Sort - Instável):\n");
    printStudents(students2, size);
    
    selectionSort(students2, size);
    printf("\nApós a ordenação (Selection Sort - Instável):\n");
    printStudents(students2, size);
    
    return 0;
}
