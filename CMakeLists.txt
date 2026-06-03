cmake_minimum_required(VERSION 3.10)
project(for_review)

set(CMAKE_C_STANDARD 11)

include_directories("C:/Program Files/Microsoft Visual Studio/18/Community/VC/Auxiliary/VS/include")
link_directories("C:/Program Files/Microsoft Visual Studio/18/Community/VC/Auxiliary/VS/lib/x64")

add_executable(for_review src/trial.txt
        src/main.c)
