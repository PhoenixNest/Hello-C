include_directories(${CMAKE_SOURCE_DIR}/static)

add_executable(LinkStack LinkStack.h LinkStack.c LinkStack-main.c)

target_link_libraries(LinkStack Scanf_lib)