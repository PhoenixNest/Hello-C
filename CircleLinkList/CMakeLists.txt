include_directories(${CMAKE_SOURCE_DIR}/static)

add_executable(CircleLinkList CircleLinkList.h CircleLinkList.c CircleLinkList-main.c)

target_link_libraries(CircleLinkList Scanf_lib)