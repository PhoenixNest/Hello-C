//
// Created by P7XXTM1-G on 2021/11/17.
//

#include "StraightInsertSort.h"

// 直接插入排序
// 最好的时间复杂度：O(n)
// 最差的时间复杂度：O(n^2)
// 空间复杂度：O(1)
void StraightInsertSort(RecordList *list) {
    int pos, j;
    for (pos = 0; pos < list->length; ++pos) {
        if (list->base[pos + 1].value < list->base[pos].value) {
            list->base[0] = list->base[pos + 1];
            j = pos + 1;

            do {
                j--;
                list->base[j + 1] = list->base[j];
            } while (list->base[0].value < list->base[j - 1].value);

            list->base[j] = list->base[0];
        }
    }
}
