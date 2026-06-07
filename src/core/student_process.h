//
// Created by ASUS on 2026/6/4.
//

#ifndef STUDENTINFOSYSTEM_STUDENT_H
#define STUDENTINFOSYSTEM_STUDENT_H

#include "student_list.h"

typedef enum ModifyType
{
    MODIFY_Id,
    MODIFY_RoomNum,
    MODIFY_Name,
    MODIFY_Sex,
    MODIFY_Class,
    MODIFY_Birth,
    MODIFY_Home,
    MODIFY_Phone
}ModifyType;

/* Modify Port */ //parameter1 is the node pointer need to be modified,parameter2 is the modify value
void ModifyID(StudentNode* StuNode_ptr,int I_id);
void ModifyRoomNum(StudentNode* StuNode_ptr,int I_roomNum);
void ModifyPhone(StudentNode* StuNode_ptr,int I_phone);/*int type modify*/
void ModifyName(StudentNode* StuNode_ptr,const char* I_name);
void ModifySex(StudentNode* StuNode_ptr,const char* I_sex);
void ModifyClass(StudentNode* StuNode_ptr,const char* I_class);
void ModifyBirth(StudentNode* StuNode_ptr,const char* I_birth);
void ModifyHome(StudentNode* StuNode_ptr,const char* I_home);/*char* type modify*/



/* Node Modify */
void modify(StudentNode* head_ptr,ModifyType M_type,const void* M_value);//GENERIC:modify function, it will call the corresponding modification port according to the modify type, and use void* to make it more generic, so that you can use the same function to modify different types of data
void modifyByPos(StudentNode* *head_ptr,ModifyType M_type,const void* M_value,int pos);
void modifyById(StudentNode* *head_ptr,ModifyType M_type,const void* M_value,int target_id);



#endif //STUDENTINFOSYSTEM_STUDENT_H