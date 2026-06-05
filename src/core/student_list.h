//
// Created by ASUS on 2026/6/4.
//

#ifndef FOR_REVIEW_LINKED_LIST_H
#define FOR_REVIEW_LINKED_LIST_H

typedef struct StudentNode {
    int id;
    int stuRoomNum;
    char stuName[18];
    char stuSex[6];
    char stuClass[40];
    char stuBirth[20];
    char stuHome[100];
    int stuPhone;
    struct StudentNode *nextNode_ptr;
} StudentNode;

extern StudentNode *head;

void listInit();
StudentNode* createNode(int I_id, int I_roomNum, char I_name[],char I_sex[], char I_class[], char I_birth[], char I_home[],int I_phone);//"I" means input
StudentNode* addNode_Tail(StudentNode* *head_ptr, int I_id, int I_roomNum, char I_name[],char I_sex[], char I_class[], char I_birth[], char I_home[],int I_phone);
void modifyByPos(StudentNode* head_ptr, int pos, int I_id, int I_roomNum, char I_name[],char);
void modifyById(StudentNode* head_ptr, int target_id, int I_id, int I_roomNum, char I_name);
StudentNode* IterateOverList(StudentNode* head_ptr, int target_id);
void deleteByPos(StudentNode* *head_ptr, int pos);
void freeList();


#endif //FOR_REVIEW_LINKED_LIST_H