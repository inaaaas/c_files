// Task 2: Basic File Editor
// Task: Create a program that acts as a simple 
//text editor. It should:
// Open "my_info.txt" (or a file of your choice).
// Read and display the contents.
// Let the user edit the text.
// Write the changes back to the file.
// Challenges:
// How will you handle overwriting vs. appending?

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZE 50 
#define BUF_SIZE 1024

int main() {
    char* f = malloc(SIZE * sizeof(char));
    printf("Enter the name of file: ");
    scanf("%s", f);

    FILE* file_r = fopen(f, "r");
    if (file_r == NULL) {
        perror("fopem");
        exit(1);
    }

    printf("FILE OPENED\n");
    fseek(file_r, 0, SEEK_END);
    long size = ftell(file_r);
    fseek(file_r, 0, SEEK_SET);

    char* buffer_r = malloc((size + 1) * sizeof(char));
    fread(buffer_r, 1, size, file_r);
    buffer_r[size] = '\0';
    printf("CURRENT CONTENT\n");
    fputs(buffer_r, stdout);
    fclose(file_r);
    free(buffer_r);

    int choice;
    printf("What do you want?\n");
    printf("0 - Append\n1 - Override\n");
    scanf("%d", &choice);
    getchar();

    FILE* file_w = NULL;
    if (choice == 0) {
        file_w = fopen(f, "a");
        
    }
    else {
        file_w = fopen(f, "w");
        
    }

    if (file_w == NULL) {
        perror("fopen");
        exit(1);
    }

    char* buffer_w = malloc(BUF_SIZE * sizeof(char));
    printf("Enter the text:\n");
    fgets(buffer_w, BUF_SIZE, stdin);
    fputs(buffer_w, file_w);

    printf("WRITTEN IN FILE\n");
    fclose(file_w);
    free(buffer_w);
    return 0;

}