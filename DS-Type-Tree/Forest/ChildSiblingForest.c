//
// Created by P7XXTM1-G on 2021/12/6.
//

#include "ChildSiblingForest.h"

// 插入树insertTree 作为 tree的第i棵子树
Status InsertChild(ChildSiblingTree *tree, int i, ChildSiblingTree insertTree) {
    int j;
    ChildSiblingTree p;

    // 森林为空 或 插入位置非法
    if (tree == NULL || i < 1) {
        return ERROR;
    }

    // insertTree 为 tree 的第一棵子树
    if (i == 1) {
        insertTree->nextSibling = (*tree)->firstChild;

        // insertTree 成为 tree的第一棵子树
        (*tree)->firstChild = (struct ChildSiblingTreeNode *) insertTree;
    } else {
        // p 指向 tree的第一棵子树
        p = (ChildSiblingTree) (*tree)->firstChild;

        // 寻找插入位置
        for (j = 2; p != NULL && j < i; j++) {
            // 找到插入位置
            if (j == i) {
                insertTree->nextSibling = p->nextSibling;
                p->nextSibling = (struct ChildSiblingTreeNode *) insertTree;
            } else {
                // 插入位置i 过大
                return ERROR;
            }
        }
    }

    return OK;
}

// 递归遍历
// 森林的先序遍历（与二叉树的先序遍历相同）
// 遍历过程：
// 1.先访问第一棵树的根结点
// 2.先序遍历第一棵树的子树森林
// 3.先序遍历剩余森林
Status PreOrderTraverForest(ChildSiblingForest forest, Status(*visit)(TreeElemType)) {
    // 森林为空，遍历结束
    if (forest == NULL) {
        return OK;
    }

    // 访问第一棵树的根结点
    if (visit(forest->data) == ERROR) {
        return ERROR;
    }

    // 递归遍历第一棵子树的子树森林
    if (PreOrderTraverForest((ChildSiblingForest) forest->firstChild, visit) == ERROR) {
        return ERROR;
    }

    // 递归先序遍历剩余森林
    return PreOrderTraverForest((ChildSiblingForest) forest->nextSibling, visit);
}

// 求森林深度
// 第一棵子树森林的深度 + 1 + max{剩余森林的深度}
int ForestDepth(ChildSiblingForest forest) {
    int dep1, dep2, dep;

    if (forest == NULL) {
        // 森林为空，深度则为0
        dep = 0;
    } else {
        // 求第一棵子树森林的深度
        dep1 = ForestDepth((ChildSiblingForest) forest->firstChild);

        // 求剩余森林的深度
        dep2 = ForestDepth((ChildSiblingForest) forest->nextSibling);

        // 森林的深度
        dep = dep1 + 1 > dep2 ? dep1 + 1 : dep2;
    }

    return dep;

}

// 森林的查找
// 在森林forest中查找结点e，可采用森林的先序遍历来实现。
// -------------------------------------------
// 查找成功：返回结点指针
// 查找失败：返回NULL
ChildSiblingTreeNode *Search(ChildSiblingForest forest, TreeElemType elem) {
    ChildSiblingTreeNode *result = NULL;

    // 查找森林为空
    if (forest == NULL) {
        return NULL;
    }

    // 找到结点，返回其指针
    if (forest->data == elem) {
        return forest;
    }

    // 在第一棵树的子树森林查找
    if ((result = Search((ChildSiblingTree) forest->nextSibling, elem)) != NULL) {
        return result;
    }

    // 在其余森林中查找
    return Search((ChildSiblingTree) forest->nextSibling, elem);
}