cmake_minimum_required(VERSION 3.10)
project(StudentInfoSystem C)

set(CMAKE_C_STANDARD 11)

# 手动指定 pkg-config 路径（Windows + MSYS64）
set(PKG_CONFIG_EXECUTABLE "C:/msys64/mingw64/bin/pkg-config.exe" CACHE FILEPATH "pkg-config executable")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
link_directories(${GTK4_LIBRARY_DIRS})

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
        src/utils/config.c
        src/utils/config.h
        src/utils/validator.c
        src/utils/validator.h
        src/utils/logger.c
        src/utils/logger.h)

target_link_libraries(StudentInfoSystem ${GTK4_LIBRARIES})

target_compile_options(StudentInfoSystem PUBLIC ${GTK4_CFLAGS_OTHER})