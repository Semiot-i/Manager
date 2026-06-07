//
// Created by ASUS on 2026/6/4.
//

#ifndef FOR_REVIEW_COMMAND_H
#define FOR_REVIEW_COMMAND_H

#include "student_list.h"

#ifdef __cplusplus
extern "C" {
#endif

// 添加学生记录到链表末尾，执行所有参数合法性检查
int addStudent(StudentNode** head_ptr,
               int id,
               int roomNum,
               const char* name,
               const char* sex,
               const char* stuClass,
               const char* birth,
               const char* home,
               int phone);

// 按位置删除学生节点
int deleteStudentByPos(StudentNode** head_ptr, int pos);
// 按学号删除学生节点
int deleteStudentById(StudentNode** head_ptr, int target_id);

// 按位置修改学生信息
int modifyStudentByPos(StudentNode* head_ptr,
                       int pos,
                       int id,
                       int roomNum,
                       const char* name,
                       const char* sex,
                       const char* stuClass,
                       const char* birth,
                       const char* home,
                       int phone);

// 按学号修改学生信息
int modifyStudentById(StudentNode* head_ptr,
                      int target_id,
                      int id,
                      int roomNum,
                      const char* name,
                      const char* sex,
                      const char* stuClass,
                      const char* birth,
                      const char* home,
                      int phone);

// 按位置查询学生节点
StudentNode* queryStudentByPos(StudentNode* head_ptr, int pos);
// 按学号查询学生节点
StudentNode* queryStudentById(StudentNode* head_ptr, int target_id);

// 打印单个学生基本信息
void printStudent(const StudentInfo* info);
// 打印单个学生节点信息，包含位置
void printStudentNode(const StudentNode* node);
// 打印整个学生链表
void listStudents(StudentNode* head_ptr);

// 保存学生链表到文本文件
int saveStudentListToFile(const char* filename, StudentNode* head_ptr);
// 从文本文件读取学生链表，替换当前链表内容
int loadStudentListFromFile(const char* filename, StudentNode** head_ptr);

#ifdef __cplusplus
}
#endif

#endif //FOR_REVIEW_COMMAND_H