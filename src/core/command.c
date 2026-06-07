//
// Created by ASUS on 2026/6/4.
//

#include "common.h"
#include "command.h"

// 将 target 指向的字符串替换为 source
static int replaceString(char** target, const char* source)
{
    if (target == NULL || source == NULL)
        return 0;

    size_t length = strlen(source) + 1;
    char* buffer = (char*)malloc(length);
    if (buffer == NULL)
        return 0;

    strcpy_s(buffer, length, source);
    free(*target);
    *target = buffer;
    return 1;
}

// 从文件中读取一行整数，忽略空行
static int readIntLine(FILE* file, int* outValue)
{
    if (file == NULL || outValue == NULL)
        return 0;

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (buffer[0] == '\n' || buffer[0] == '\r')
            continue;

        char* endPtr = NULL;
        long value = strtol(buffer, &endPtr, 10);
        if (endPtr == buffer)
            return 0;

        *outValue = (int)value;
        return 1;
    }

    return 0;
}

// 从文件中读取一行字符串，并去掉尾部换行符
static int readStringLine(FILE* file, char** outString)
{
    if (file == NULL || outString == NULL)
        return 0;

    char buffer[512];
    if (fgets(buffer, sizeof(buffer), file) == NULL)
        return 0;

    size_t length = strcspn(buffer, "\r\n");
    buffer[length] = '\0';

    char* result = (char*)malloc(length + 1);
    if (result == NULL)
        return 0;

    strcpy_s(result, length + 1, buffer);
    *outString = result;
    return 1;
}

// 添加学生节点到链表末尾，参数检查并更新位置索引
int addStudent(StudentNode** head_ptr,
               int id,
               int roomNum,
               const char* name,
               const char* sex,
               const char* stuClass,
               const char* birth,
               const char* home,
               int phone)
{
    if (head_ptr == NULL || name == NULL || sex == NULL || stuClass == NULL || birth == NULL || home == NULL)
        return 0;

    StudentNode* newNode = createNode(id, roomNum, (char*)name, (char*)sex, (char*)stuClass, (char*)birth, (char*)home, phone);
    if (newNode == NULL)
        return 0;

    if (*head_ptr == NULL)
    {
        *head_ptr = newNode;
    }
    else
    {
        StudentNode* tail = *head_ptr;
        while (tail->nextNode_ptr != NULL)
            tail = tail->nextNode_ptr;

        tail->nextNode_ptr = newNode;
    }

    updatePos(*head_ptr);
    return 1;
}

// 按位置删除学生节点，并重新计算位置
int deleteStudentByPos(StudentNode** head_ptr, int pos)
{
    if (head_ptr == NULL || *head_ptr == NULL || pos <= 0)
        return 0;

    updatePos(*head_ptr);
    StudentNode* current = *head_ptr;
    StudentNode* previous = NULL;

    while (current != NULL && current->position != pos)
    {
        previous = current;
        current = current->nextNode_ptr;
    }

    if (current == NULL)
        return 0;

    if (previous == NULL)
        *head_ptr = current->nextNode_ptr;
    else
        previous->nextNode_ptr = current->nextNode_ptr;

    destroyNode(current);
    updatePos(*head_ptr);
    return 1;
}

// 按学号删除学生节点，并重新计算位置
int deleteStudentById(StudentNode** head_ptr, int target_id)
{
    if (head_ptr == NULL || *head_ptr == NULL)
        return 0;

    StudentNode* current = *head_ptr;
    StudentNode* previous = NULL;

    while (current != NULL && current->info.id != target_id)
    {
        previous = current;
        current = current->nextNode_ptr;
    }

    if (current == NULL)
        return 0;

    if (previous == NULL)
        *head_ptr = current->nextNode_ptr;
    else
        previous->nextNode_ptr = current->nextNode_ptr;

    destroyNode(current);
    updatePos(*head_ptr);
    return 1;
}

