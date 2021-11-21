//
// Created by P7XXTM1-G on 2021/11/16.
//

#include "LinkQueue.h"

Status EnQueue_LQ(LinkQueue *linkQueue, ElemType elem) {
    LinkQueueNode *node;

    node = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if (node == NULL) {
        return OVERFLOW;
    }

    node->data = elem;
    node->next = NULL;

    if (linkQueue->front == NULL) {
        linkQueue->front = node;
    } else {
        linkQueue->rear->next = node;
    }

    linkQueue->rear = node;

    return OK;
}

Status DeQueue_LQ(LinkQueue *linkQueue, ElemType *elem) {
    LinkQueueNode *node;
    if (linkQueue->front == NULL) {
        return ERROR;
    }

    node = linkQueue->front;
    *elem = node->data;
    linkQueue->front = node->next;

    if (linkQueue->rear == node) {
        linkQueue->rear = NULL;
    }

    free(node);

    return OK;
}