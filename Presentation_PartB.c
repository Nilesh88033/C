#include <stdio.h>
#include <string.h>


//Build a Student information system



// Maximum number of students in the database
#define MAX_STUDENTS 50

// Structure to store student information
struct Student {
    char name[50];
    int regNumber;
    char course[50];
    int phone;
    char email[50];
};

// Function to add a new student to the database
void addStudent(struct Student students[], int *count) {
    if (*count < MAX_STUDENTS) {
        printf("Enter student name: ");
        scanf("%s", students[*count].name);

        printf("Enter student registration number: ");
        scanf("%d", &students[*count].regNumber);

        printf("Enter student enrolled course: ");
        scanf("%s", students[*count].course);

        printf("Enter student phone number: ");
        scanf("%d", &students[*count].phone);

        printf("Enter student email: ");
        scanf("%s", students[*count].email);

        (*count)++;
        printf("Student added successfully!\n");
    } else {
        printf("Database is full. Cannot add more students.\n");
    }
}

// Function to display all students in the database
void displayStudents(const struct Student students[], int count) {
    if (count > 0) {
        printf("\n----- Student Database -----\n");
        printf("%-20s %-20s %-20s %-15s %-20s\n", "Name", "Reg Number", "Course", "Phone", "Email");
        for (int i = 0; i < count; ++i) {
            printf("%-20s %-20d %-20s %-15d %-20s\n", students[i].name, students[i].regNumber, students[i].course, students[i].phone, students[i].email);
        }
    } else {
        printf("No students in the database.\n");
    }
}

// Function to search for a student by registration number
void searchStudent(const struct Student students[], int count) {
    int regNumber;
    printf("Enter the registration number to search: ");
    scanf("%d", &regNumber);

    for (int i = 0; i < count; ++i) {
        if (students[i].regNumber == regNumber) {
            printf("Student found!\n");
            printf("Name: %s\nRegistration Number: %d\nEnrolled Course: %s\nPhone: %d\nEmail: %s\n", students[i].name, students[i].regNumber, students[i].course, students[i].phone, students[i].email);
            return;
        }
    }

    printf("Student with registration number %d not found.\n", regNumber);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        // Display menu
        printf("\n----- Menu -----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
