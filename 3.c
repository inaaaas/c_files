//Գրել ծրագիր, որը կկարդա արդեն իսկ ստեղծված ֆայլի 
//առաջին թիվը և կտպի էկրանին։

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {

    FILE* file = fopen("file3.txt", "r");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }
    int number;
   if (fscanf(file, "%d", &number) == 1) {
        printf("First number in file: %d\n", number);
   }
   else {
        printf("No number in file\n");
   }
   fclose(file);
   return 0;
}