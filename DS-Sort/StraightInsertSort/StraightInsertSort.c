//
// Created by P7XXTM1-G on 2021/11/17.
//

#include "StraightInsertSort.h"

void StraightInsertSort(RecordList *list) {
    int pos, j;
    for (pos = 0; pos < list->length; ++pos) {
        if (list->recordElem[pos + 1].key < list->recordElem[pos].key) {
            list->recordElem[0] = list->recordElem[pos + 1];
            j = pos + 1;

            do {
                j--;
                list->recordElem[j + 1] = list->recordElem[j];
            } while (list->recordElem[0].key < list->recordElem[j - 1].key);

            list->recordElem[j] = list->recordElem[0];
        }
    }
}
