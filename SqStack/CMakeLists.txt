include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(SqStack SqStack.h SqStack.c SqStack-main.c)

target_link_libraries(SqStack Scanf_lib)