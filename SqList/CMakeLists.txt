include_directories(${CMAKE_SOURCE_DIR}/static)

add_executable(SqList SqList.h SqList.c SqList-In-Use.h SqList-In-Use.c SqList-main.c)

target_link_libraries(SqList Scanf_lib)