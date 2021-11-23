//
// Created by P7XXTM1-G on 2021/11/23.
//

#ifndef HELLO_C_TERNARYLINKEDTREE_H
#define HELLO_C_TERNARYLINKEDTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"

typedef char TreeElemType;

typedef struct TriLinkedTreeNode {
    TreeElemType data;
    struct TriLinkedTreeNode *parent, *leftChild, *rightChild;
} TriLinkedTreeNode, *TriLinkedTree;

Status PreOrderTraverse(TriLinkedTree root, Status(*visit)(TreeElemType elem));

#endif //HELLO_C_TERNARYLINKEDTREE_H
