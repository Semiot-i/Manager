#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include "../include/common.h"
#include "../core/command.h"

void appWindowInit(void);
void appWindowShowMenu(void);
int appWindowGetUserChoice(void);
void appWindowRun(void);
void appWindowCleanup(void);

#endif
