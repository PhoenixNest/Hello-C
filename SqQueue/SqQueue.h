//
// Created by P7XXTM1-G on 2021/11/14.
//

#ifndef HELLO_C_SQQUEUE_H
#define HELLO_C_SQQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"

typedef int ElemType;

typedef struct {
    ElemType *base;
    int front;
    int rear;
    int size;
} SqQueue;

Status InitQueue_Sq(SqQueue *sqQueue, int size);

Status DestroyQueue_Sq(SqQueue *SqQueue);

void ClearQueue_Sq(SqQueue *sqQueue);

Status QueueEmpty_Sq(SqQueue sqQueue);

int QueueLength_Sq(SqQueue sqQueue);

Status GetHead_Sq(SqQueue sqQueue, ElemType *elem);

Status EnQueue_Sq(SqQueue *sqQueue, ElemType elem);

Status DeQueue_Sq(SqQueue *sqQueue, ElemType *elem);

#endif //HELLO_C_SQQUEUE_H
