//
// Created by P7XXTM1-G on 2021/12/2.
//

#include "SequenceSearch.h"

// 顺序查找 时间复杂度：O(n)
// 无序表的顺序查找
int SeqSearch(RecordList list, KeyType value) {
    int i;

    // 空一个位置设置岗哨，存取待查找的值
    list.base[0].value = value;

    // 从表尾向前查找
    for (i = list.size - 1; value != list.base[i].value; --i);

    // 成功则返回元素下标，失败返回0
    return i;
}

// 有序表的顺序查找
int sortBySequential(RecordList list, KeyType value) {
    int i;

    // 空一个位置设置岗哨，存取待查找的值
    list.base[0].value = value;

    // 从表尾向前查找
    for (i = list.size - 1; value < list.base[i].value; --i);

    // 返回元素位置
    if (value == list.base[i].value) {
        return i;
    }

    // 失败返回0
    return 0;
}