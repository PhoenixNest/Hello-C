//
// Created by P7XXTM1-G on 2021/12/6.
//

#ifndef HELLO_C_CHILDSIBLINGFOREST_H
#define HELLO_C_CHILDSIBLINGFOREST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "Status/Status.h"

typedef int TreeElemType;

// 孩子兄弟链表
typedef struct {
    // 数据域
    TreeElemType data;

    // 最左孩子指针、右兄弟指针
    struct ChildSiblingTreeNode *firstChild, *nextSibling;
} ChildSiblingTreeNode, *ChildSiblingTree, *ChildSiblingForest;

Status InitTree(ChildSiblingTree *tree);

ChildSiblingTree MakeTree(TreeElemType elem, int childTreeNum, ...);

Status DestroyTree(ChildSiblingTree *tree);

int TreeDepth(ChildSiblingTree tree);

ChildSiblingTreeNode *Search(ChildSiblingTree tree, TreeElemType elem);

Status InsertChild(ChildSiblingTree *tree, int i, ChildSiblingTree insertTree);

Status DeleteChild(ChildSiblingTree *tree, int position);

Status PreOrderTraverForest(ChildSiblingForest forest, Status(*visit)(TreeElemType));

int ForestDepth(ChildSiblingForest forest);

ChildSiblingTreeNode *Search(ChildSiblingForest forest, TreeElemType elem);

#endif //HELLO_C_CHILDSIBLINGFOREST_H
