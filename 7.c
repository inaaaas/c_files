//Իրականացնել ծրագիր, որը մուտքագրում է թիվ, 
//հաշվում 1-ից մինչև այդ մուտքագրված թվի ֆակտորիալները
// և տեղադրում factorials.txt ֆայլում, անջատելով ստորակետներով։ 
// Օրինակ՝
// input - 5
// Factorials.txt - 1, 2, 6, 24, 120
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int factorial(int num) {
    if (num <= 1) {
        return 1;
    }
    return num * factorial(num - 1);
}
int main() {
    FILE* file = fopen("factorial.txt", "w");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }
    int num = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; ++i) {
        fprintf(file, "%d", factorial(i));
        if (i < num) {
            fprintf(file, ", ");
        }
    }
    fclose(file);
    return 0;
}