// Created by ASUS on 2026/6/4.
//

#include "common.h"
#include "command.h"
#include "student_process.h"
#include "file_manager.h"

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

    StudentNode* node = addNode_Tail(head_ptr, id, roomNum, name, sex, stuClass, birth, home, phone);
    if (node == NULL)
        return 0;

    updatePos(*head_ptr);
    return 1;
}

int deleteStudentByPos(StudentNode** head_ptr, int pos)
{
    if (head_ptr == NULL || *head_ptr == NULL || pos <= 0)
        return 0;

    updatePos(*head_ptr);
    if (getNodeByPos(*head_ptr, pos) == NULL)
        return 0;

    deleteNodeByPos(head_ptr, pos);
    updatePos(*head_ptr);
    return 1;
}

int deleteStudentById(StudentNode** head_ptr, int target_id)
{
    if (head_ptr == NULL || *head_ptr == NULL)
        return 0;

    updatePos(*head_ptr);
    StudentNode* target = getNodeById(*head_ptr, target_id);
    if (target == NULL)
        return 0;

    deleteNodeByPos(head_ptr, target->position);
    updatePos(*head_ptr);
    return 1;
}

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

    ModifyID(target, id);
    ModifyRoomNum(target, roomNum);
    ModifyPhone(target, phone);
    ModifyName(target, name);
    ModifySex(target, sex);
    ModifyClass(target, stuClass);
    ModifyBirth(target, birth);
    ModifyHome(target, home);
    return 1;
}

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
    if (head_ptr == NULL || pos <= 0 || name == NULL || sex == NULL || stuClass == NULL || birth == NULL || home == NULL)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    return setStudentInfo(target, id, roomNum, name, sex, stuClass, birth, home, phone);
}

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
    if (head_ptr == NULL || name == NULL || sex == NULL || stuClass == NULL || birth == NULL || home == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    return setStudentInfo(target, id, roomNum, name, sex, stuClass, birth, home, phone);
}

int modifyStudentIdByPos(StudentNode* head_ptr, int pos, int id)
{
    if (head_ptr == NULL || pos <= 0)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    ModifyID(target, id);
    return 1;
}

int modifyStudentRoomNumByPos(StudentNode* head_ptr, int pos, int roomNum)
{
    if (head_ptr == NULL || pos <= 0)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    ModifyRoomNum(target, roomNum);
    return 1;
}

int modifyStudentPhoneByPos(StudentNode* head_ptr, int pos, int phone)
{
    if (head_ptr == NULL || pos <= 0)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    ModifyPhone(target, phone);
    return 1;
}

int modifyStudentNameByPos(StudentNode* head_ptr, int pos, const char* name)
{
    if (head_ptr == NULL || pos <= 0 || name == NULL)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    ModifyName(target, name);
    return 1;
}

int modifyStudentSexByPos(StudentNode* head_ptr, int pos, const char* sex)
{
    if (head_ptr == NULL || pos <= 0 || sex == NULL)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    ModifySex(target, sex);
    return 1;
}

int modifyStudentClassByPos(StudentNode* head_ptr, int pos, const char* stuClass)
{
    if (head_ptr == NULL || pos <= 0 || stuClass == NULL)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    ModifyClass(target, stuClass);
    return 1;
}

int modifyStudentBirthByPos(StudentNode* head_ptr, int pos, const char* birth)
{
    if (head_ptr == NULL || pos <= 0 || birth == NULL)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    ModifyBirth(target, birth);
    return 1;
}

int modifyStudentHomeByPos(StudentNode* head_ptr, int pos, const char* home)
{
    if (head_ptr == NULL || pos <= 0 || home == NULL)
        return 0;

    updatePos(head_ptr);
    StudentNode* target = getNodeByPos(head_ptr, pos);
    if (target == NULL)
        return 0;

    ModifyHome(target, home);
    return 1;
}

