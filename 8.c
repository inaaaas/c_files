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
#include <ctype.h>
#include <string.h>

#define N 50
#define MAX_WORD_COUNT 200

typedef struct {
    char word[N];
    int count;
    int included;
} Tokens;

void toLower(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main() {
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("fopen");
        fclose(file);
        exit(1);
    }
    FILE* file2 = fopen("statistics.txt", "w");
    if (file2 == NULL) {
        perror("fopen");
        fclose(file2);
        exit(1);
    }
    
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = malloc((size + 1) * sizeof(char));
    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    char* token = strtok(buffer, " \n\t");
    Tokens tokens[MAX_WORD_COUNT] = {0};

    int i = 0;
    int count_of_words = 0;
   
    while(token != NULL) {
        int len = strlen(token);
        if (len > 0 && ispunct(token[len - 1])) {
            token[len - 1] = '\0';
        }
            toLower(token);
            strcpy(tokens[i].word, token);
            tokens[i].count = 1;
            ++i;
            ++count_of_words;
            token = strtok(NULL, " \n\t");
    } 
    for (int j = 0; j < count_of_words - 1; ++j) {
        if (tokens[j].included != 0) {
            continue;
        }
        for (int k = j + 1; k < count_of_words; ++k) {
            if (strcmp(tokens[j].word, tokens[k].word) == 0) {
                tokens[j].count++;
                tokens[k].included ++;
            }
        }
    }
    for (int j = 0; j < count_of_words; ++j) {
        if (tokens[j].included == 0) {
            fprintf(file2, "%s: %d\n",tokens[j].word, tokens[j].count);
        }
    }
    fclose(file);
    fclose(file2);
    free(buffer);
    return 0;
}
