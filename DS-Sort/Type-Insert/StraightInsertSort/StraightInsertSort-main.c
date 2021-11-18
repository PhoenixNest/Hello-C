//
// Created by P7XXTM1-G on 2021/11/18.
//

#include "StraightInsertSort.h"

int main() {
    RecordList list;

    InitList_Rec(&list, 10);

    RecordElemType array[10] = {85, 56, 23, 98, 54, 74, 1, 4, 8, 31};

    for (int i = 0; i < 10; ++i) {
        Insert_Rec(&list, i, array[i]);
    }

    for (int i = 0; i < list.length; ++i) {
        printf("Current Num: %d \n", list.base->key);
    }

    return 0;
}