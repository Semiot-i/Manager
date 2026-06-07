cmake_minimum_required(VERSION 3.10)
project(StudentInfoSystem C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_executable(StudentInfoSystem
        src/main.c
        src/core/student_list.c
        src/core/student_list.h
        src/core/student_process.c
        src/core/student_process.h
        src/core/file_manager.c
        src/core/file_manager.h
        src/core/command.c
        src/core/command.h
        src/include/common.h
        src/app/app_window.c
        src/app/app_window.h
        src/app/file_browser.c
        src/app/file_browser.h
        src/app/student_editor.c
        src/app/student_editor.h
        )
