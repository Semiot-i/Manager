//
// Created by ASUS on 2026/6/4.
//

#ifndef FOR_REVIEW_LINKED_LIST_H
#define FOR_REVIEW_LINKED_LIST_H

typedef struct StudentInfo
{
    int id;
    int stuRoomNum;
    char stuName[18];
    char stuSex[6];
    char stuClass[40];
    char stuBirth[20];
    char stuHome[100];
    int stuPhone;
}StudentInfo;//student data

typedef struct StudentNode {
    StudentInfo info;//student data
    struct StudentNode *nextNode_ptr;//link ptr
} StudentNode;//linked list node struct

extern StudentNode *head_p;//list head pointer

/* List Process */
void listInit();//initialize list
void listFree();//Free all student info in the list
StudentNode* createNode(int I_id, int I_roomNum, char I_name[],char I_sex[], char I_class[], char I_birth[], char I_home[],int I_phone);//Create new student information("I" means input)


/* List Iterate */
void IterateOverList(StudentNode* head_ptr, void(*visitFunc)(StudentNode* currentNode_p,void*), void* context);//GENERICS:Iterate over list,you can write a callback function to visit each node



#endif //FOR_REVIEW_LINKED_LIST_H