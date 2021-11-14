//
// Created by P7XXTM1-G on 2021/11/14.
//

#include "SqQueue.h"

#include "Status.h"

Status InitQueue_Sq(SqQueue *sqQueue, int size) {
    sqQueue->elem = (ElemType *) malloc(size * sizeof(ElemType));

    if (NULL == sqQueue->elem) { return OVERFLOW; }

    sqQueue->maxSize = size;
    sqQueue->front = sqQueue->rear = 0;

    return OK;
}

Status EnQueue_Sq(SqQueue *sqQueue, ElemType elem) {
    if (sqQueue->front == sqQueue->rear) { return ERROR; }

    sqQueue->elem[sqQueue->rear] = elem;

    return OK;
}

Status DeQueue_Sq(SqQueue *sqQueue, ElemType *elem) {
    if (sqQueue->front == sqQueue->rear) { return ERROR; }

    elem = &sqQueue->elem[sqQueue->front];
    sqQueue->rear = (sqQueue->rear + 1) % sqQueue->maxSize;

    return OK;
}