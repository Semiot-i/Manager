#include "student_editor.h"
#include <stdio.h>

void studentEditorShowAddForm(void) {
    printf("\n--- Add Student ---\n");
}

void studentEditorGetStudentInfo(int* id, int* roomNum, char* name, char* sex, 
                                  char* stuClass, char* birth, char* home, int* phone) {
    printf("Enter ID: ");
    scanf("%d", id);
    printf("Enter Room Number: ");
    scanf("%d", roomNum);
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Sex: ");
    scanf("%s", sex);
    printf("Enter Class: ");
    scanf("%s", stuClass);
    printf("Enter Birth (YYYY-MM-DD): ");
    scanf("%s", birth);
    printf("Enter Home Address: ");
    scanf("%s", home);
    printf("Enter Phone: ");
    scanf("%d", phone);
}

void studentEditorHandleAdd(StudentNode** head_ptr) {
    int id, roomNum, phone;
    char name[50], sex[10], stuClass[50], birth[20], home[100];
    
    studentEditorShowAddForm();
    studentEditorGetStudentInfo(&id, &roomNum, name, sex, stuClass, birth, home, &phone);
    
    int result = addStudent(head_ptr, id, roomNum, name, sex, stuClass, birth, home, phone);
    if (result == 1) {
        printf("Student added successfully!\n");
    } else {
        printf("Failed to add student!\n");
    }
}

void studentEditorHandleDelete(StudentNode** head_ptr) {
    int choice, pos, target_id;
    
    printf("\n--- Delete Student ---\n");
    printf("1. Delete by Position\n");
    printf("2. Delete by ID\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter position: ");
        scanf("%d", &pos);
        int result = deleteStudentByPos(head_ptr, pos);
        if (result == 1) {
            printf("Student deleted successfully!\n");
        } else {
            printf("Failed to delete student!\n");
        }
    } else if (choice == 2) {
        printf("Enter student ID: ");
        scanf("%d", &target_id);
        int result = deleteStudentById(head_ptr, target_id);
        if (result == 1) {
            printf("Student deleted successfully!\n");
        } else {
            printf("Failed to delete student!\n");
        }
    }
}

static void showModifyMenu(void) {
    printf("\n--- Modify Student ---\n");
    printf("1. Modify by Position\n");
    printf("2. Modify by ID\n");
    printf("Enter choice: ");
}

static void modifyByPosition(StudentNode* head_ptr) {
    int pos, choice;
    printf("Enter position: ");
    scanf("%d", &pos);
    
    StudentNode* node = queryStudentByPos(head_ptr, pos);
    if (!node) {
        printf("Student not found!\n");
        return;
    }
    
    printf("\nCurrent Info:\n");
    printStudentNode(node);
    
    printf("\nSelect field to modify:\n");
    printf("1. ID\n");
    printf("2. Room Number\n");
    printf("3. Name\n");
    printf("4. Sex\n");
    printf("5. Class\n");
    printf("6. Birth\n");
    printf("7. Home\n");
    printf("8. Phone\n");
    printf("9. All Fields\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 9) {
        int id, roomNum, phone;
        char name[50], sex[10], stuClass[50], birth[20], home[100];
        studentEditorGetStudentInfo(&id, &roomNum, name, sex, stuClass, birth, home, &phone);
        modifyStudentByPos(head_ptr, pos, id, roomNum, name, sex, stuClass, birth, home, phone);
    } else {
        switch(choice) {
            case 1: {
                int id;
                printf("Enter new ID: ");
                scanf("%d", &id);
                modifyStudentIdByPos(head_ptr, pos, id);
                break;
            }
            case 2: {
                int roomNum;
                printf("Enter new Room Number: ");
                scanf("%d", &roomNum);
                modifyStudentRoomNumByPos(head_ptr, pos, roomNum);
                break;
            }
            case 3: {
                char name[50];
                printf("Enter new Name: ");
                scanf("%s", name);
                modifyStudentNameByPos(head_ptr, pos, name);
                break;
            }
            case 4: {
                char sex[10];
                printf("Enter new Sex: ");
                scanf("%s", sex);
                modifyStudentSexByPos(head_ptr, pos, sex);
                break;
            }
            case 5: {
                char stuClass[50];
                printf("Enter new Class: ");
                scanf("%s", stuClass);
                modifyStudentClassByPos(head_ptr, pos, stuClass);
                break;
            }
            case 6: {
                char birth[20];
                printf("Enter new Birth: ");
                scanf("%s", birth);
                modifyStudentBirthByPos(head_ptr, pos, birth);
                break;
            }
            case 7: {
                char home[100];
                printf("Enter new Home: ");
                scanf("%s", home);
                modifyStudentHomeByPos(head_ptr, pos, home);
                break;
            }
            case 8: {
                int phone;
                printf("Enter new Phone: ");
                scanf("%d", &phone);
                modifyStudentPhoneByPos(head_ptr, pos, phone);
                break;
            }
        }
    }
    printf("Modification completed!\n");
}

