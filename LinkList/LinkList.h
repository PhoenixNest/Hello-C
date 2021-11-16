//
// Created by P7XXTM1-G on 2021/11/16.
//

#ifndef HELLO_C_LINKLIST_H
#define HELLO_C_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

typedef int ElemType;

typedef struct LinkListNode {
    ElemType data;
    struct LinkListNode *next;
} LinkListNode;

typedef LinkListNode *LinkList;

Status InitList_L(LinkList *linkList);

Status DestroyList_L(LinkList *linkList);

Status ClearList_L(LinkList *linkList);

Status ListEmpty_L(LinkList linkList);

int ListLength_L(LinkList linkList);

LinkListNode *Search_L(LinkList linkList, ElemType elem);

LinkListNode *NextElem_L(LinkListNode *pointer);

LinkListNode *MakeNode_L(ElemType elem);

Status InsertAfter_L(LinkListNode *p, LinkListNode *q);

Status DeleteAfter_L(LinkListNode *p, ElemType elem);

void ListTraverse_L(LinkList linkList, Status(*Visit)(ElemType elem));

#endif //HELLO_C_LINKLIST_H
