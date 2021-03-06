//
// Created by P7XXTM1-G on 2021/11/16.
//

#include "DuelLinkList.h"

// 双向链表

// 在 p结点 前插入 q结点
Status InsertBefore_DuL(DuelLinkListNode *p, DuelLinkListNode *q) {
    if (p == NULL || q == NULL || p->prior == NULL) {
        return ERROR;
    }

    q->prior = p->prior;
    q->next = p;
    q->prior->next = p;
    p->prior = q;

    return OK;
}

// 删除 指针p 所指向的结点，并用 参数e 返回 p结点 的元素值
Status Delete_DuL(DuelLinkListNode *p, ElemType elem) {
    if (p == NULL || p->prior == NULL) {
        return ERROR;
    }

    if (p->next != NULL) {
        p->next->prior = p->prior;
    }

    p->prior->next = p->next;

    elem = p->data;

    free(p);

    return OK;
}