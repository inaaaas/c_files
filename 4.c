//Գրել ծրագիր, որը կհաշվի ֆայլում եղած թվերի 
//միջին թվաբանականը և կավելացնի ֆայլի վերջից։

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r+");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }
    int sum = 0;
    int number = 0;
    int count = 0;
    while (fscanf(file, "%d", &number) == 1) {
        sum += number;
        ++count;
    }
    double average = (double)sum / count;
    fprintf(file, "\nAverage is %.2f", average);
    fclose(file);
    return 0;
}
