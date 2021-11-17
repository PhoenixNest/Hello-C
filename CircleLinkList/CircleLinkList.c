//
// Created by P7XXTM1-G on 2021/11/17.
//

#include "CircleLinkList.h"

// 单循环链表

Status InitList_CL(CircleLinkList *circleLinkList) {
    if (NULL == (*circleLinkList = (LinkListNode *) malloc(sizeof(LinkListNode)))) {
        return OVERFLOW;
    }

    (*circleLinkList)->next = NULL;

    return OK;
}

Status DeleteAfter_CL(CircleLinkList circleLinkList, LinkListNode *p, ElemType *elem) {
    LinkListNode *q;

    if (circleLinkList == (*circleLinkList).next) {
        return ERROR;
    }

    if (p->next == circleLinkList) {
        p = circleLinkList;
    }

    q = p->next;
    p->next = q->next;
    *elem = q->data;

    free(q);

    return OK;
}

void Split(CircleLinkList *circleLinkListLO, CircleLinkList *circleLinkListLC, CircleLinkList *circleLinkListLL) {
    char text;
    CircleLinkList po, pc, pl;
    po = (*circleLinkListLO)->next;
    circleLinkListLC = circleLinkListLO;

    InitList_CL(circleLinkListLL);
    pc = *circleLinkListLC;
    pl = *circleLinkListLL;

    while (po != *circleLinkListLO) {
        text = po->data;
        if (text >= 'A' && text <= 'Z') {
            pc->next = po;
            pl = po;
        } else {
            pl->next = po;
            pl = po;
        }

        po = po->next;
    }

    pc->next = *circleLinkListLC;
    pl->next = *circleLinkListLL;
}