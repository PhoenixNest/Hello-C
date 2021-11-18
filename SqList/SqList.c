//
// Created by P7XXTM1-G on 2021/11/15.
//

#include "SqList.h"

Status InitList_Sq(SqList *sqList, int size, int increment) {
    sqList->base = (ElemType *) malloc(size * sizeof(ElemType));

    if (sqList->base == NULL) {
        return OVERFLOW;
    }

    sqList->length = 0;
    sqList->size = size;
    sqList->increment = increment;

    return OK;
}

Status ClearList_Sq(SqList *sqList) {
    if (sqList == NULL || sqList->base == NULL) {
        return ERROR;
    }

    sqList->length = 0;

    return OK;
}

Status ListEmpty_Sq(SqList sqList) {
    return sqList.length == 0 ? TRUE : FALSE;
}

int ListLength(SqList sqList) {
    return sqList.length;
}

int Search_Sq(SqList sqList, ElemType elem) {
    int elemPosition = 0;
    while (elemPosition < sqList.length && sqList.base[elemPosition] != elem) {
        elemPosition++;
    }

    if (elemPosition < sqList.length) {
        return elemPosition;
    } else {
        return -1;
    }

    // for (int i = 0; i < sqList.length; i++) {
    //     if(elem == sqList.base[i]){
    //         return i;
    //     }
    // }
    //
    // return -1;
}

Status Append_Sq(SqList *sqList, ElemType elem) {
    ElemType *newBase;
    if (sqList->length >= sqList->size) {
        newBase = (ElemType *) realloc(sqList->base, ((*sqList).size + sqList->increment) * sizeof(ElemType));

        if (NULL == newBase) {
            return OVERFLOW;
        }

        sqList->base = newBase;
        sqList->size += sqList->increment;
    }

    sqList->base[sqList->length] = elem;
    return OK;
}

void ListTraverse_Sq(SqList sqList, void(*visit)(ElemType elem)) {
    for (int i = 0; i < sqList.length; i++) {
        visit(sqList.base[i]);
    }
}

Status Insert_Sq(SqList *sqList, int position, ElemType elem) {
    ElemType *newBase;
    ElemType *p, *q;

    // 检查表结构是否存在
    if (sqList == NULL || sqList->base == NULL) {
        return ERROR;
    }

    // 插入位置越界
    if (position < 1 || position > sqList->length + 1) {
        return ERROR;
    }

    // 表满，扩容
    if (sqList->length >= sqList->size) {
        newBase = (ElemType *) realloc(sqList->base, (sqList->size + sqList->increment) * sizeof(ElemType));
        if (newBase == NULL) {
            return OVERFLOW;
        }

        sqList->base = newBase;
        sqList->size += sqList->increment;
    }

    q = &sqList->base[position - 1];

    // 1.右移元素，腾出位置
    for (p = &sqList->base[sqList->length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }

    // 2.元素进表
    *q = elem;

    // 3.表长+1
    sqList->length++;

    return OK;
}

Status DeleteLast_Sq(SqList *sqList, ElemType *elem) {
    if (sqList->length == 0) {
        return ERROR;
    }

    *elem = sqList->base[sqList->length - 1];

    --sqList->length;

    return OK;
}
