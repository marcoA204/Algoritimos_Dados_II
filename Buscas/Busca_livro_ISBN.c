#include <stdio.h>
#include <string.h>
#include <locale.h>
typedef struct {
    char title[100];
    char author[100];
    char isbn[20];
} Book;

int binarySearch(Book books[], int size, const char *isbn) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        int res = strcmp(books[mid].isbn, isbn);
        
        if (res == 0)
            return mid; 
        if (res < 0)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    
    return -1; 
}

int main() {
	setlocale (LC_ALL, "portuguese");
    Book books[] = {
        {"The Catcher in the Rye", "J.D. Salinger", "9780316769488"},
        {"1984", "George Orwell", "9780451524935"},
        {"To Kill a Mockingbird", "Harper Lee", "9780061120084"},
        {"Pride and Prejudice", "Jane Austen", "9780141439518"},
        {"The Great Gatsby", "F. Scott Fitzgerald", "9780743273565"}
    };
    
    int size = sizeof(books) / sizeof(books[0]);
    
    char searchISBN[] = "9780061120084";
    
    int result = binarySearch(books, size, searchISBN);
    
    if (result != -1) {
        printf("Livro encontrado:\n");
        printf("Título: %s\n", books[result].title);
        printf("Autor: %s\n", books[result].author);
        printf("ISBN: %s\n", books[result].isbn);
    } else {
        printf("Livro com ISBN %s não encontrado.\n", searchISBN);
    }
    
    return 0;
}
