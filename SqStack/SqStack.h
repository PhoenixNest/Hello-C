//
// Created by P7XXTM1-G on 2021/11/13.
//

#ifndef HELLO_C_SQSTACK_H
#define HELLO_C_SQSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"

typedef int ElemType;

typedef struct {
    ElemType *base;
    int top;
    int size;
    int increment;
} SqStack;

Status InitStack_Sq(SqStack *sqStack, int size, int increment);

Status DestroyStack_Sq(SqStack *sqStack);

Status StackEmpty_Sq(SqStack sqStack);

void ClearStack_Sq(SqStack *sqStack);

Status Push_Sq(SqStack *sqStack, ElemType elem);

Status Pop_Sq(SqStack *sqStack, ElemType *elem);

Status GetTop_Sq(SqStack sqStack, ElemType *elem);

#endif //HELLO_C_SQSTACK_H
