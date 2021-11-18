//
// Created by P7XXTM1-G on 2021/11/17.
//

#ifndef HELLO_C_SHELLSORT_H
#define HELLO_C_SHELLSORT_H

#include <stdio.h>
#include <stdlib.h>

#include "RecordType/RecordType.h"
#include "RecordList/RecordList.h"

void ShellInsert(RecordList *list, int gap);

void ShellSort(RecordList *list, int gapArray[], int gapArraySize);

#endif //HELLO_C_SHELLSORT_H