int modifyStudentIdById(StudentNode* head_ptr, int target_id, int id)
{
    if (head_ptr == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    ModifyID(target, id);
    return 1;
}

int modifyStudentRoomNumById(StudentNode* head_ptr, int target_id, int roomNum)
{
    if (head_ptr == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    ModifyRoomNum(target, roomNum);
    return 1;
}

int modifyStudentPhoneById(StudentNode* head_ptr, int target_id, int phone)
{
    if (head_ptr == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    ModifyPhone(target, phone);
    return 1;
}

int modifyStudentNameById(StudentNode* head_ptr, int target_id, const char* name)
{
    if (head_ptr == NULL || name == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    ModifyName(target, name);
    return 1;
}

int modifyStudentSexById(StudentNode* head_ptr, int target_id, const char* sex)
{
    if (head_ptr == NULL || sex == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    ModifySex(target, sex);
    return 1;
}

int modifyStudentClassById(StudentNode* head_ptr, int target_id, const char* stuClass)
{
    if (head_ptr == NULL || stuClass == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    ModifyClass(target, stuClass);
    return 1;
}

int modifyStudentBirthById(StudentNode* head_ptr, int target_id, const char* birth)
{
    if (head_ptr == NULL || birth == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    ModifyBirth(target, birth);
    return 1;
}

int modifyStudentHomeById(StudentNode* head_ptr, int target_id, const char* home)
{
    if (head_ptr == NULL || home == NULL)
        return 0;

    StudentNode* target = getNodeById(head_ptr, target_id);
    if (target == NULL)
        return 0;

    ModifyHome(target, home);
    return 1;
}

StudentNode* queryStudentByPos(StudentNode* head_ptr, int pos)
{
    if (head_ptr == NULL || pos <= 0)
        return NULL;

    updatePos(head_ptr);
    return getNodeByPos(head_ptr, pos);
}

StudentNode* queryStudentById(StudentNode* head_ptr, int target_id)
{
    if (head_ptr == NULL)
        return NULL;

    return getNodeById(head_ptr, target_id);
}

void printStudent(const StudentInfo* info)
{
    if (info == NULL)
        return;

    printf("%-8s %-10s %-12s %-6s %-15s %-12s %-15s %-12s\n",
           "ID", "Room", "Name", "Sex", "Class", "Birth", "Home", "Phone");
    printf("%-8d %-10d %-12s %-6s %-15s %-12s %-15s %-12d\n",
           info->id,
           info->stuRoomNum,
           info->stuName ? info->stuName : "",
           info->stuSex ? info->stuSex : "",
           info->stuClass ? info->stuClass : "",
           info->stuBirth ? info->stuBirth : "",
           info->stuHome ? info->stuHome : "",
           info->stuPhone);
}

void printStudentNode(const StudentNode* node)
{
    if (node == NULL)
        return;

    printf("\n");
    printf("%-8s %-10s %-12s %-6s %-15s %-12s %-15s %-12s\n",
           "Pos", "ID", "Name", "Sex", "Class", "Birth", "Home", "Phone");
    printf("----------------------------------------------------------------------------------------\n");
    printf("%-8d %-10d %-12s %-6s %-15s %-12s %-15s %-12d\n",
           node->position,
           node->info.id,
           node->info.stuName ? node->info.stuName : "",
           node->info.stuSex ? node->info.stuSex : "",
           node->info.stuClass ? node->info.stuClass : "",
           node->info.stuBirth ? node->info.stuBirth : "",
           node->info.stuHome ? node->info.stuHome : "",
           node->info.stuPhone);
    printf("----------------------------------------------------------------------------------------\n");
    printf("\n");
}

static void printStudentCallback(StudentNode* currentNode, void* context)
{
    (void)context;
    printf("%-8d %-10d %-12s %-6s %-15s %-12s %-15s %-12d\n",
           currentNode->position,
           currentNode->info.id,
           currentNode->info.stuName ? currentNode->info.stuName : "",
           currentNode->info.stuSex ? currentNode->info.stuSex : "",
           currentNode->info.stuClass ? currentNode->info.stuClass : "",
           currentNode->info.stuBirth ? currentNode->info.stuBirth : "",
           currentNode->info.stuHome ? currentNode->info.stuHome : "",
           currentNode->info.stuPhone);
}

void listStudents(StudentNode* head_ptr)
{
    if (head_ptr == NULL)
    {
        printf("No students in the list.\n");
        return;
    }

    updatePos(head_ptr);
    
    printf("\n");
    printf("%-8s %-10s %-12s %-6s %-15s %-12s %-15s %-12s\n",
           "Pos", "ID", "Name", "Sex", "Class", "Birth", "Home", "Phone");
    printf("----------------------------------------------------------------------------------------\n");
    
    IterateOverList(head_ptr, printStudentCallback, NULL);
    
    printf("----------------------------------------------------------------------------------------\n");
    printf("Total: %d student(s)\n", getCount(head_ptr));
    printf("\n");
}

int saveStudentListToFile(const char* filename, StudentNode* head_ptr)
{
    if (filename == NULL)
        return 0;

    return save_student_to_file((char*)filename, head_ptr) == 0 ? 1 : 0;
}

int loadStudentListFromFile(const char* filename, StudentNode** head_ptr)
{
    if (filename == NULL || head_ptr == NULL)
        return 0;

    StudentNode* newHead = NULL;
    if (load_student_from_file((char*)filename, &newHead) != 0)
        return 0;

    if (*head_ptr != NULL)
        listFree(head_ptr);

    *head_ptr = newHead;
    updatePos(*head_ptr);
    return 1;
}
