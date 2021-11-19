//
// Created by P7XXTM1-G on 2021/11/17.
//

#include "ShellSort.h"

void ShellInsert(RecordList *list, int gap) {
    int i, j;
    for (i = 0; i < list->length - gap; ++i) {
        if (list->base[i + gap].key < list->base[i].key) {
            list->base[0] = list->base[i + gap];
            j = i + gap;
        }

        do {
            j -= gap;
            list->base[j + gap] = list->base[j];
        } while (j - gap > 0 && list->base[0].key < list->base[j - gap].key);

        list->base[j] = list->base[0];
    }
}

void ShellSort(RecordList *list, int gapArray[], int gapArraySize) {
    for (int i = 0; i < gapArraySize; ++i) {
        ShellInsert(list, gapArray[i]);
    }
}
