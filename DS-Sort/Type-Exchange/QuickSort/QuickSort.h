//
// Created by P7XXTM1-G on 2021/11/20.
//

#ifndef HELLO_C_QUICKSORT_H
#define HELLO_C_QUICKSORT_H

#include "RecordList/RecordList.h"

int Partition(RecordElemType array[], int low, int high);

void QSort(RecordElemType array[], int low, int high);

void QuickSort(RecordList *list);

#endif //HELLO_C_QUICKSORT_H
