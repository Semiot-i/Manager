//
// Created by ASUS on 2026/6/4.
//
#include "common.h"
#include "student_process.h"

StudentNode* head_p;


/* Node Process */
StudentNode* addNode_Tail(StudentNode* *head_ptr, int I_id, int I_roomNum, char I_name[],char I_sex[], char I_class[], char I_birth[], char I_home[],int I_phone)
{
    StudentNode *newNode_p = createNode(I_id, I_roomNum, I_name, I_sex, I_class, I_birth, I_home, I_phone);
    if (*head_ptr ==NULL)
    {
        *head_ptr = newNode_p;
        return newNode_p;
    }
    StudentNode *temp_p = *head_ptr;
    while (temp_p->nextNode_ptr != NULL)
    {
        temp_p = temp_p->nextNode_ptr;
    }
    temp_p->nextNode_ptr = newNode_p;
    newNode_p->nextNode_ptr = NULL;
    return newNode_p;
}


/* Node Modify */