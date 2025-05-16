//Գրել ծրագիր, որը կստեղծի ֆայլ և օգտագործողի
// կողմից մուտքագրված թվանշանները կլցնի ֆայլի մեջ։

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file2.txt", "w");
    if (file == NULL) {
        perror(fopen);
        exit(1);
    }
    int num = 0;
    printf("Enter the numbers , which you want include to file \nEnter Q ,if you want to stop\n");

    while (scanf("%d", &num) == 1) {
        fprintf(file, "%d ", num);
    }
    fclose(file);
    return 0;
}
