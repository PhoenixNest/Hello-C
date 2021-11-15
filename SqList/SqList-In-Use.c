//
// Created by P7XXTM1-G on 2021/11/15.
//

#include "SqList-In-Use.h"

// 有序顺序表合并
void MergeList(SqList sqListA, SqList sqListB, SqList *sqListC) {
    int i = 0, j = 0;
    ElemType ai, bj;

    int size = sqListA.length + sqListB.length;
    int increment = 10;

    InitList_Sq(sqListC, size, increment);

    // 已知有序顺序表 A 与 B 中的元素按值非递减排列
    // A，B 不为空
    // 归并 A，B 得到新表 C
    while (i < sqListA.length && j < sqListB.length) {
        GetElem_Sq(sqListA, i, &ai); // 取表 A 的第 i 个元素到 ai
        GetElem_Sq(sqListB, j, &bj); // 取表 B 的第 j 个元素到 bj
        if (ai < bj) {
            // ai 较小或相等时，取 ai，并将其加入新表 C
            Append_Sq(sqListC, ai);

            // 指针移向 A 表下一个元素
            ++i;
        } else {
            // bj较小或相等时，取 bj，并将其加入新表 C
            Append_Sq(sqListC, bj);

            // 指针移向 B 表下一个元素
            ++j;
        }
    }

    // 表 A 非空且表 B 已空
    while (i < sqListA.length) {
        GetElem_Sq(sqListA, i++, &ai);
    }

    // 表 B 非空且表 A 已空
    while (i < sqListB.length) {
        GetElem_Sq(sqListB, j++, &bj);
    }
}