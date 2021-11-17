add_executable(RecordType RecordType.h RecordType.c RecordType.h RecordList.c RecordList.h)

target_link_libraries(RecordType Scanf_lib)

add_subdirectory(StraightInsertSort)
add_subdirectory(ShellSort)