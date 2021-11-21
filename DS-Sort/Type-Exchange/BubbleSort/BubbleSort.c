//
// Created by P7XXTM1-G on 2021/11/20.
//

#include "BubbleSort.h"

void BubbleSort(RecordList *recordList) {
    int i, j;
    RecordElemType temp;
    Status flag = TRUE;

    for (i = 1; i < recordList->length && flag; ++i) {
        flag = FALSE;
        for (j = 0; j < recordList->length - i; ++j) {
            if (recordList->base[j + 1].value < recordList->base[j].value) {
                temp.value = recordList->base[j + 1].value;
                recordList->base[j + 1].value = recordList->base[j].value;
                recordList->base[j] = temp;

                flag = TRUE;
            }
        }
    }
}