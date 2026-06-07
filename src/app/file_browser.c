#include "file_browser.h"
#include <stdio.h>
#include <stdlib.h>

static char filePath[256];

void fileBrowserShow(void) {
    printf("\n--- File Browser ---\n");
    printf("Default directory: %s\n", DEFAULT_DATA_DIR);
    printf("Enter file path (or press Enter for default): ", DEFAULT_DATA_DIR);
}

char* fileBrowserGetFilePath(void) {
    fgets(filePath, sizeof(filePath), stdin);
    size_t len = strlen(filePath);
    if (len > 0 && filePath[len - 1] == '\n') {
        filePath[len - 1] = '\0';
    }
    if (strlen(filePath) == 0) {
        snprintf(filePath, sizeof(filePath), "%s/students.txt", DEFAULT_DATA_DIR);
    }
    return filePath;
}

int fileBrowserLoadFile(StudentNode** head_ptr) {
    fileBrowserShow();
    char* path = fileBrowserGetFilePath();
    int result = loadStudentListFromFile(path, head_ptr);
    if (result == 1) {
        printf("File loaded successfully!\n");
    } else {
        printf("Failed to load file!\n");
    }
    return result;
}

int fileBrowserSaveFile(StudentNode* head_ptr) {
    fileBrowserShow();
    char* path = fileBrowserGetFilePath();
    int result = saveStudentListToFile(path, head_ptr);
    if (result == 1) {
        printf("File saved successfully!\n");
    } else {
        printf("Failed to save file!\n");
    }
    return result;
}
