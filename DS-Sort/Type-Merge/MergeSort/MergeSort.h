//
// Created by P7XXTM1-G on 2021/11/20.
//

#ifndef HELLO_C_MERGESORT_H
#define HELLO_C_MERGESORT_H

#include "RecordList/RecordList.h"

void Merge(RecordElemType array[], RecordElemType temp[], int low, int mid, int high);

void MSort(RecordElemType array[], RecordElemType temp[], int i, int low, int high);

void MergeSort(RecordList *recordList);

void MSort_iteration(RecordElemType array[], RecordElemType temp[], int size);

void MergeSort_iteration(RecordList *recordList);

#endif //HELLO_C_MERGESORT_H
