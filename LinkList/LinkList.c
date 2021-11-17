//
// Created by P7XXTM1-G on 2021/11/16.
//

#include "LinkList.h"

// 单链表

// 初始化一个只带头结点的单链表
Status InitList_L(LinkList *linkList) {
    if (NULL == (*linkList = (LinkListNode *) malloc(sizeof(LinkListNode)))) {
        return OVERFLOW;
    }

    (*linkList)->next = NULL;
    return OK;
}

// 从 数组A 中生成单链表
Status CreateList_L(LinkList *linkList, int num, ElemType *array) {
    LinkListNode *prior, *after;
    if (OVERFLOW == InitList_L(linkList)) {
        return OVERFLOW;
    }

    prior = *linkList;
    for (int i = 0; i < num; i++) {
        after = MakeNode_L(array[i]);
        InsertAfter_L(prior, after);
        prior = after;
    }

    return OK;
}

// 查找表中数据域值为 recordElem 的元素的节点地址
LinkListNode *Search_L(LinkList linkList, ElemType elem) {
    LinkListNode *node;
    if (NULL == linkList) {
        return NULL;
    }

    node = linkList->next;

    while (node != NULL && node->data != elem) {
        node = node->next;
    }

    return node;
}

// 求后继
LinkListNode *NextElem_L(LinkListNode *pointer) {
    if (NULL == pointer) {
        return NULL;
    }

    return pointer->next;
}

// 构造结点
LinkListNode *MakeNode_L(ElemType elem) {
    LinkListNode *node;

    node = (LinkListNode *) malloc(sizeof(LinkListNode));
    if (node != NULL) {
        node->data = elem;
        node->next = NULL;
    }

    return node;

}

// 在 p结点 后插入 q结点
Status InsertAfter_L(LinkListNode *p, LinkListNode *q) {
    if (NULL == p || NULL == q) {
        return ERROR;
    }

    // 修改 q结点 的指针域
    q->next = p->next;

    // 修改 p结点 的指针域
    p->next = q;

    return OK;
}

// 删除 p结点 的直接后继结点，并用参数 recordElem 返回被删除结点的值
Status DeleteAfter_L(LinkListNode *p, ElemType elem) {
    LinkListNode *q;
    if (NULL == p || NULL == p->next) {
        return ERROR;
    }

    q = p->next;
    p->next = q->next;
    elem = q->data;

    free(q);

    return OK;
}

// 逆置
void InverseList(LinkList linkList) {
    LinkListNode *p, *q;
    if (NULL == linkList->next || NULL == linkList->next->next) {
        return;
    }

    p = linkList->next;
    linkList->next = NULL;

    while (p != NULL) {
        q = p->next;
        InsertAfter_L(linkList, p);
        p = q;
    }
}

// 有序单链表合并
void MergeList_L(LinkList *linkListA, LinkList *linkListB, LinkList *linkListC) {
    // 将 升序单链表A 和 B 归并为新的 单链表C
    LinkList pa, pb, pc, temp;
    pa = (*linkListA)->next;
    pb = (*linkListB)->next;

    // 使用 A 的头结点作为 C 的头结点
    *linkListC = pc = *linkListA;

    // 依次处理 A 和 B 的当前结点
    while (pa && pb) {
        // 将 pA 结点插入 C
        if (pa->data <= pb->data) {
            // temp 指向 A 中下一个待处理结点
            temp = pa->next;

            // 将 pA 结点插入 C 表表尾
            InsertAfter_L(pc, pa);

            // 令 pC 指向 pA 结点
            pc = pa;
            pa = temp;
        } else {
            temp = pb->next;
            InsertAfter_L(pc, pb);
            pc = pb;
            pb = temp;
        }

        // 插入 A 和 B 中剩余结点
        pc->next = pa ? pa : pb;

        free(*linkListB);
    }
}