//
// Created by ASUS on 2026/6/4.
//

#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

typedef struct StudentInfo
{
    int id;
    int stuRoomNum;
    char* stuName;
    char* stuSex;
    char* stuClass;
    char* stuBirth;
    char* stuHome;
    int stuPhone;
}StudentInfo;//student data

typedef struct StudentNode {
    StudentInfo info;//student data
    int position;//position in the list,for easy access
    struct StudentNode *nextNode_ptr;//link ptr
} StudentNode;//linked list node struct

extern StudentNode *GlobalListHead_p;//list head pointer

/* Node Process */
StudentNode* createNode(int I_id, int I_roomNum,const char* I_name,const char* I_sex,const char* I_class,const char* I_birth,const char* I_home,int I_phone);//Create new student information("I" means input)
StudentNode* destroyNode(StudentNode* node_p);//Free student info,and return the next node ptr
StudentNode* addNode_Tail(StudentNode** head_ptr, int I_id, int I_roomNum,const char* I_name,const char* I_sex,const char* I_class,const char* I_birth,const char* I_home,int I_phone);//Add Student information to the end of the list
StudentNode* addNodeByPos(StudentNode** head_ptr, int I_pos, int I_id, int I_roomNum,const char* I_name,const char* I_sex,const char* I_class,const char* I_birth,const char* I_home,int I_phone);//Add Student information at specified position
void deleteNodeByPos(StudentNode** head_ptr, int pos);//Delete node at specified position

/* List Process */ //(Unfinished)avoid using the func, it's not completed,you can build func use the node process func
void listInit(StudentNode** head_ptr);//initialize list
void listFree(StudentNode** head_ptr);//Free all list


/* List Query */
void updatePos(StudentNode* head_ptr);//Update position field for all nodes in the list
StudentNode* getNodeByPos(StudentNode* head_ptr, int I_pos);//Find node by position,return the node ptr
StudentNode* getNodeById(StudentNode* head_ptr, int I_id);//Find node by student id,return the node ptr
StudentNode* getNodeByName(StudentNode* headA_ptr, char* I_name);//Find node by student's name,return the node ptr
StudentNode** getAllNodeByName(StudentNode* head_ptr, char* I_name);//Find all nodes by student's name,return an array of node ptrs
int getCount(StudentNode* head_ptr);//Get the total number of nodes in the list


/* List Iterate */
void IterateOverList(StudentNode* head_ptr, void(*visitFunc)(StudentNode* currentNode_p,void*), void* context);//GENERICS:Iterate over list,you can write a callback function to visit each node



#endif //STUDENT_LIST_H