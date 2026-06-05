//
// Created by ASUS on 2026/6/4.
//

#ifndef FOR_REVIEW_STUDENT_H
#define FOR_REVIEW_STUDENT_H

#include "student_list.h"


/* Node Process */
StudentNode* addNode_Tail(StudentNode* *head_ptr, int I_id, int I_roomNum, char I_name[],char I_sex[], char I_class[], char I_birth[], char I_home[],int I_phone);//Add Student information to the end of the list
void deleteByPos(StudentNode* *head_ptr, int pos);//Delete Student info by position


/* Node Modify */
void modifyByPos(StudentNode* head_ptr, int pos, int I_id, int I_roomNum, char I_name[],char I_sex[]);
void modifyById(StudentNode* head_ptr, int target_id, int I_id, int I_roomNum, char I_name[], char I_sex[]);




#endif //FOR_REVIEW_STUDENT_H