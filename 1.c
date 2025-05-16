//Գրել ծրագիր, որը կստեղծի ֆայլ և ֆայլի մեջ կլցնի 1-ից 15-ը 
//միջակայքում եղած բոլոր պարզ թվերը։

#include <stdio.h>
#include <fcntl.h>

int main() {
    FILE* file = fopen("file.txt", "w");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }
    int flag = 0;
    for (int i = 1; i <= 15; ++i) {
        for (int j = 2; j <= i/2; ++j) {
            if ( i % j == 0) {
                flag = 1;
                break;  
            }
        }
        if (flag == 0) {
            fprintf(file, "%d\n", i);
        }
        flag = 0;
    }
    fclose(file);
    return 0;
}
