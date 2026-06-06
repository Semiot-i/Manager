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
    }//check StudentNode memory allocation statue
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
        newNode_p -> info.stuHome == NULL)//check if any string memory allocation failed
    {
        // Free any successfully allocated strings before returning
        printf("String memory allocation failed!\n");
        destroyNode(newNode_p);
        return NULL;
    }//check string memory allocation statue,avoid memory leaks
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


/* List Query */
void updatePos(StudentNode* head_ptr)
{
    int headPos = 1;
    if (head_ptr == NULL){return;}//empty list return
    StudentNode* currentNode_p = head_ptr;
    while (currentNode_p != NULL)//iterate over
    {
        currentNode_p->position = headPos;
        headPos++;
        currentNode_p = currentNode_p->nextNode_ptr;
    }

}
StudentNode* getNodeByPos(StudentNode* head_ptr, int I_pos)
{
    if (I_pos <= 0)
    {
        printf("Invalid position! Valid input is a positive integer!\n");
        return NULL;
    }//check position validation
    if (head_ptr == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }//check list is not empty
    StudentNode* currentNode_p = head_ptr;
    while (currentNode_p != NULL)
    {
        if (currentNode_p->position == I_pos)return currentNode_p;
        else currentNode_p = currentNode_p->nextNode_ptr;
    }
    printf("Position %d not found! You might enter an invalid position.\n", I_pos);
    return NULL;
}
StudentNode* getNodeById(StudentNode* head_ptr,int I_id)
{
    if (head_ptr == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    StudentNode* currentNode_p = head_ptr;
    while (currentNode_p != NULL)
    {
        if (currentNode_p->info.id == I_id)return currentNode_p;
        else currentNode_p = currentNode_p->nextNode_ptr;
    }
    printf("ID %d not found! You might enter an undefined ID.\n", I_id);
    return NULL;
}
StudentNode* getNodeByName(StudentNode* head_ptr,char* I_name)
{
    if (head_ptr == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    if (I_name == NULL)
    {
        printf("Name is empty!\n");
        return NULL;
    }
    StudentNode* currentNode_p = head_ptr;
    while (currentNode_p != NULL)
    {
        if (currentNode_p->info.stuName!=NULL && strcmp(currentNode_p->info.stuName, I_name) == 0)return currentNode_p;
        else currentNode_p = currentNode_p->nextNode_ptr;
    }
    printf("Name %s not found! You might enter an undefined name.\n", I_name);
    return NULL;
}
StudentNode** getAllNodeByName(StudentNode*head_ptr,char* I_name)
{
    //check list and input name is not empty
    if (head_ptr == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    if (I_name == NULL)
    {
        printf("Name is empty!\n");
        return NULL;
    }


    //count name amount
    int count = 0;
    StudentNode* currentNode_p = head_ptr;
    while (currentNode_p != NULL)    {
        if (currentNode_p->info.stuName!=NULL && strcmp(currentNode_p->info.stuName, I_name) == 0)count++;
        currentNode_p = currentNode_p->nextNode_ptr;
    }


    //allocate ptr memory
    if (count == 0)
    {
        printf("No student with name %s found!\n", I_name);
        return NULL;
    }//check name amount
    StudentNode** ptrArray = (StudentNode**)malloc((count + 1) *sizeof(StudentNode*));//allocate memory for pointer array,and extra space for NULL character
    if (ptrArray == NULL)
    {
        printf("Memory allocation failed for pointer array!");
        return NULL;
    }//check memory allocation for pointer array

    //collect ptr to ptr array
    int index = 0;
    currentNode_p = head_ptr;
    while (currentNode_p != NULL)
    {
        if (currentNode_p->info.stuName!=NULL && strcmp(currentNode_p->info.stuName, I_name) == 0)
        {
            ptrArray[index] = currentNode_p;
            index++;
        }
        currentNode_p = currentNode_p->nextNode_ptr;
    }//iterate over list
    ptrArray[index] = NULL;//NULL character to mark end of array
    return ptrArray;
}
int getCount(StudentNode* head_ptr)
{
    if (head_ptr == NULL)
    {
        printf("List is empty!\n");
        return 0;
    }
    int count = 0;
    StudentNode* currentNode_p = head_ptr;
    while (currentNode_p != NULL)
    {
        count++;
        currentNode_p = currentNode_p->nextNode_ptr;
    }
    return count;//return total number of nodes
}


/* List Iterate */ //For GENERICS
void IterateOverList(StudentNode* head_ptr, void(*visitFunc)(StudentNode* currentNode_p,void* context), void* context)//GENERICS:callback function can define how to visit each node, context can be used to pass additional data if needed
{
    StudentNode* currentNode_ptr = head_ptr;
    while (currentNode_ptr != NULL)//iterate over list until the end (NULL)
    {
        visitFunc(currentNode_ptr,context);
        currentNode_ptr = currentNode_ptr->nextNode_ptr;
    }
}
