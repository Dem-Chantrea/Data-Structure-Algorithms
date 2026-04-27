#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    char course[50];
    float score;
} Student;


typedef struct Node {
    Student data;
    struct Node* next;
} Node;

// Function prototypes
Node* InputStudent(Node* head);
Node* RemoveStudent(Node* head, int id);
Node* updateStudent(Node* head, int id);
Node* searchStudent(Node* head, int id);
void displayStudents(Node* head);
Node* ClearList(Node* head);
void input(Student* stu);
void output(Student stu);


int main() {
    Node* head = NULL;
    int choice, id, n;
    int i;

    

    while (1) {
        printf("\n----------------------------------->> Student Management System <<----------------------------------\n");
        printf("\n\t\t 1. Insert Student");
        printf("\n\t\t 2. Delete Student");
        printf("\n\t\t 3. Update Student");
        printf("\n\t\t 4. Search Student");
        printf("\n\t\t 5. Display All Students");
        printf("\n\t\t 6. Clear All Students");
        printf("\n\t\t 7. Exit\n");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        system("color 1");

        switch (choice) {

        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                head = InputStudent(head);
            }
            break;

        case 2:
            system("color 5");
            printf("Enter Student ID to delete: ");
            scanf("%d", &id);
            head = RemoveStudent(head, id);
            break;

        case 3:
            system("color 3");
            printf("Enter Student ID to update: ");
            scanf("%d", &id);
            head = updateStudent(head, id);
            break;

        case 4: {
            system("color 2");
            printf("Enter Student ID to search: ");
            scanf("%d", &id);

            Node* found = searchStudent(head, id);

            if (found) {
                printf("Student found:\n");
                printf("\n\tID\tName\tCourse\tScore\n");
                output(found->data);
            } else {
                printf("Student not found.\n");
            }
            break;
        }

        case 5:
            system("color 4");
            printf("\nStudent List:\n");
            printf("\n\tID\tName\tCourse\tScore\n");
            displayStudents(head);
            break;

        case 6:
            system("color 6");
            head = ClearList(head);
            printf("All students have been cleared.\n");
            break;

        case 7:
            ClearList(head);
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

//  INSERT STUDENT 
Node* InputStudent(Node* head) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if (!new_node) {
        printf("Memory allocation error\n");
        return head;
    }

    input(&new_node->data);

    new_node->next = head;
    head = new_node;

    printf("Student added successfully!\n");
    return head;
}

// DELETE STUDENT 
Node* RemoveStudent(Node* head, int id) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return head;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student deleted successfully!\n");
    return head;
}

//UPDATE STUDENT 
Node* updateStudent(Node* head, int id) {
    Node* temp = head;

    while (temp != NULL && temp->data.id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return head;
    }

    input(&temp->data);

    printf("Student updated successfully!\n");
    return head;
}

// SEARCH STUDENT 
Node* searchStudent(Node* head, int id) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data.id == id) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

// DISPLAY STUDENTS 
void displayStudents(Node* head) {
    Node* temp = head;

    if (temp == NULL) {
        printf("No students to display.\n");
        return;
    }

    while (temp != NULL) {
        output(temp->data);
        temp = temp->next;
    }
}

//CLEAR LIST 
Node* ClearList(Node* head) {
    Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return NULL;
}

//INPUT STUDENT 
void input(Student* stu) {
    printf("Enter Student ID: ");
    scanf("%d", &stu->id);
    getchar();

    printf("Enter Student Name: ");
    fgets(stu->name, sizeof(stu->name), stdin);
    stu->name[strcspn(stu->name, "\n")] = '\0';

    printf("Enter Student Course: ");
    fgets(stu->course, sizeof(stu->course), stdin);
    stu->course[strcspn(stu->course, "\n")] = '\0';

    printf("Enter Student Score: ");
    scanf("%f", &stu->score);
    getchar();
}

//OUTPUT STUDENT 
void output(Student stu) {
    printf("\n\t%d\t%s\t%s\t%.2f\n",
           stu.id, stu.name, stu.course, stu.score);
}
