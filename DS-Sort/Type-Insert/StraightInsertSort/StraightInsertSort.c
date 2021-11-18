//
// Created by P7XXTM1-G on 2021/11/17.
//

#include "StraightInsertSort.h"

void StraightInsertSort(RecordList *list) {
    int pos, j;
    for (pos = 0; pos < list->length; ++pos) {
        if (list->base[pos + 1].key < list->base[pos].key) {
            list->base[0] = list->base[pos + 1];
            j = pos + 1;

            do {
                j--;
                list->base[j + 1] = list->base[j];
            } while (list->base[0].key < list->base[j - 1].key);

            list->base[j] = list->base[0];
        }
    }
}
