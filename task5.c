//Simple Data Storage System
#include <stdio.h>
#include <fcntl.h>

typedef struct {
     char name[50];
     int id;
     float grades[5]; // Store up to 5 grades
}student;

FILE* file;

void add() {
    student student1; 

    printf("Enter student name: ");
    scanf("%s", student1.name);

    printf("Enter student ID: ");
    scanf("%d", &student1.id);

    printf("Enter student 5 grades: ");
    for (int i = 0; i < 5; ++i) {
        scanf("%f", &student1.grades[i]);
    }

    fprintf(file, "%s", student1.name);
    
    fprintf(file, ",%d", student1.id);
    
    for(int i = 0; i < 5; ++i) {
        fprintf(file, ",%.2f", student1.grades[i]);
    }

    fprintf(file, "\n");

    return;
}

void recordByName() {
    

}

void recordByID() {


}

void update() {


}

void delete() {

    
}

void sort() {


}

int main() {
    printf("CHOOSE THE OPERATION\n");
    printf("1. Add a new record\n");
    printf("2. Search for a record by name\n");
    printf("3. Search for a record by ID\n");
    printf("4. Update a record\n");
    printf("5. Delete a record\n");
    printf("6. Sort records\n");
    printf("0. Exit\n");

    int choice = 0;
    scanf("%d", &choice);

    file = fopen("data.txt", "r+");

    switch(choice) {
        case 1:
            add();
            break;
        case 2:
            recordByName();
            break;
        case 3:
            recordByID();
            break;
        case 4:
            update();
            break;
        case 5:
            delete();
            break;
        case 6:
            sort();
    }

    fclose(file);
    return 0;
}