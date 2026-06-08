#ifndef STUDENT_H
#define STUDENT_H

// 🔹 Structure Definition
struct Student {
    int id;
    char name[50];
    float marks;
};

// 🔹 Function Declarations
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();

#endif