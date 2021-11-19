include_directories(${CMAKE_SOURCE_DIR}/static)

add_executable(DuelLinkList DuelLinkList.h DuelLinkList.c DuelLinkList-main.c)

target_link_libraries(DuelLinkList Scanf_lib)