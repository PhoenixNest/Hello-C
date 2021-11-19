include_directories(${CMAKE_SOURCE_DIR}/static)

add_executable(LinkStack LinkStack.h LinkStack.c LinkStack-main.cpp)

target_link_libraries(LinkStack Scanf_lib)