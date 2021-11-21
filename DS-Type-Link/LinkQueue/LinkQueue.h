//
// Created by P7XXTM1-G on 2021/11/16.
//

#ifndef HELLO_C_LINKQUEUE_H
#define HELLO_C_LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"

typedef int ElemType;

typedef struct LinkQueueNode {
    ElemType data;
    struct LinkQueueNode *next;
} LinkQueueNode, *LinkQueueNodePointer;

typedef struct {
    LinkQueueNodePointer front;
    LinkQueueNodePointer rear;
} LinkQueue;

void InitQueue_LQ(LinkQueue *linkQueue);

void DestroyQueue_LQ(LinkQueue *linkQueue);

Status QueueEmpty_LQ(LinkQueue linkQueue);

int QueueLength_LQ(LinkQueue linkQueue);

Status GetHead_LQ(LinkQueue linkQueue, ElemType *elem);

Status EnQueue_LQ(LinkQueue *linkQueue, ElemType elem);

Status DeQueue_LQ(LinkQueue *linkQueue, ElemType *elem);

#endif //HELLO_C_LINKQUEUE_H
