//
// Created by ASUS on 2026/6/4.
//

#ifndef COMMAND_H
#define COMMAND_H

#include "student_list.h"

#ifdef __cplusplus
extern "C" {
#endif

// Add a student record to the end of the list
int addStudent(StudentNode** head_ptr,
               int id,
               int roomNum,
               const char* name,
               const char* sex,
               const char* stuClass,
               const char* birth,
               const char* home,
               int phone);

// Delete a student node by position
int deleteStudentByPos(StudentNode** head_ptr, int pos);
// Delete a student node by student id
int deleteStudentById(StudentNode** head_ptr, int target_id);

// Modify student information by position
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

// Modify single student field by position
int modifyStudentIdByPos(StudentNode* head_ptr, int pos, int id);
int modifyStudentRoomNumByPos(StudentNode* head_ptr, int pos, int roomNum);
int modifyStudentPhoneByPos(StudentNode* head_ptr, int pos, int phone);
int modifyStudentNameByPos(StudentNode* head_ptr, int pos, const char* name);
int modifyStudentSexByPos(StudentNode* head_ptr, int pos, const char* sex);
int modifyStudentClassByPos(StudentNode* head_ptr, int pos, const char* stuClass);
int modifyStudentBirthByPos(StudentNode* head_ptr, int pos, const char* birth);
int modifyStudentHomeByPos(StudentNode* head_ptr, int pos, const char* home);

// Modify student information by student id
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

// Modify single student field by student id
int modifyStudentIdById(StudentNode* head_ptr, int target_id, int id);
int modifyStudentRoomNumById(StudentNode* head_ptr, int target_id, int roomNum);
int modifyStudentPhoneById(StudentNode* head_ptr, int target_id, int phone);
int modifyStudentNameById(StudentNode* head_ptr, int target_id, const char* name);
int modifyStudentSexById(StudentNode* head_ptr, int target_id, const char* sex);
int modifyStudentClassById(StudentNode* head_ptr, int target_id, const char* stuClass);
int modifyStudentBirthById(StudentNode* head_ptr, int target_id, const char* birth);
int modifyStudentHomeById(StudentNode* head_ptr, int target_id, const char* home);

// Query student node by position
StudentNode* queryStudentByPos(StudentNode* head_ptr, int pos);
// Query student node by student id
StudentNode* queryStudentById(StudentNode* head_ptr, int target_id);

// Print single student information
void printStudent(const StudentInfo* info);
// Print student node information including position
void printStudentNode(const StudentNode* node);
// Print all student records in the list
void listStudents(StudentNode* head_ptr);

// Save student list to a text file
int saveStudentListToFile(const char* filename, StudentNode* head_ptr);
// Load student list from a text file and replace the current list
int loadStudentListFromFile(const char* filename, StudentNode** head_ptr);

#ifdef __cplusplus
}
#endif

#endif //COMMAND_H