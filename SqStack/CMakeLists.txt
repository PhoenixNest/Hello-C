include_directories(${CMAKE_SOURCE_DIR}/static)

add_executable(SqStack SqStack.h SqStack.c SqStack-In-Use.h SqStack-In-Use.c SqStack-main.c)

target_link_libraries(SqStack Scanf_lib)