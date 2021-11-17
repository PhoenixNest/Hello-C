include_directories(${CMAKE_SOURCE_DIR}/DS-Sort)

add_executable(ShellSort ShellSort.h ShellSort.c)

target_link_libraries(ShellSort Scanf_lib)