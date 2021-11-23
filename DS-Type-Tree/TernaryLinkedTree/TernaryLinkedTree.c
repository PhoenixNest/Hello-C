//
// Created by P7XXTM1-G on 2021/11/23.
//

#include "TernaryLinkedTree.h"

Status PreOrderTraverse(TriLinkedTree root, Status(*visit)(TreeElemType elem)) {
    TriLinkedTree p, pr;

    if (root != NULL) {
        p = root;

        while (p != NULL) {
            visit(p->data);
            if (p->leftChild != NULL) {
                p = p->leftChild;
            } else if (p->rightChild != NULL) {
                p = p->rightChild;
            } else {
                do {
                    pr = p;
                    p = p->parent;
                } while (p != NULL && (p->rightChild == pr || p->rightChild == NULL));
            }
        }
    }

    return OK;
}