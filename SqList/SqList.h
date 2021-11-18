//
// Created by P7XXTM1-G on 2021/11/15.
//

#ifndef HELLO_C_SQLIST_H
#define HELLO_C_SQLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "Status.h"

typedef int ElemType;

typedef struct {
    ElemType *base;
    int length;
    int size;
    int increment;
} SqList;

Status InitList_Sq(SqList *sqList, int size, int increment);

Status DestroyList(SqList *sqList);

Status ClearList_Sq(SqList *sqList);

Status ListEmpty_Sq(SqList sqList);

int ListLength(SqList sqList);

Status GetElem_Sq(SqList sqList, int position, ElemType *elem);

int Search_Sq(SqList sqList, ElemType elem);

void ListTraverse_Sq(SqList sqList, void(*visit)(ElemType elem));

Status PutElem_Sq(SqList *sqList, int i, ElemType elem);

Status Append_Sq(SqList *sqList, ElemType elem); // 表尾追加

Status Insert_Sq(SqList *sqList, int position, ElemType elem); // 表内插入

Status DeleteLast_Sq(SqList *sqList, ElemType *elem);

#endif //HELLO_C_SQLIST_H
