//
// Created by P7XXTM1-G on 2021/12/4.
//

#include "BinarySortTree.h"

// 二叉查找树 / 二叉排序树
// 查找性能：
// 最好情况：二叉查找树树高最小，时间复杂度为：O(logn)
// 最坏情况：二叉查找树为单支树，此时将退化为顺序查找，时间复杂度为：O(n)

// 递归查找
BinarySortTree SearchBST(BinarySortTree root, KeyType value) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data.value == value) {
        return root;
    }

    // 根值大于查找值
    // 往左子树进行递归查找
    if (root->data.value > value) {
        return SearchBST(root->leftChild, value);
    }

    // 往右子树进行递归查找
    return SearchBST(root->rightChild, value);
}

// 非递归查找
BinarySortTree SearchBST_I(BinarySortTree root, KeyType value) {
    while (root != NULL) {
        if (root->data.value == value) {
            return root;
        } else if (root->data.value > value) {
            root = root->leftChild;
        } else {
            root = root->rightChild;
        }
    }

    return NULL;
}

// 递归插入
Status InsertBST(BinarySortTree *root, RecordElemType value) {
    // 若二叉查找树是空树，则创建新插入结点并作为根结点
    if (root == NULL) {
        BinarySortTreeNode *newTreeRoot;

        newTreeRoot = (BinarySortTreeNode *) malloc(sizeof(BinarySortTreeNode));

        if (newTreeRoot == NULL) {
            return OVERFLOW;
        }

        newTreeRoot->data = value;
        newTreeRoot->leftChild = NULL;
        newTreeRoot->rightChild = NULL;

        // 赋值新根结点
        root = &newTreeRoot;

        return TRUE;
    }

    // 若插入结点的值小于根结点值，在左子树递归插入
    if (value.value < (*root)->data.value) {
        return InsertBST(&(*root)->leftChild, value);
    }

    // 若插入结点的值小于根结点值，在右子树递归插入
    if (value.value > (*root)->data.value) {
        return InsertBST(&(*root)->rightChild, value);
    }

    // 结点已存在不插入
    // 等效于：value.value == (*root)->data.value;
    return FALSE;
}

// 删除结点
// 将待删结点的前驱结点作为新父节点（若在根部删除，则为根节点）
// 将指针指向待删结点的直接前驱或直接后继（此处为指向前驱）
void DeleteNode(BinarySortTree *p) {
    // 删除二叉查找树中的 p结点，引用形参p 的实参是 要删除的p结点的双亲指向其的指针域
    BinarySortTreeNode *q, *s;

    // 令 q 指向 要删除的p结点
    q = *p;

    if ((*p)->rightChild == NULL) {
        // 被删的p结点的右子树为空
        // 置p结点的左子树 为 p结点的双亲结点的相应子树
        p = &(*p)->leftChild;
        free(q);

    } else if ((*p)->leftChild == NULL) {
        // 被删的p结点的左子树为空
        // 置p结点的右子树 为 p结点的双亲结点的相应子树
        p = &(*p)->rightChild;
        free(q);

    } else {
        // 左右子树均不为空
        // s指向p结点的左孩子
        s = (*p)->leftChild;

        while (s->rightChild != NULL) {
            // 向右走到尽头，令s指向被删结点的直接前驱
            q = s;
            s = s->rightChild;
        }

        // 将直接前驱s结点的值 赋予 被删结点
        (*p)->data = s->data;

        // s结点是被删结点的左孩子
        if (q == *p) {
            // 删除s结点 只需将其左子树置为q结点的左子树
            q->leftChild = s->leftChild;

        } else {
            // 删除s结点 只需将其左子树置为q结点的右子树
            q->rightChild = s->leftChild;
        }

        free(s);
    }
}

// 递归删除
Status DeleteBST(BinarySortTree *root, KeyType value) {
    // 不存在 值为value 的结点
    if (root == NULL) {
        return FALSE;
    }

    // 找到 值为value 的结点
    if ((*root)->data.value == value) {
        // 删除 值为value 的结点
        DeleteNode(root);
        return TRUE;

    } else if ((*root)->data.value > value) {
        // 对左子树递归并返回结果
        return DeleteBST(&(*root)->leftChild, value);
    }

    // 对右子树递归并返回结果
    return DeleteBST(&(*root)->rightChild, value);
}

// [2019.829] 算法填空题2
// 判断二叉查找树是否为二叉平衡树
Status isAVL(BinarySortTree tree, int *high) {
    int h1, h2;

    // 结点
    if (tree == NULL) {
        *high = 0;
        return TRUE;
    }

    // 单枝树
    if (!tree->leftChild && !tree->rightChild) {
        *high = 1;
        return FALSE;
    }

    // 统计左右子树平衡因子
    if (!isAVL((BinarySortTree) tree->leftChild, &h1) || !isAVL((BinarySortTree) tree->rightChild, &h2)) {
        return FALSE;
    }

    // 计算两分枝树平衡因子
    *high = (h1 > h2 ? h1 : h2) + 1;

    // 平衡二叉树的平衡因子只可能为 -1，0，1
    // 此处对平衡因子进行取绝对值处理，若绝对值小于2，则为平衡二叉树
    if (abs(h2 - h2) < 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}