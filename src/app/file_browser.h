#ifndef FILE_BROWSER_H
#define FILE_BROWSER_H

#include "../include/common.h"
#include "../core/command.h"

void fileBrowserShow(void);
char* fileBrowserGetFilePath(void);
int fileBrowserLoadFile(StudentNode** head_ptr);
int fileBrowserSaveFile(StudentNode* head_ptr);

#endif
