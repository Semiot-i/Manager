//
// Created by ASUS on 2026/6/4.
//

#include "common.h"
#include "student_list.h"

StudentNode* head_p;//Student list head pointer,for multi-threading use


/* List Process*/
StudentNode* createNode(int I_id, int I_roomNum, char* I_name,char* I_sex, char* I_class, char* I_birth, char* I_home,int I_phone)
{
    StudentNode *newNode_p = (StudentNode *)malloc (sizeof(StudentNode));//create node on heap
    if (newNode_p == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }//check memory allocation
    newNode_p -> info.id = I_id;
    newNode_p -> info.stuRoomNum = I_roomNum;
    newNode_p -> info.stuPhone = I_phone;
    size_t nameLen = strlen(I_name) + 1;
    size_t sexLen = strlen(I_sex) + 1;
    size_t classLen = strlen(I_class) + 1;
    size_t birthLen = strlen(I_birth) + 1;
    size_t homeLen = strlen(I_home) + 1;//calculate string lengths for memory allocation
    newNode_p -> info.stuName = (char*)malloc(nameLen * sizeof(char));
    newNode_p -> info.stuSex = (char*)malloc(sexLen * sizeof(char));
    newNode_p -> info.stuClass = (char*)malloc(classLen * sizeof(char));
    newNode_p -> info.stuBirth = (char*)malloc(birthLen * sizeof(char));
    newNode_p -> info.stuHome = (char*)malloc(homeLen * sizeof(char));//allocate memory for strings
    if (newNode_p -> info.stuName == NULL || newNode_p -> info.stuSex == NULL ||
        newNode_p -> info.stuClass == NULL || newNode_p -> info.stuBirth == NULL ||
        newNode_p -> info.stuHome == NULL)
    {
        // Free any successfully allocated strings before returning
        free(newNode_p -> info.stuName);
        free(newNode_p -> info.stuSex);
        free(newNode_p -> info.stuClass);
        free(newNode_p -> info.stuBirth);
        free(newNode_p -> info.stuHome);
        free(newNode_p);
        printf("String memory allocation failed!\n");
        return NULL;
    }
    strcpy_s (newNode_p -> info.stuName, nameLen, I_name);
    strcpy_s (newNode_p -> info.stuSex, sexLen, I_sex);
    strcpy_s (newNode_p -> info.stuClass, classLen, I_class);
    strcpy_s (newNode_p -> info.stuBirth, birthLen, I_birth);
    strcpy_s (newNode_p -> info.stuHome, homeLen, I_home);//data  copy
    newNode_p->position = 0;//position will be updated when inserted into list
    newNode_p->nextNode_ptr = NULL;//link ptr
    return newNode_p;//return node ptr
}
void* destroyNode(StudentNode* node_p)
{
    if (node_p == NULL)return NULL;

    void* temp_ptr = node_p->nextNode_ptr;
    free(node_p->info.stuName);
    free(node_p->info.stuSex);
    free(node_p->info.stuClass);
    free(node_p->info.stuBirth);
    free(node_p->info.stuHome);//free info memory
    free(node_p);//free info and ptr memory
    return temp_ptr;
}
void listInit()
{
    head_p = NULL;//initialize head pointer to NULL (empty list)
    // Note: If the list already contains nodes, they will be orphaned.
    // Call listFree() first to avoid memory leaks before re-initializing.
}
void listFree()
{
    while (head_p != NULL)
    {
        head_p = (StudentNode*)destroyNode(head_p);//destroyNode frees the node and returns the next node ptr
    }
}



/* List Iterate */
void IterateOverList(StudentNode* head_ptr, void(*visitFunc)(StudentNode* currentNode_p,void*), void* context)//GENERICS:callback function can define how to visit each node, context can be used to pass additional data if needed
{
    StudentNode* currentNode_ptr = head_ptr;
    while (currentNode_ptr != NULL)//iterate over list until the end (NULL)
    {
        visitFunc(currentNode_ptr,context);
        currentNode_ptr = currentNode_ptr->nextNode_ptr;
    }
}
