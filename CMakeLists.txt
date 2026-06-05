cmake_minimum_required(VERSION 3.10)
project(for_review)

set(CMAKE_C_STANDARD 11)

include_directories("C:/Program Files/Microsoft Visual Studio/18/Community/VC/Auxiliary/VS/include"
                    ${CMAKE_SOURCE_DIR}/src/include)
# link_directories 不需要手动设置，CMake 会自动处理 Windows SDK 库路径

add_executable(for_review src/trial.txt
        src/main.c
        src/core/student_list.c
        src/core/student_list.h
        src/core/student.c
        src/core/student.h
        src/core/file_manager.c
        src/core/file_manager.h
        src/core/command.c
        src/core/command.h
        src/include/common.h
        src/app/app_window.c
        src/app/file_browser.c
        src/app/app_window.h
        src/app/file_browser.h
        src/app/student_editor.c
        src/app/student_editor.h
        src/app/settings.c
        src/app/settings.h
        src/utils/config.c
        src/utils/config.h
        src/utils/validator.c
        src/utils/validator.h
        src/utils/thread_pool.c
        src/utils/thread_pool.h)