// 内部函数：替换目标节点中的学生信息字符串并更新基本字段
static int setStudentInfo(StudentNode* target,
                          int id,
                          int roomNum,
                          const char* name,
                          const char* sex,
                          const char* stuClass,
                          const char* birth,
                          const char* home,
                          int phone)
{
    if (target == NULL || name == NULL || sex == NULL || stuClass == NULL || birth == NULL || home == NULL)
        return 0;

    target->info.id = id;
    target->info.stuRoomNum = roomNum;
    target->info.stuPhone = phone;

    if (!replaceString(&target->info.stuName, name))
        return 0;
    if (!replaceString(&target->info.stuSex, sex))
        return 0;
    if (!replaceString(&target->info.stuClass, stuClass))
        return 0;
    if (!replaceString(&target->info.stuBirth, birth))
        return 0;
    if (!replaceString(&target->info.stuHome, home))
        return 0;

    return 1;
}

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
                       int phone)
{
    if (head_ptr == NULL || pos <= 0)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    return setStudentInfo(target, id, roomNum, name, sex, stuClass, birth, home, phone);
}

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
                      int phone)
{
    if (head_ptr == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    return setStudentInfo(target, id, roomNum, name, sex, stuClass, birth, home, phone);
}

// 按位置查询学生节点
StudentNode* queryStudentByPos(StudentNode* head_ptr, int pos)
{
    if (head_ptr == NULL || pos <= 0)
        return NULL;

    updatePos(head_ptr);
    return getNodeByPos(head_ptr, pos);
}

// 按学号查询学生节点
StudentNode* queryStudentById(StudentNode* head_ptr, int target_id)
{
    if (head_ptr == NULL)
        return NULL;

    return getNodeById(head_ptr, target_id);
}

// 打印单个学生基本信息
void printStudent(const StudentInfo* info)
{
    if (info == NULL)
        return;

    printf("ID: %d\n", info->id);
    printf("Room Number: %d\n", info->stuRoomNum);
    printf("Name: %s\n", info->stuName);
    printf("Sex: %s\n", info->stuSex);
    printf("Class: %s\n", info->stuClass);
    printf("Birthday: %s\n", info->stuBirth);
    printf("Home Address: %s\n", info->stuHome);
    printf("Phone: %d\n", info->stuPhone);
}

// 打印一个学生节点信息，含位置编号
void printStudentNode(const StudentNode* node)
{
    if (node == NULL)
        return;

    if (node->position > 0)
        printf("Position: %d\n", node->position);

    printStudent(&node->info);
    printf("-----------------------------\n");
}

// 遍历回调：打印当前节点
static void printStudentCallback(StudentNode* currentNode, void* context)
{
    (void)context;
    printStudentNode(currentNode);
}

// 打印链表中所有学生信息
void listStudents(StudentNode* head_ptr)
{
    if (head_ptr == NULL)
    {
        printf("No students in the list.\n");
        return;
    }

    updatePos(head_ptr);
    IterateOverList(head_ptr, printStudentCallback, NULL);
}

// 保存学生链表到文本文件，每条记录按行写入
int saveStudentListToFile(const char* filename, StudentNode* head_ptr)
{
    if (filename == NULL)
        return 0;

    FILE* file = fopen(filename, "w");
    if (file == NULL)
        return 0;

    StudentNode* current = head_ptr;
    while (current != NULL)
    {
        fprintf(file, "%d\n", current->info.id);
        fprintf(file, "%d\n", current->info.stuRoomNum);
        fprintf(file, "%d\n", current->info.stuPhone);
        fprintf(file, "%s\n", current->info.stuName);
        fprintf(file, "%s\n", current->info.stuSex);
        fprintf(file, "%s\n", current->info.stuClass);
        fprintf(file, "%s\n", current->info.stuBirth);
        fprintf(file, "%s\n", current->info.stuHome);
        current = current->nextNode_ptr;
    }

    int result = (fclose(file) == 0) ? 1 : 0;
    return result;
}

// 从文本文件加载学生链表，替换当前链表内容
int loadStudentListFromFile(const char* filename, StudentNode** head_ptr)
{
    if (filename == NULL || head_ptr == NULL)
        return 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL)
        return 0;

    StudentNode* newHead = NULL;
    StudentNode* tail = NULL;
    int id = 0;
    int roomNum = 0;
    int phone = 0;
    char* name = NULL;
    char* sex = NULL;
    char* stuClass = NULL;
    char* birth = NULL;
    char* home = NULL;

    while (1)
    {
        if (!readIntLine(file, &id))
            break;

        if (!readIntLine(file, &roomNum) ||
            !readIntLine(file, &phone) ||
            !readStringLine(file, &name) ||
            !readStringLine(file, &sex) ||
            !readStringLine(file, &stuClass) ||
            !readStringLine(file, &birth) ||
            !readStringLine(file, &home))
        {
            free(name);
            free(sex);
            free(stuClass);
            free(birth);
            free(home);
            while (newHead != NULL)
                newHead = (StudentNode*)destroyNode(newHead);
            fclose(file);
            return 0;
        }

        StudentNode* node = createNode(id, roomNum, name, sex, stuClass, birth, home, phone);
        free(name);
        free(sex);
        free(stuClass);
        free(birth);
        free(home);

        if (node == NULL)
        {
            while (newHead != NULL)
                newHead = (StudentNode*)destroyNode(newHead);
            fclose(file);
            return 0;
        }

        if (newHead == NULL)
            newHead = node;
        else
            tail->nextNode_ptr = node;

        tail = node;
    }

    fclose(file);

    while (*head_ptr != NULL)
        *head_ptr = (StudentNode*)destroyNode(*head_ptr);

    *head_ptr = newHead;
    updatePos(*head_ptr);
    return 1;
}
