//
// Created by P7XXTM1-G on 2021/11/16.
//

#ifndef HELLO_C_LINKSTACK_H
#define HELLO_C_LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

typedef int ElemType;

typedef struct LinkStackNode {
    ElemType data;
    struct LinkStackNode *next;
} LinkStackNode;
typedef LinkStackNode *LinkStack;

void InitStack_LS(LinkStack *linkStack);

void DestroyStack_LS(LinkStack *linkStack);

Status StackEmpty_LS(LinkStack linkStack);

Status Push_LS(LinkStack *linkStack, ElemType elem);

Status Pop_LS(LinkStack *linkStack, ElemType elem);

Status GetTop_LS(LinkStack linkStack, ElemType *elem);

#endif //HELLO_C_LINKSTACK_H
