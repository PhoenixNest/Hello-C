//
// Created by P7XXTM1-G on 2021/11/22.
//

#include "BinarySequenceTree.h"

// 二叉顺序树

// 判断 v结点 是否 u结点 的子孙
Status is_Descendant(BinarySequenceTree tree, int u, int v) {
    if (u < 1 || u > tree.lastIndex || v < 1 || v > tree.lastIndex || v <= u) {
        return FALSE;
    }

    while (v > u) {
        v = v / 2;
        if (v == u) {
            return TRUE;
        }
    }

    return FALSE;
}