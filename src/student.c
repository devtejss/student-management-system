#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"

#define FILE_PATH "data/students.dat"

// 🔹 Add Student
void addStudent() {
    FILE *fp = fopen(FILE_PATH, "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("✅ Student added successfully!\n");
}

// 🔹 View All Students
void viewStudents() {
    FILE *fp = fopen(FILE_PATH, "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    struct Student s;

    printf("\n--- Student List ---\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("ID: %d | Name: %s | Marks: %.2f\n",
               s.id, s.name, s.marks);
    }

    fclose(fp);
}

// 🔹 Search Student by ID
void searchStudent() {
    FILE *fp = fopen(FILE_PATH, "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    struct Student s;
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("\n🎯 Student Found:\n");
            printf("ID: %d\nName: %s\nMarks: %.2f\n",
                   s.id, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("❌ Student not found!\n");
    }

    fclose(fp);
}

// 🔹 Delete Student by ID
void deleteStudent() {
    FILE *fp = fopen(FILE_PATH, "rb");
    FILE *temp = fopen("data/temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_PATH);
    rename("data/temp.dat", FILE_PATH);

    if (found)
        printf("🗑️ Student deleted successfully!\n");
    else
        printf("❌ Student not found!\n");
}