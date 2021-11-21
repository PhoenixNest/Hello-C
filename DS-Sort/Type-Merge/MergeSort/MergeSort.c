//
// Created by P7XXTM1-G on 2021/11/20.
//

#include "math.h"
#include "MergeSort.h"

// 2-路归并
// 归并相邻的两个有序子序列
// 将有序序列 array[low..mid-1] 和 array[mid..high] 归并为有序序列 array[low..high]
void Merge(RecordElemType array[], RecordElemType temp[], int low, int mid, int high) {
    // 将相邻的有序区间 array[low..mid] 和 array[mid+1..high] 归并有序的 temp[low..high]
    int k, j;
    for (j = mid + 1, k = low; low <= mid && j < high; ++k) {
        if (array[low].value <= array[j].value) {
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

// 2-路归并排序
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

// 2-路归并排序 接口函数
void MergeSort(RecordList *recordList) {
    RecordElemType *R;
    R = (RecordElemType *) malloc((recordList->length + 1) * sizeof(RecordElemType));

    MSort(recordList->base, R, 0, 1, recordList->length);

    free(R);
};

// 迭代实现
// 2-路归并排序
void MSort_iteration(RecordElemType array[], RecordElemType temp[], int size) {
    int deepLevel;
    int currentLength;
    int low, high, mid;

    deepLevel = ceil(log(size) / log(2));

    if (deepLevel % 2 == 1) {
        for (int i = 1; i <= size; i++) {
            temp[i] = array[i];
        }
    }

    for (currentLength = 2; deepLevel > 0; currentLength *= 2, deepLevel--) {
        for (low = 1; low <= size; low += currentLength) {
            if ((mid = low + (currentLength - 1) / 2) > size) {
                mid = size;
            }

            if ((high = low + high - 1) > size) {
                high = size;
            }

            if (deepLevel % 2 == 1) {
                Merge(temp, array, low, mid, high);
            } else {
                Merge(array, temp, low, mid, high);
            }
        }
    }
}

// 2-路归并排序 迭代接口函数
void MergeSort_iteration(RecordList *recordList) {
    RecordElemType *value;
    value = (RecordElemType *) malloc((recordList->length + 1) * sizeof(RecordElemType));

    MSort_iteration(recordList->base, value, recordList->length);

    free(value);
}