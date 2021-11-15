//
// Created by P7XXTM1-G on 2021/11/13.
//

#include "SqStack.h"

Status InitStack_Sq(SqStack *sqStack, int size, int increment) {
    sqStack->base = (ElemType *) malloc(size * sizeof(ElemType));

    if (sqStack->base == NULL) { return OVERFLOW; }

    sqStack->top = 0;
    sqStack->size = size;
    sqStack->increment = increment;

    return OK;
}

//Status DestroyStack_Sq(SqStack *sqStack) {
//    if (sqStack == NULL) {
//        return ERROR;
//    }
//
//    free(sqStack->base);
//
//    sqStack->base = NULL;
//    sqStack->top = NULL;
//    sqStack->size = 0;
//
//    return OK;
//}

Status StackEmpty_Sq(SqStack sqStack) {
    if (&sqStack.top == sqStack.base) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void ClearStack_Sq(SqStack *sqStack) {
    StackEmpty_Sq(*sqStack);

    sqStack->top = *sqStack->base;
}

Status Push_Sq(SqStack *sqStack, ElemType elem) {
    ElemType *newBase;
    if (sqStack->top >= sqStack->size) {
        newBase = (ElemType *) realloc(sqStack->base, ((*sqStack).size + sqStack->increment) * sizeof(ElemType));

        if (NULL == newBase) return OVERFLOW;

        sqStack->base = newBase;
        sqStack->size += sqStack->increment;
    }
    sqStack->base[(sqStack->top)++] = elem;
    return OK;
}

Status Pop_Sq(SqStack *sqStack, ElemType *elem) {
    if (StackEmpty_Sq(*sqStack)) {
        return ERROR;
    }

    *elem = sqStack->base[--(sqStack->top)];
    return OK;
}

Status GetTop_Sq(SqStack sqStack, ElemType *elem) {
    if (StackEmpty_Sq(sqStack)) {
        return 0;
    }

    *elem = sqStack.base[sqStack.top - 1];
    return OK;
}