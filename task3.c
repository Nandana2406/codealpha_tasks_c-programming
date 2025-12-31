#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;
    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n2. Display All\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    Student s;
    printf("Enter ID, Name, GPA: ");
    scanf("%d %s %f", &s.id, s.name, &s.gpa);
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Record added successfully.\n");
}

void displayStudents() {
    FILE *fp = fopen("students.dat", "rb");
    Student s;
    if (!fp) { printf("No records found.\n"); return; }
    printf("\nID\tName\tGPA\n-------------------\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.gpa);
    }
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    int id, found = 0;
    Student s;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Found: %s, GPA: %.2f\n", s.name, s.gpa);
            found = 1; break;
        }
    }
    if (!found) printf("Record not found.\n");
    fclose(fp);
}

void updateStudent() {
    FILE *fp = fopen("students.dat", "rb+");
    int id, found = 0;
    Student s;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Enter new Name and GPA: ");
            scanf("%s %f", s.name, &s.gpa);
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            found = 1; break;
        }
    }
    fclose(fp);
    if (found) printf("Record updated.\n"); else printf("Not found.\n");
}

void deleteStudent() {
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    int id, found = 0;
    Student s;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) found = 1;
        else fwrite(&s, sizeof(Student), 1, temp);
    }
    fclose(fp); fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");
    if (found) printf("Record deleted.\n"); else printf("Not found.\n");
}
