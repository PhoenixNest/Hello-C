//
// Created by P7XXTM1-G on 2021/11/22.
//

#ifndef HELLO_C_BINARYSQEUENCETREE_H
#define HELLO_C_BINARYSQEUENCETREE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"

typedef char TreeElemType;

typedef struct {
    TreeElemType *elem;
    int lastIndex;
} BinarySequenceTree;

Status is_Descendant(BinarySequenceTree tree, int u, int v);

#endif //HELLO_C_BINARYSQEUENCETREE_H
