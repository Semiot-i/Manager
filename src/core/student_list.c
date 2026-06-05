//
// Created by ASUS on 2026/6/4.
//

#include "common.h"
#include "student_list.h"

StudentNode* head_p;//Student list head pointer,for multi-threading use

StudentNode* createNode(int I_id, int I_roomNum, char I_name[],char I_sex[], char I_class[], char I_birth[], char I_home[],int I_phone)
{
    StudentNode *newNode_p = (StudentNode *)malloc (sizeof(StudentNode));//create node on heap
    if (newNode_p == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }//check memory allocation
    newNode_p -> info.id = I_id;
    newNode_p -> info.stuRoomNum = I_roomNum;
    newNode_p -> info.stuPhone = I_phone;
    strcpy_s (newNode_p -> info.stuName, sizeof(newNode_p -> info.stuName), I_name);
    strcpy_s (newNode_p -> info.stuSex, sizeof(newNode_p -> info.stuSex), I_sex);
    strcpy_s (newNode_p -> info.stuClass, sizeof(newNode_p -> info.stuClass), I_class);
    strcpy_s (newNode_p -> info.stuBirth, sizeof(newNode_p -> info.stuBirth), I_birth);
    strcpy_s (newNode_p -> info.stuHome, sizeof(newNode_p -> info.stuHome), I_home);//data  copy
    newNode_p->nextNode_ptr = NULL;//link ptr
    return newNode_p;//return node ptr
}

/* List Process*/
void listInit()
{
    head_p = NULL;//initialize head pointer to NULL (empty list)
}
void listFree(){}


/* List Iterate */
void IterateOverList(StudentNode* head_ptr, void(*visitFunc)(StudentNode* currentNode_p,void*), void* context)//GENERICS:callback function can define how to visit each node, context can be used to pass additional data if needed
{
    StudentNode* currentNode_ptr = head_ptr;
    while (currentNode_ptr != NULL)//iterate over list until the end (NULL)
    {
        visitFunc(currentNode_ptr,context);
        currentNode_ptr = currentNode_ptr->nextNode_ptr;
    }
}
