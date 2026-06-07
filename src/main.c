#include "include/common.h"
#include "core/student_list.h"
#include "app/app_window.h"
#include "app/student_editor.h"
#include "app/file_browser.h"

int main()
{
    appWindowInit();
    
    int running = 1;
    while (running) {
        appWindowShowMenu();
        int choice = appWindowGetUserChoice();
        
        switch (choice) {
            case 1:
                studentEditorHandleAdd(&GlobalListHead_p);
                break;
            case 2:
                studentEditorHandleDelete(&GlobalListHead_p);
                break;
            case 3:
                studentEditorHandleModify(GlobalListHead_p);
                break;
            case 4:
                studentEditorHandleQuery(GlobalListHead_p);
                break;
            case 5:
                studentEditorListAll(GlobalListHead_p);
                break;
            case 6:
                fileBrowserLoadFile(&GlobalListHead_p);
                break;
            case 7:
                fileBrowserSaveFile(GlobalListHead_p);
                break;
            case 0:
                running = 0;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    appWindowCleanup();
    return 0;
}