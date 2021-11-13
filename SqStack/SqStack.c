//
// Created by P7XXTM1-G on 2021/11/13.
//

#include "SqStack.h"

Status InitStack_Sq(SqStack sqStack, int size, int increment) {
    sqStack.elem = (ElemType *) malloc(size * sizeof(ElemType));

    if (sqStack.elem == NULL) { return OVERFLOW; }

    sqStack.top = 0;
    sqStack.size = size;
    sqStack.increment = increment;
    return OK;
}

Status Push_Sq(SqStack sqStack, ElemType elemType) {
    ElemType *newBase;
    if (sqStack.top >= sqStack.size) {
        newBase = (ElemType *) realloc(sqStack.elem, (sqStack.size + sqStack.increment) * sizeof(ElemType));

        if (NULL == newBase) { return OVERFLOW; }

        sqStack.elem = newBase;
        sqStack.size += sqStack.increment;
    }
    sqStack.elem[sqStack.top++] = elemType;
    return OK;
}
