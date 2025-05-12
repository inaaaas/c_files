// Task 4: Simple File System Shell
// Project Description: Develop a simple
// shell program that allows users to interact 
//with the file system using custom commands. 
//This shell will support basic file operations
// using Unix I/O functions.

// Features to Implement:
// 1.cat [filename]: Display the contents of a file.
// 2.write [filename] [text]: Write text to a file,
//    creating the file if it doesn't exist.
// 3.cp [source] [destination]: Copy a file 
//    from source to destination.
// 4.exit: Exit the shell program.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define LEN_COMMAND 50
#define SIZE_BUF 1024

void cat(char* token) {
     FILE* file = fopen(token, "r");
     if (file == NULL) {
          perror("fopen");
          exit(1);
     }
     fseek(file, 0, SEEK_END);
     int size = ftell(file);
     fseek(file, 0, SEEK_SET);
     char* buffer = malloc((size + 1) * sizeof(char));
     fread(buffer, 1, size, file);
     buffer[size] = '\0';
     fputs(buffer, stdout);
     free(buffer);
     fclose(file);
     return;
}

void write(char* token1, char* token2) {
     FILE* file = fopen(token1, "w");
     if (file == NULL) {
          perror("fopen");
          exit(1);
     }
     fprintf(file, "%s", token2);
     fclose(file);
     return;
}

void cp(char* token1, char* token2) {
     FILE* file1 = fopen(token1, "r");
     if (file1 == NULL) {
          perror("fopen");
          exit(1);
     }
     
     FILE* file2 = fopen(token2, "w");
     if (file2 == NULL) {
          perror("fopen");
          exit(1);
     }
     fseek(file1, 0, SEEK_END);
     int size = ftell(file1);
     fseek(file1, 0, SEEK_SET);

     char* buffer = malloc((size + 1) * sizeof(char));
     fread(buffer, 1, size, file1);
     buffer[size] = '\0';
     fprintf(file2, "%s", buffer);
     fclose(file1);
     fclose(file2);
     free(buffer);
     return;
}

int main() {
    char* command = malloc(LEN_COMMAND * sizeof(char));

    while (1) {
     printf("> ");
     
     fgets(command, LEN_COMMAND, stdin);
       if (strcmp("exit\n", command) == 0) {
          break;
       }

       char* newLine = strchr(command, '\n');
       if (newLine) {
          *newLine = '\0';
       }

       char* token = strtok(command, " ");
       if (strcmp(token, "cat") == 0) {
            char* arg = strtok(NULL, " ");
            cat(arg);
       }
       else if (strcmp(token, "write") == 0) {
          char* arg1 = strtok(NULL, " ");
          char* arg2 = strtok(NULL, "");
            write(arg1, arg2);
       }
       else if (strcmp(token, "cp") == 0) {
          char* arg1 = strtok(NULL, " ");
          char* arg2 = strtok(NULL, " ");
            cp(arg1,arg2);
       }
    }
    return 0;
}