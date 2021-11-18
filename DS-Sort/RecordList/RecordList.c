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

Status Append_Sq(RecordList *recordList, RecordElemType elem) {
    RecordElemType *newBase;
    if (recordList->length >= recordList->size) {
        newBase = (RecordElemType *) realloc(recordList->base,
                                             ((*recordList).size + recordList->increment) * sizeof(ElemType));

        if (NULL == newBase) {
            return OVERFLOW;
        }

        recordList->base = newBase;
    }

    recordList->base[recordList->length] = elem;
    return OK;
}

Status Insert_Rec(RecordList *recordList, int position, RecordElemType elem) {
    RecordElemType *newBase;
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
