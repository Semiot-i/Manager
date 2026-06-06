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


/* List Query */
void updatePositions(StudentNode* head_ptr);//Update position field for all nodes in the list
StudentNode* getNodeByPos(StudentNode* head_ptr, int I_pos);//Find node by position,return the node ptr
StudentNode* getNodeById(StudentNode* head_ptr, int I_id);//Find node by student id,return the node ptr
StudentNode* getNodeByName(StudentNode* headA_ptr, char* I_name);//Find node by student's name,return the node ptr
StudentNode** getAllNodeByName(StudentNode* head_ptr, char* I_name);//Find all nodes by student's name,return an array of node ptrs
int getCount(StudentNode* head_ptr);//Get the total number of nodes in the list


/* List Iterate */
void IterateOverList(StudentNode* head_ptr, void(*visitFunc)(StudentNode* currentNode_p,void*), void* context);//GENERICS:Iterate over list,you can write a callback function to visit each node



#endif //FOR_REVIEW_LINKED_LIST_H