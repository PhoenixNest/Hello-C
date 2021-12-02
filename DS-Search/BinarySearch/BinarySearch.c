//
// Created by P7XXTM1-G on 2021/11/19.
//

#include "BinarySearch.h"

// 折半查找 / 二分查找
// 时间复杂度：O(logn)
// 比较次数少，查找速度快，平均性能好，但要求待查找表必须顺序存储且有序，适合不经常变动而查找频繁的有序表
int BinarySearch(RecordElemType array[], KeyType value, int low, int high) {
    int mid = (low + high) / 2;

    if (low > high) {
        // 当低区指针与高区指针发生错位，则表示序列中无待查找值，查找失败
        return -1;
    }

    if (array[mid].value == value) {
        // 在 中间位置 就查找成功
        return mid;
    } else if (array[mid].value > value) {
        // 若待查找值 小于 中间值，则继续在给定序列 上半区 进行递归查找
        return BinarySearch(array, value, low, mid - 1);
    } else {
        // 若待查找值 大于 中间值，则继续在给定序列 下半区 进行递归查找
        return BinarySearch(array, value, mid + 1, high);
    }
}

// 迭代实现
// 折半查找 / 二分查找
int BinarySearch_iteration(RecordElemType array[], KeyType value, int low, int high) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid].value == value) {
            return mid;
        } else if (array[mid].value > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}