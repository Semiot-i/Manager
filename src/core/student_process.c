//
// Created by ASUS on 2026/6/4.
//
#include "common.h"
#include "student_process.h"


// head_p is defined in student_list.c, declared extern in student_list.h
// No need to redefine here


/* Node Modify */
void modify(StudentNode* StuNode_ptr,ModifyType M_type,void* M_value)
{
    if (M_type == MODIFY_Id){}
    if (M_type == MODIFY_RoomNum){}
    if (M_type == MODIFY_Name){}
    if (M_type == MODIFY_Sex){}
    if (M_type == MODIFY_Class){}
    if (M_type == MODIFY_Birth){}
    if (M_type == MODIFY_Home){}
    if (M_type == MODIFY_Phone){}
}
void modifyByPos(StudentNode* *head_ptr,ModifyType M_type,void* M_value,int pos)
{
    if (head_ptr == NULL || *head_ptr == NULL)
    {
        printf("List is empty!\n");
        return;
    }//check if list is empty
    StudentNode* currentNode_p =getNodeByPos(*head_ptr,pos);
    modify(currentNode_p,M_type,M_value);
}