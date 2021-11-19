include_directories(${CMAKE_SOURCE_DIR}/static)

add_executable(SqQueue SqQueue.h SqQueue.c SqQueue-In-Use.h SqQueue-In-Use.c SqQueue-main.c)

target_link_libraries(SqQueue Scanf_lib)