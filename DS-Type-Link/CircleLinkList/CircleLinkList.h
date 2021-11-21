//
// Created by P7XXTM1-G on 2021/11/17.
//

#ifndef HELLO_C_CIRCLELINKLIST_H
#define HELLO_C_CIRCLELINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"
#include "../LinkList/LinkList.h"

typedef int ElemType;

typedef LinkList CircleLinkList;

Status InitList_CL(CircleLinkList *circleLinkList);

Status DeleteAfter_CL(CircleLinkList circleLinkList, LinkListNode *p, ElemType *elem);

void Split(CircleLinkList *circleLinkListLO, CircleLinkList *circleLinkListLC, CircleLinkList *circleLinkListLL);

#endif //HELLO_C_CIRCLELINKLIST_H
