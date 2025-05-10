//Իրականացնել ծրագիր, որը կհաշվի 
//ֆայլի բոլոր թվանշանների քանակը և կտպի էկրանին։

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Fopen");
        exit(1);
    }
    int num  = 0;
    int count = 0;
    while ((num = fgetc(file)) != EOF) {
        if (num >= 48 && num <= 57) { //isdigit(num)
            ++count;
        }
    }
    printf("Number of digits in file %d\n", count);
    fclose(file);
    return 0;
}