//
// Created by P7XXTM1-G on 2021/11/14.
//

#include "SqQueue.h"
#include "Status.h"

#define MaxSize 100

Status InitQueue_Sq(SqQueue *sqQueue, int size) {
    sqQueue->base = (ElemType *) malloc(size * sizeof(ElemType));

    if (NULL == sqQueue->base) {
        return OVERFLOW;
    }

    sqQueue->size = size;
    sqQueue->front = sqQueue->rear = 0;

    return OK;
}

Status QueueEmpty_Sq(SqQueue sqQueue) {
    if (sqQueue.rear == sqQueue.front) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int QueueLength_Sq(SqQueue sqQueue) {
    return QueueEmpty_Sq(sqQueue) ?
           0 : (sqQueue.rear - sqQueue.front + MaxSize) % MaxSize;
}

Status GetHead_Sq(SqQueue sqQueue, ElemType *elem) {
    QueueEmpty_Sq(sqQueue);

    *elem = sqQueue.base[sqQueue.front];

    return OK;
}

Status EnQueue_Sq(SqQueue *sqQueue, ElemType elem) {
    if ((sqQueue->rear + 1) % sqQueue->size == sqQueue->front) {
        return ERROR;
    }

    sqQueue->base[sqQueue->rear] = elem;
    sqQueue->rear = (sqQueue->rear + 1) % sqQueue->size;

    return OK;
}

Status DeQueue_Sq(SqQueue *sqQueue, ElemType *elem) {
    if (sqQueue->front == sqQueue->rear) {
        return ERROR;
    }

    *elem = sqQueue->base[sqQueue->front];
    sqQueue->front = (sqQueue->front + 1) % sqQueue->size;

    return OK;
}