//
// Created by P7XXTM1-G on 2021/11/23.
//

#include "TernaryLinkedTree.h"

// 非递归遍历
// 不使用栈的先序非递归遍历
Status PreOrderTraverse(TriLinkedTree root, Status(*visit)(TreeElemType elem)) {
    TriLinkedTree p, pr;

    if (root != NULL) {
        p = root;

        while (p != NULL) {
            // 输出当前结点
            visit(p->data);

            // 若有左孩子，继续访问
            if (p->leftChild != NULL) {
                p = p->leftChild;
            }// 若有右孩子，继续访问
            else if (p->rightChild != NULL) {
                p = p->rightChild;
            }// 沿双亲指针链查找，找到 第一个有右孩子的p结点，找不到则结束
            else {
                do {
                    pr = p;
                    p = p->parent;
                } while (p != NULL && (p->rightChild == pr || p->rightChild == NULL));

                // 找到 右孩子的p结点 后，p指向右孩子结点
                if (p != NULL) {
                    p = p->rightChild;
                }
            }
        }
    }

    return OK;
}