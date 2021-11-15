//
// Created by P7XXTM1-G on 2021/11/15.
//

#include "SqList.h"

Status InitList_Sq(SqList *sqList, int size, int increment) {
    sqList->base = (ElemType *) malloc(size * sizeof(ElemType));

    if (sqList->base == NULL) { return OVERFLOW; }

    sqList->size = size;
    sqList->increment = increment;

    return OK;
}

Status ListEmpty_Sq(SqList sqList) {
    return sqList.length == 0 ? TRUE : FALSE;
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

Status Insert_Sq(SqList *sqList, int position, ElemType elem) {
    ElemType *newBase;

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

    // 元素右移
    for (int i = sqList->length; i > position; i--) {
        sqList->base[i] = sqList->base[i - 1];
    }

    // 元素进表
    sqList->base[position] = elem;

    // 表长 +1
    ++sqList->length;

    return OK;
}

Status DeleteLast_Sq(SqList *sqList, ElemType *elem) {
    if (0 == sqList->length) { return ERROR; }

    *elem = sqList->base[sqList->length - 1];

    --sqList->length;

    return OK;
}
