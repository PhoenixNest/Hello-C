//
// Created by P7XXTM1-G on 2021/11/22.
//

#include "GeneralizedList.h"

// 广义表

// 求广义表深度
// 如：
//├── DS-Search
//│         └── BinarySearch
//├── DS-Sort
//│         ├── Type-Exchange
//│         ├── Type-Insert
//│         ├── Type-Merge
//│         ├── Type-Radix
//│         └── Type-Select
//├── DS-Type-Array
//│         └── GeneralizedList
//|
// 可表示为：A[1,5,1]
//├─────── A[DS-Search[1],DS-Sort[5],DS-Type-Array[1]]

int GListDepth(GList gList) {
    int h1, h2;
    // 递归边界条件
    // 空表
    if (gList == NULL) {
        return 1;
    }
    // 原子表（不可分）
    if (gList->tag == ATOM) {
        return 0;
    }

    // 表头深度 +1
    h1 = GListDepth(gList->un.pointer.headPointer) + 1;

    // 表尾深度与原表相同
    h2 = GListDepth(gList->un.pointer.tailPointer);

    return h1 >= h2 ? h1 : h2;
}

// 广义表表尾追加
Status Append(GList *gList, GLNode *glNode) {
    GLNode *pp;
    GList tail;

    tail = (GList) malloc(sizeof(GLNode));

    if (tail == NULL) {
        return OVERFLOW;
    }

    tail->tag = LIST;
    tail->un.pointer.headPointer = glNode;
    tail->un.pointer.tailPointer = NULL;

    if (gList == NULL) {
        gList = &tail;
    } else {
        for (pp = (GLNode *) gList; pp->un.pointer.tailPointer != NULL; pp = pp->un.pointer.tailPointer);

        // 定位至最后一个结点
        pp->un.pointer.tailPointer = tail;
    }


    return OK;
}