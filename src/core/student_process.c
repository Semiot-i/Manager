//
// Created by ASUS on 2026/6/4.
//
#include "common.h"
#include "student_process.h"


// head_p is defined in student_list.c, declared extern in student_list.h
// No need to redefine here


/* Modify Port */
void ModifyID(StudentNode* StuNode_ptr,int I_id)
{
    StuNode_ptr->info.id = I_id;
}
void ModifyRoomNum(StudentNode* StuNode_ptr,int I_roomNum)
{
    StuNode_ptr->info.stuRoomNum = I_roomNum;
}
void ModifyPhone(StudentNode* StuNode_ptr,int I_phone)
{
    StuNode_ptr->info.stuPhone = I_phone;
}//int type modify,change directly
void ModifyName(StudentNode* StuNode_ptr,const char* I_name)
{
    free(StuNode_ptr->info.stuName);
    size_t I_name_len = strlen(I_name);
    StuNode_ptr->info.stuName = malloc((I_name_len+1)*sizeof(char));
}
void ModifySex(StudentNode* StuNode_ptr,const char* I_sex)
{
    free(StuNode_ptr->info.stuSex);
    size_t I_sex_len = strlen(I_sex);
    StuNode_ptr->info.stuSex = malloc((I_sex_len+1)*sizeof(char));
}
void ModifyClass(StudentNode* StuNode_ptr,const char* I_class)
{
    free(StuNode_ptr->info.stuClass);
    size_t I_class_len = strlen(I_class);
    StuNode_ptr->info.stuClass = malloc((I_class_len+1)*sizeof(char));
}
void ModifyBirth(StudentNode* StuNode_ptr,const char* I_birth)
{
    free(StuNode_ptr->info.stuBirth);
    size_t I_birth_len = strlen(I_birth);
    StuNode_ptr->info.stuBirth = malloc((I_birth_len+1)*sizeof(char));
}
void ModifyHome(StudentNode* StuNode_ptr,const char* I_home)
{
    free(StuNode_ptr->info.stuHome);
    size_t I_home_len = strlen(I_home);
    StuNode_ptr->info.stuHome = malloc((I_home_len+1)*sizeof(char));
}//char* type modify,free old memory first, redirect ptr to new malloced_memory


/* Node Modify */
void modify(StudentNode* StuNode_ptr,ModifyType M_type,const void* M_value)
{
    if (M_type == MODIFY_Id)
    {
        int* temp = (int*)M_value;//use int* to avoid copying, and make it more efficient, since int is a small type, the performance difference is negligible, but it's a good practice to use pointers for modify functions
        ModifyID(StuNode_ptr,*temp);
    }
    if (M_type == MODIFY_RoomNum)
    {
        int* temp = (int*)M_value;
        ModifyRoomNum(StuNode_ptr,*temp);
    }
    if (M_type == MODIFY_Phone)
    {
        int* temp = (int*)M_value;
        ModifyPhone(StuNode_ptr,*temp);
    }
    if (M_type == MODIFY_Name)
    {
        char* temp = (char*)M_value;
        ModifyName(StuNode_ptr,temp);
    }
    if (M_type == MODIFY_Sex)
    {
        char* temp = (char*)M_value;
        ModifySex(StuNode_ptr,temp);
    }
    if (M_type == MODIFY_Class)
    {
        char* temp = (char*)M_value;
        ModifyClass(StuNode_ptr,temp);
    }
    if (M_type == MODIFY_Birth)
    {
        char* temp = (char*)M_value;
        ModifyBirth(StuNode_ptr,temp);
    }
    if (M_type == MODIFY_Home)
    {
        char* temp = (char*)M_value;
        ModifyHome(StuNode_ptr,temp);
    }
}//modify function, it will call the corresponding modification port according to the modify type, and use void* to make it more generic, so that you can use the same function to modify different types of data
void modifyByPos(StudentNode* *head_ptr,ModifyType M_type,const void* M_value,int pos)
{
    if (head_ptr == NULL || *head_ptr == NULL)
    {
        printf("List is empty!\n");
        return;
    }//check if list is empty
    StudentNode* currentNode_p =getNodeByPos(*head_ptr,pos);
    if (currentNode_p == NULL)
    {
        printf("Node not found!\n");
        return;
    }
    modify(currentNode_p,M_type,M_value);
}
void modifyById(StudentNode* *head_ptr,ModifyType M_type,const void* M_value,int target_id)
{
    if (head_ptr == NULL || *head_ptr == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    StudentNode* currentNode_p = getNodeById(*head_ptr,target_id);
    if (currentNode_p == NULL)
    {
        printf("Node not found!\n");
        return;
    }
    modify(currentNode_p,M_type,M_value);
}