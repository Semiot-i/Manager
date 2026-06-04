//
// Created by ASUS on 2026/6/4.
//

#ifndef FOR_REVIEW_LINKED_LIST_H
#define FOR_REVIEW_LINKED_LIST_H

typedef struct StudentInfo {
    char* id;
    char* stuName;
    char* stuSex;
    char* stuClass;
    char* stuRoomNum;
    char* stuBirth;
    char* stuHome;
    char* stuPhone;
    struct StudentInfo *next;
} StudentNode;

void listInit();
void createStudentNode(StudentNode *node);
void pruneStudentNode(StudentNode *node);


#endif //FOR_REVIEW_LINKED_LIST_H