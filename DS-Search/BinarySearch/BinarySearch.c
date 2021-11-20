//
// Created by P7XXTM1-G on 2021/11/19.
//

#include "BinarySearch.h"

// 折半查找 / 二分查找
int BinarySearch(RecordElemType elem[], KeyType value, int low, int high) {
    int mid = (low + high) / 2;
    if (low > high) {
        // 当低区指针与高区指针发生错位，则表示序列中无待查找值，查找失败
        return -1;
    }

    if (elem[mid].key == value) {
        // 在 中间位置 就查找成功
        return mid;
    } else if (elem[mid].key > value) {
        // 若待查找值 小于 中间值，则继续在给定序列 上半区 进行递归查找
        return BinarySearch(elem, value, low, mid - 1);
    } else {
        // 若待查找值 大于 中间值，则继续在给定序列 下半区 进行递归查找
        return BinarySearch(elem, value, mid + 1, high);
    }
}