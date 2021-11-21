//
// Created by P7XXTM1-G on 2021/11/17.
//

#include "ShellSort.h"

void ShellInsert(RecordList *list, int gap) {
    int i, j;
    for (i = 0; i < list->length - gap; ++i) {
        if (list->base[i + gap].value < list->base[i].value) {
            list->base[0] = list->base[i + gap];
            j = i + gap;
        }

        // 记录后移
        do {
            j -= gap;
            list->base[j + gap] = list->base[j];
        } while (j - gap > 0 && list->base[0].value < list->base[j - gap].value);

        // 将待插入记录放到合适位置
        list->base[j] = list->base[0];
    }
}

// 希尔排序
// 时间复杂度约：O(n^1.3)
// 空间复杂度：O(1)
void ShellSort(RecordList *list, int gapArray[], int gapArraySize) {
    for (int i = 0; i < gapArraySize; ++i) {
        ShellInsert(list, gapArray[i]);
    }
}
