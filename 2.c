//Գրել ծրագիր, որը կստեղծի ֆայլ և օգտագործողի
// կողմից մուտքագրված թվանշանները կլցնի ֆայլի մեջ։

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file2.txt", "w");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }
    int num = 0;
    printf("Enter the numbers , which you want include to file \nEnter Q ,if you want to stop\n");

    // while (scanf("%d", &num) != 0) {
    //     fprintf(file, "%d ", num);
    // }
    char buf[16];
    while (scanf("%15s", buf)==1 && strcmp(buf,"Q")!=0) {
      int d = atoi(buf);
      fprintf(file,"%d ", d);
    }
    fclose(file);
    return 0;
}
