//
// Created by P7XXTM1-G on 2021/11/13.
//

#include "SqStack.h"

Status InitStack_Sq(SqStack *sqStack, int size, int increment) {
    sqStack->elem = (ElemType *) malloc(size * sizeof(ElemType));

    if (sqStack->elem == NULL) { return OVERFLOW; }

    sqStack->top = 0;
    sqStack->size = size;
    sqStack->increment = increment;

    return OK;
}

Status DestroyStack_Sq(SqStack *sqStack) {
    if (sqStack == NULL) {
        return ERROR;
    }

    free(sqStack->elem);

    sqStack->elem = NULL;
    sqStack->top = NULL;
    sqStack->size = 0;

    return OK;
}

Status StackEmpty_Sq(SqStack sqStack) {
    if (&sqStack.top == sqStack.elem) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void ClearStack_Sq(SqStack *sqStack) {

    StackEmpty_Sq(*sqStack);

    sqStack->top = *sqStack->elem;
}

Status Push_Sq(SqStack *sqStack, ElemType elem) {
    ElemType *newBase;
    if (sqStack->top >= sqStack->size) {
        newBase = (ElemType *) realloc(sqStack->elem, ((*sqStack).size + sqStack->increment) * sizeof(ElemType));

        if (NULL == newBase) return OVERFLOW;

        sqStack->elem = newBase;
        sqStack->size += sqStack->increment;
    }
    sqStack->elem[(sqStack->top)++] = elem;
    return OK;
}

Status Pop_Sq(SqStack *sqStack, ElemType *elem) {
    if (StackEmpty_Sq(*sqStack)) {
        return ERROR;
    }

    *elem = sqStack->elem[--sqStack->top];
    sqStack->elem[--sqStack->top];
    return OK;
}

Status GetTop_Sq(SqStack sqStack, ElemType *elem) {
    if (StackEmpty_Sq(sqStack)) {
        return ERROR;
    }

    *elem = sqStack.elem[sqStack.top];
    return OK;
}