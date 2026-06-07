//
// Created by ASUS on 2026/6/4.
//

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "student_list.h"

int save_student_to_file( char* filePath, StudentNode* head);//对学生信息进行（增、删、改）操作后，调用此函数将链表中的学生信息保存到指定文件中。
int load_student_from_file( char* filePath, StudentNode** head_ptr);//从指定文件中读取学生信息，并将其加载到链表中。
int is_file_exists(char* filePath);//检查指定文件是否存在，返回1表示存在，0表示不存在。

#endif //FILE_MANAGER_H