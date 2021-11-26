//
// Created by P7XXTM1-G on 2021/11/22.
//

#ifndef HELLO_C_BINARYLINKEDTREE_H
#define HELLO_C_BINARYLINKEDTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"
#include "../../DS-Type-Link/LinkStack/LinkStack.h"
#include "../../DS-Type-Link/LinkQueue/LinkQueue.h"

typedef char TreeElemType;

typedef struct BinaryLinkedTreeNode {
    TreeElemType data;
    struct BinaryLinkedTreeNode *leftChild, *rightChild;
} BinaryLinkedTreeNode, *BinaryLinkedTree;

void InitBinaryLinkedTree(BinaryLinkedTree *root);

BinaryLinkedTree MakeBinaryTree(TreeElemType rootData, BinaryLinkedTree leftTree, BinaryLinkedTree rightTree);

BinaryLinkedTree CreateBinaryLinkedTree(char *defBT, int *i);

void DestroyBinaryLinkedTree(BinaryLinkedTree *root);

Status BinaryLinkedTreeEmpty(BinaryLinkedTree root);

Status BreakBinaryLinkedTree(BinaryLinkedTree *root, BinaryLinkedTree *lTree, BinaryLinkedTree *rTree);

int BinaryLinkedTreeDepth(BinaryLinkedTree root);

void CountLeaf(BinaryLinkedTree root, int *count);

Status ReplaceLeft(BinaryLinkedTree *root, BinaryLinkedTree *leftTree);

Status ReplaceRight(BinaryLinkedTree *root, BinaryLinkedTree *rightTree);

Status CutLeft(BinaryLinkedTree *root);

Status CutRight(BinaryLinkedTree *root);

Status PreOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

Status InOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

Status PostOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

void PreOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

void InOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

void PostOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

void InOrderTraverse_I(BinaryLinkedTree root, Status(*visit)(TreeElemType elem));

#endif //HELLO_C_BINARYLINKEDTREE_H
