//
// Created by ASUS on 2026/6/3.
//
#include "common.h"
#include "core/student_list.h"
#include "core/student_process.h"


int main()
{
    //*****************FOR TRIAL*****************
    int choice = 0;
    printf("-----Welcome to use the program!-----\n");
    listInit();
    do
    {
        printf("Please input the command:\n");
        printf("1. Add a student\n");
        printf("2. Delete a student\n");
        printf("3. Modify a student\n");
        printf("4. Query a student\n");
        printf("5. List all students\n");
        printf("6. Save the list to file\n");
        printf("7. Load the list from file\n");
        printf("0. Exit the program\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Please enter the correspond info:\n");
                    
            int id, roomNum, phone;
            char name[18], sex[6], stuClass[40], birth[20], home[100];
                    
            printf("ID: ");
            scanf("%d", &id);
                    
            printf("Room Number: ");
            scanf("%d", &roomNum);
                    
            printf("Name: ");
            scanf("%s", name);
                    
            printf("Sex: ");
            scanf("%s", sex);
                    
            printf("Class: ");
            scanf("%s", stuClass);
                    
            printf("Birthday (YYYY-MM-DD): ");
            scanf("%s", birth);
                    
            printf("Home Address: ");
            scanf("%s", home);
                    
            printf("Phone: ");
            scanf("%d", &phone);
                    
            addNode_Tail(&head_p, id, roomNum, name, sex, stuClass, birth, home, phone);
            printf("Student added successfully!\n");
        }
        else if (choice == 2)
        {
            printf("Delete a student\n");
        }
        else if (choice == 3)
        {
            printf("Modify a student\n");
        }
        else if (choice == 4)
        {
            printf("Query a student\n");
        }
        else if (choice == 5)
        {
            printf("List all students\n");
        }
        else if (choice == 6)
        {
            printf("Save the list to file\n");
        }
        else if (choice == 7)
        {
            printf("Load the list from file\n");
        }
        else if (choice == 0)
        {
            printf("Exit the program\n");
        }
        else
        {
            printf("Invalid command\n");
        }
    } while (choice != 0);
}