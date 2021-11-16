include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(LinkList LinkList.h LinkList.c LinkList-main.c)

target_link_libraries(LinkList Scanf_lib)