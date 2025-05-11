// Task 3: Basic Symbol Counter
// Develop a C program that counts the occurrence 
//of each symbol (character) in a text file and outputs the results.
// Instructions:
// Read Input: Your program should accept a single command-line 
//argument specifying the path to the text file to be analyzed.
// Process File:
// Count the occurrence of each ASCII character (considering
// characters from 0 to 127).
// Output Results:
// Display the frequency of each character that appears in 
//the file. For characters that do not appear, no output is needed.
// Format the output as follows: Character 'a': 20 occurrences
// Error Handling: Ensure your program gracefully handles
// common error scenarios such as missing files or access permissions.
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#define BUF_SIZE 128
#define SIZE 50

int main(int argc, char* argv[]) {
    // char* f = malloc(SIZE * sizeof(char));
    // printf("Enter the name of file : ");
    // scanf("%s", f);

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }

    int chars_count[BUF_SIZE] = {0};
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        ++chars_count[ch];
    }
    for (int i = 0; i < BUF_SIZE; ++i) {
        if (chars_count[i] > 0) {
            if(isprint(i)) {
                printf("Character '%c' : %d occurences\n", i, chars_count[i]);
            }        
            else if (i == '\n') {
                printf("Character '\\n' : %d occurences\n", chars_count[i]);
            }
            else if (i == '\t') {
                printf("Character '\\t' : %d occurences\n", chars_count[i]);
            }
            else if (i == '\r') {
                printf("Character '\\r' : %d occurences\n", chars_count[i]);
            }
        }
    }
    fclose(file);
    return 0;
}