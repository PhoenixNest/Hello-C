include_directories(${CMAKE_SOURCE_DIR}/DS-Sort)

add_executable(StraightInsertSort StraightInsertSort.h StraightInsertSort.c)

target_link_libraries(StraightInsertSort Scanf_lib)
