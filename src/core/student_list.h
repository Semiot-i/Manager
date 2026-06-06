//
// Created by ASUS on 2026/6/4.
//

#ifndef FOR_REVIEW_LINKED_LIST_H
#define FOR_REVIEW_LINKED_LIST_H

typedef struct StudentInfo
{
    int id;
    int stuRoomNum;
    char* stuName;
    char* stuSex;
    char* stuClass;
    char* stuBirth;
    char* stuHome;
    int stuPhone;
}StudentInfo;//student data

typedef struct StudentNode {
    StudentInfo info;//student data
    int position;//position in the list,for easy access
    struct StudentNode *nextNode_ptr;//link ptr
} StudentNode;//linked list node struct

extern StudentNode *head_p;//list head pointer

/* List Process */
StudentNode* createNode(int I_id, int I_roomNum, char* I_name,char* I_sex, char* I_class, char* I_birth, char* I_home,int I_phone);//Create new student information("I" means input)
void* destroyNode(StudentNode* node_p);//Free student info,and return the next node ptr
void listInit();//initialize list
void listFree();//Free all list

/* List Iterate */
void IterateOverList(StudentNode* head_ptr, void(*visitFunc)(StudentNode* currentNode_p,void*), void* context);//GENERICS:Iterate over list,you can write a callback function to visit each node



#endif //FOR_REVIEW_LINKED_LIST_H