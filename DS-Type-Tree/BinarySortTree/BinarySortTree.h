//
// Created by P7XXTM1-G on 2021/12/4.
//

#ifndef HELLO_C_BINARYSORTTREE_H
#define HELLO_C_BINARYSORTTREE_H

#include <stdio.h>
#include <stdlib.h>

#include "Status/Status.h"
#include "RecordList/RecordList.h"

typedef struct BinarySearchTreeNode {
    RecordElemType data;
    struct BinarySortTreeNode *leftChild, *rightChild;
} BinarySortTreeNode, *BinarySortTree;

Status InitBinarySearchTree(BinarySortTree *root);

Status DestroyBinarySearchTree(BinarySortTree *root);

BinarySortTree SearchBST(BinarySortTree root, KeyType value);

BinarySortTree SearchBST_I(BinarySortTree root, KeyType value);

Status InsertBST(BinarySortTree *root, RecordElemType value);

Status DeleteBST(BinarySortTree *root, KeyType value);

#endif //HELLO_C_BINARYSORTTREE_H
