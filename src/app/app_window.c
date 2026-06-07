#include "app_window.h"
#include <stdio.h>
#include <stdlib.h>

extern StudentNode* GlobalListHead_p;

static void showMainMenu(void) {
    printf("\n========================================\n");
    printf("       Student Information System\n");
    printf("========================================\n");
    printf("1. Add Student\n");
    printf("2. Delete Student\n");
    printf("3. Modify Student\n");
    printf("4. Query Student\n");
    printf("5. List All Students\n");
    printf("6. Load from File\n");
    printf("7. Save to File\n");
    printf("0. Exit\n");
    printf("========================================\n");
    printf("Please enter your choice: ");
}

void appWindowInit(void) {
    GlobalListHead_p = NULL;
    system("cls");
}

void appWindowShowMenu(void) {
    showMainMenu();
}

int appWindowGetUserChoice(void) {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void appWindowCleanup(void) {
    printf("\nThank you for using the system!\n");
}
