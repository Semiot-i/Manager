//
// Created by ASUS on 2026/6/4.
//
#include "file_manager.h"
#include "common.h"

int save_student_to_file( char* filePath, StudentNode* head)
{
    if (filePath == NULL || head == NULL)//wrong file path or empty list
    {
        printf("Invalid file path or empty student list!\n");
        return -1;
    }
    
    FILE* file = fopen(filePath, "w");

    if (file == NULL)//failed to open file
    {
        printf("Failed to open file %s for writing!\n", filePath);
        return -1;
    }
   
    StudentNode* currentNode_p = head;

    while (currentNode_p != NULL)//write student info to file 
    {
        fprintf(file, "%d,%d,%s,%s,%s,%s,%s,%d\n",
                currentNode_p->info.id,
                currentNode_p->info.stuRoomNum,
                currentNode_p->info.stuName,
                currentNode_p->info.stuSex,
                currentNode_p->info.stuClass,
                currentNode_p->info.stuBirth,
                currentNode_p->info.stuHome,
                currentNode_p->info.stuPhone);
        currentNode_p = currentNode_p->nextNode_ptr;
    }
    
    fclose(file);
    return 0;
}

int load_student_from_file(char* filePath, StudentNode** head)
{
    if (filePath == NULL || head == NULL)//wrong file path or null head pointer
    {
        printf("Invalid file path or null head pointer!\n");
        return -1;
    }
    
    FILE* file = fopen(filePath, "r");

    if (file == NULL)//failed to open file
    {
        printf("Failed to open file %s for reading!\n", filePath);
        return -1;
    }
    
    char line[512];//buffer to read each line of student info from file
    
    while (fgets(line, sizeof(line), file))//read student info from file and add to list
    {
        int id, stuRoomNum, stuPhone;
        char stuName[100], stuSex[10], stuClass[50], stuBirth[20], stuHome[100];
        
        sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%[^,],%[^,],%d",
               &id, &stuRoomNum, stuName, stuSex, stuClass, stuBirth, stuHome, &stuPhone);
        
        addNode_Tail(head, id, stuRoomNum, stuName, stuSex, stuClass, stuBirth, stuHome, stuPhone);
    }
    
    fclose(file);
    return 0;
}

int is_file_exists(char* filePath)
{
    if (filePath == NULL)
    {
        printf("Invalid file path!\n");
        return 0;
    }
    
    FILE* file = fopen(filePath, "r");
    if (file != NULL)
    {
        fclose(file);
        return 1;//file exists
    }
    
    return 0;//file does not exist
}