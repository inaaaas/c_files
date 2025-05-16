//Գրել ծրագիր, որը կտպի էկրանին ֆայլի մասին ինֆորմացիա.
//Ֆայլի չափը՝ բայթերով
//Ֆայլի մեջ տողերի քանակը
//Ֆայլի մեջ բառերի քանակը

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }
    
    int ch = 0;
    int byteCount = 0;
    int lineCount = 0;
    int wordCount = 0;
    int wordStart = 0;

    int prev = 0;
    while ((ch = fgetc(file)) != EOF) {
        ++byteCount;
        if (ch == '\n') {
            ++lineCount;
        }
        if (isspace(ch)) {
            wordStart = 0;
        }
        else if (wordStart == 0) {
            ++wordCount;
            wordStart = 1;
        }
        prev = ch;
    }
    
    if (byteCount > 0 && prev != '\n') {
        ++lineCount;
    }
    
    printf("Bytes count : %d\nLine count : %d\nWord count : %d", byteCount, lineCount, wordCount);
    fclose(file);
    return 0;
}
