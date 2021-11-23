//
// Created by P7XXTM1-G on 2021/11/22.
//

#ifndef HELLO_C_BINARYLINKEDTREE_H
#define HELLO_C_BINARYLINKEDTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"
#include "../../DS-Type-Link/LinkStack/LinkStack.h"

typedef char TreeElemType;

typedef struct BinaryLinkedTreeNode {
    TreeElemType data;
    struct BinaryLinkedTreeNode *leftChild, *rightChild;
} BinaryLinkedTreeNode, *BinaryLinkedTree;

void InitBinaryLinkedTree(BinaryLinkedTree *binaryLinkedTree);

BinaryLinkedTree MakeBinaryTree(TreeElemType rootData, BinaryLinkedTree leftTree, BinaryLinkedTree rightTree);

void DestroyBinaryLinkedTree(BinaryLinkedTree *binaryLinkedTree);

Status BinaryLinkedTreeEmpty(BinaryLinkedTree binaryLinkedTree);

Status BreakBinaryLinkedTree(BinaryLinkedTree *root, BinaryLinkedTree *lTree, BinaryLinkedTree *rTree);

Status ReplaceLeft(BinaryLinkedTree *binaryLinkedTree, BinaryLinkedTree *leftTree);

Status ReplaceRight(BinaryLinkedTree *binaryLinkedTree, BinaryLinkedTree *rightTree);

Status CutLeft(BinaryLinkedTree *binaryLinkedTree);

Status CutRight(BinaryLinkedTree *binaryLinkedTree);

Status PreOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

Status InOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

Status PostOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

void PreOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

void InOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

void PostOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

void InOrderTraverse_I(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

#endif //HELLO_C_BINARYLINKEDTREE_H
