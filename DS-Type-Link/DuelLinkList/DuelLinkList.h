//
// Created by P7XXTM1-G on 2021/11/16.
//

#ifndef HELLO_C_DUELLINKLIST_H
#define HELLO_C_DUELLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"

typedef int ElemType;

typedef struct DuelLinkListNode {
    ElemType data;
    struct DuelLinkListNode *prior, *next;
} DuelLinkListNode;

typedef DuelLinkListNode *DuelLinkList;

Status InitLIst_DuL(DuelLinkList *duelLinkList);

Status DestroyList_DuL(DuelLinkList *duelLinkList);

Status ClearList_DuL(DuelLinkList duelLinkList);

Status ListEmpty_DuL(DuelLinkList duelLinkList);

int ListLength_DuL(DuelLinkList duelLinkList);

DuelLinkListNode *Search_DuL(DuelLinkList duelLinkList, ElemType elem);

DuelLinkListNode *PriorElem_DuL(DuelLinkListNode *node);

DuelLinkListNode *NextElem_DuL(DuelLinkListNode *node);

DuelLinkListNode *MakeNode_DuL(ElemType elem);

Status InsertBefore_DuL(DuelLinkListNode *p, DuelLinkListNode *q);

Status InsertAfter_DuL(DuelLinkListNode *p, DuelLinkListNode *q);

Status Delete_DuL(DuelLinkListNode *p, ElemType elem);

void ListTraverse_DuL(DuelLinkList duelLinkList, Status(*Visit)(ElemType elem));

#endif //HELLO_C_DUELLINKLIST_H
