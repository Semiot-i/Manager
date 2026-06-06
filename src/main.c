//
// Created by ASUS on 2026/6/3.
//
#include "common.h"
#include "core/student_list.h"
#include "core/student_process.h"
#include "app/app_window.h"

int main()
{
    // initialize core data
    listInit();
    // run GUI (blocks until window closed)
    app_run();
    // cleanup
    listFree();
    return 0;
}