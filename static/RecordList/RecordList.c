//
// Created by P7XXTM1-G on 2021/11/17.
//

#include "RecordList.h"

Status InitList_Rec(RecordList *recordList, int size) {
    recordList->base = (RecordElemType *) malloc(size * sizeof(RecordElemType));

    if (recordList->base == NULL) {
        return OVERFLOW;
    }

    recordList->length = 0;
    recordList->size = size;

    return OK;
}

void ListTraverse_Rec(RecordList sqList, void(*visit)(RecordElemType elem)) {
    for (int i = 0; i < sqList.length; i++) {
        visit(sqList.base[i]);
    }

    printf("\n");
}

Status Insert_Rec(RecordList *recordList, int position, RecordElemType elem) {
    RecordElemType *p, *q;

    if (recordList == NULL || recordList->base == NULL) {
        return ERROR;
    }

    if (position < 1 || position > recordList->length + 1) {
        return ERROR;
    }

    q = &recordList->base[position - 1];

    for (p = &recordList->base[recordList->length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }

    *q = elem;
    recordList->length++;

    return OK;
}
