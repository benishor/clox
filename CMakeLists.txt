cmake_minimum_required(VERSION 3.18)
project(clox)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_C_STANDARD 11)

add_compile_options(
        -Wall
        -Wextra
        -Wconversion
        -Wsign-conversion
        $<$<CONFIG:DEBUG>:-g3>
        $<$<CONFIG:DEBUG>:-Og>
        $<$<CONFIG:RELEASE>:-O3>
)

add_compile_definitions(
        $<$<CONFIG:DEBUG>:DEBUG>
)
add_executable(clox main.c chunk.h chunk.c memory.h memory.c debug.h debug.c value.h value.c vm.h vm.c common.h compiler.h compiler.c scanner.h scanner.c object.h object.c table.h table.c)
