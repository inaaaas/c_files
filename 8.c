// Իրականացնել ծրագիր, 
//որը բացում է text.txt ֆայլ, և հաշվում ֆայլում 
//յուրաքանչյուր բառի առկայության քանակը, 
//այնուհետև ստացված արդյունքը տեղադրում է 
//statistics.txt ֆայլում։ Օրինակ՝
// Text.txt 
// This is a test. This is only a test.

// Statistics.txt
// this: 2 
// is: 2 
// a: 2 
// test: 2 
// only: 1

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define N 50

int main() {
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }
    FILE* file2 = fopen("statistics.txt", "w");
    if (file2 == NULL) {
        perror("fopen");
        exit(1);
    }
    char string[N];
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = malloc((size + 1) * sizeof(char));
    fread(buffer, size, 1, file);
    buffer[size] = '\n';
    char* token = strtok(buffer, " ");
    while(token != NULL) {

        token = strtok(NULL, " ");
    } 
}