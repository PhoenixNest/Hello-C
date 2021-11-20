//
// Created by P7XXTM1-G on 2021/11/20.
//

#include "MergeSort.h"

// 2-路归并，归并相邻的两个有序子序列
// 将有序序列 array[low..mid-1] 和 array[mid..high] 归并为有序序列 array[low..high]
void Merge(RecordElemType array[], RecordElemType temp[], int low, int mid, int high) {
    // 将相邻的有序区间 array[low..mid] 和 array[mid+1..high] 归并有序的 temp[low..high]
    int k, j;
    for (j = mid + 1, k = low; low <= mid && j < high; ++k) {
        if (array[low].key <= array[j].key) {
            // 若将条件中的 "<=" 改成 "<"，则归并排序不稳定
            temp[k] = array[low++];
        } else {
            temp[k] = array[j++];
        }
    }
    // 将剩余的 array[low..mid] 复制到 temp
    while (low <= mid) {
        temp[k++] = array[low++];
    }

    // 将剩余的 array[j..mid] 复制到 temp
    while (j <= high) {
        temp[k++] = array[j++];
    }
}

// 递归2-路归并排序
void MSort(RecordElemType array[], RecordElemType temp[], int i, int low, int high) {
    int mid;
    if (low == high) {
        if (i % 2 == 1) {
            temp[low] = array[low];
        }
    } else {
        // 从中间划分为两个子序列
        mid = (low + high) / 2;

        // 递归对子序列 array[low..mid]进行归并排序
        MSort(array, temp, i + 1, low, mid);

        // 递归对子序列 array[mid+1..high]进行归并排序
        MSort(array, temp, i + 1, mid + 1, high);

        // 归并两个子序列
        if (i % 2 == 1) {
            Merge(array, temp, low, mid, high);
        } else {
            Merge(temp, array, low, mid, high);
        }
    }
}

// 2-路归并接口函数
void MergeSort(RecordList *recordList) {
    RecordElemType *R;
    R = (RecordElemType *) malloc((recordList->length + 1) * sizeof(RecordElemType));

    MSort(recordList->base, R, 0, 1, recordList->length);

    free(R);
};