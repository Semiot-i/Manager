//
// Created by ASUS on 2026/6/4.
//

#ifndef FOR_REVIEW_STUDENT_H
#define FOR_REVIEW_STUDENT_H

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


/* Node Modify */
void modify(StudentNode* head_ptr,ModifyType M_type,void* M_value);
void modifyByPos(StudentNode* *head_ptr,ModifyType M_type,void* M_value,int pos);



#endif //FOR_REVIEW_STUDENT_H