static void modifyById(StudentNode* head_ptr) {
    int target_id, choice;
    printf("Enter student ID: ");
    scanf("%d", &target_id);
    
    StudentNode* node = queryStudentById(head_ptr, target_id);
    if (!node) {
        printf("Student not found!\n");
        return;
    }
    
    printf("\nCurrent Info:\n");
    printStudentNode(node);
    
    printf("\nSelect field to modify:\n");
    printf("1. ID\n");
    printf("2. Room Number\n");
    printf("3. Name\n");
    printf("4. Sex\n");
    printf("5. Class\n");
    printf("6. Birth\n");
    printf("7. Home\n");
    printf("8. Phone\n");
    printf("9. All Fields\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 9) {
        int id, roomNum, phone;
        char name[50], sex[10], stuClass[50], birth[20], home[100];
        studentEditorGetStudentInfo(&id, &roomNum, name, sex, stuClass, birth, home, &phone);
        modifyStudentById(head_ptr, target_id, id, roomNum, name, sex, stuClass, birth, home, phone);
    } else {
        switch(choice) {
            case 1: {
                int id;
                printf("Enter new ID: ");
                scanf("%d", &id);
                modifyStudentIdById(head_ptr, target_id, id);
                break;
            }
            case 2: {
                int roomNum;
                printf("Enter new Room Number: ");
                scanf("%d", &roomNum);
                modifyStudentRoomNumById(head_ptr, target_id, roomNum);
                break;
            }
            case 3: {
                char name[50];
                printf("Enter new Name: ");
                scanf("%s", name);
                modifyStudentNameById(head_ptr, target_id, name);
                break;
            }
            case 4: {
                char sex[10];
                printf("Enter new Sex: ");
                scanf("%s", sex);
                modifyStudentSexById(head_ptr, target_id, sex);
                break;
            }
            case 5: {
                char stuClass[50];
                printf("Enter new Class: ");
                scanf("%s", stuClass);
                modifyStudentClassById(head_ptr, target_id, stuClass);
                break;
            }
            case 6: {
                char birth[20];
                printf("Enter new Birth: ");
                scanf("%s", birth);
                modifyStudentBirthById(head_ptr, target_id, birth);
                break;
            }
            case 7: {
                char home[100];
                printf("Enter new Home: ");
                scanf("%s", home);
                modifyStudentHomeById(head_ptr, target_id, home);
                break;
            }
            case 8: {
                int phone;
                printf("Enter new Phone: ");
                scanf("%d", &phone);
                modifyStudentPhoneById(head_ptr, target_id, phone);
                break;
            }
        }
    }
    printf("Modification completed!\n");
}

void studentEditorHandleModify(StudentNode* head_ptr) {
    int choice;
    showModifyMenu();
    scanf("%d", &choice);
    
    if (choice == 1) {
        modifyByPosition(head_ptr);
    } else if (choice == 2) {
        modifyById(head_ptr);
    }
}

void studentEditorHandleQuery(StudentNode* head_ptr) {
    int choice, pos, target_id;
    
    printf("\n--- Query Student ---\n");
    printf("1. Query by Position\n");
    printf("2. Query by ID\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter position: ");
        scanf("%d", &pos);
        StudentNode* node = queryStudentByPos(head_ptr, pos);
        if (node) {
            printStudentNode(node);
        } else {
            printf("Student not found!\n");
        }
    } else if (choice == 2) {
        printf("Enter student ID: ");
        scanf("%d", &target_id);
        StudentNode* node = queryStudentById(head_ptr, target_id);
        if (node) {
            printStudentNode(node);
        } else {
            printf("Student not found!\n");
        }
    }
}

void studentEditorListAll(StudentNode* head_ptr) {
    printf("\n--- All Students ---\n");
    listStudents(head_ptr);
}
