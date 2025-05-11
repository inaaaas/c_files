// Task 1: Custom File Copy Utility
// Objective: Develop a program to copy the contents of one file to another using system calls.
// Instructions:
// Your program should accept two arguments: the source file path and the destination file path.
// Provide error handling for common issues like missing files or access permissions.
// Advanced Challenge: Implement a progress bar that updates in real time as the file is being copied.


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define SIZE 50 
#define BUF_SIZE 11

int main() {
    char* f1 = malloc(SIZE * sizeof(char));
    char* f2 = malloc(SIZE * sizeof(char));
    if (f1 == NULL || f2 == NULL) {
        perror("Malloc");
        exit(1);
    }
    printf("Enter the name of first file: ");
    scanf("%49s",f1);
    printf("Enter the name of second file: ");
    scanf("%49s",f2);

    FILE* file1 = fopen(f1, "r");
    FILE* file2 = fopen(f2, "w");
    if (file1 == NULL) {
        perror("fopen");
        free(f1);
        free(f2);
        exit(1);
    }
    if (file2 == NULL) {
        perror("fopen");
        fclose(file2);
        free(f1);
        free(f2);
        exit(1);
    }

    fseek(file1, 0, SEEK_END);
    int size = ftell(file1);
    fseek(file1, 0, SEEK_SET);

    char buffer[BUF_SIZE];
    int count_of_copied = 0;
    int bytes_count;

     while ((bytes_count = fread(buffer, 1, BUF_SIZE - 1, file1)) > 0) {
        fwrite(buffer, 1, bytes_count, file2);
        count_of_copied += bytes_count;
        printf("\nIn process ");
        printf("%.0f %%", ((float)count_of_copied / size) * 100);
     }

    printf("\nFile copied\n");
    fclose(file1);
    fclose(file2);
    free(f1);
    free(f2);
    return 0;
}
