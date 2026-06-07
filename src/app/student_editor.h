#ifndef STUDENT_EDITOR_H
#define STUDENT_EDITOR_H

#include "../include/common.h"
#include "../core/command.h"

void studentEditorShowAddForm(void);
void studentEditorGetStudentInfo(int* id, int* roomNum, char* name, char* sex, 
                                  char* stuClass, char* birth, char* home, int* phone);
void studentEditorHandleAdd(StudentNode** head_ptr);
void studentEditorHandleDelete(StudentNode** head_ptr);
void studentEditorHandleModify(StudentNode* head_ptr);
void studentEditorHandleQuery(StudentNode* head_ptr);
void studentEditorListAll(StudentNode* head_ptr);

#endif
