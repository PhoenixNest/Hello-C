//
// Created by P7XXTM1-G on 2021/11/20.
//

#include "QuickSort.h"

// 一趟快速排序
// 参数列表：待排序序列，排序区间的下界，排序区间的上界
int Partition(RecordElemType array[], int low, int high) {
    // 暂存枢轴
    array[0] = array[low];

    // 开始进行分割
    while (low < high) {
        // 大下标端找小于枢轴的记录
        while (low < high && array[high].key >= array[0].key) {
            --high;
        }

        // 该记录移动到小下标端
        array[low] = array[high];

        // 小下标端找大于枢轴的记录
        while (low < high && array[low].key <= array[0].key) {
            ++low;
        }

        // 该记录移动到大下标端
        array[high] = array[low];
    }

    // 把枢轴回填到分解位置上
    array[low] = array[0];

    // 返回枢轴位置
    return low;
}

// 递归快速排序
void QSort(RecordElemType array[], int low, int high) {
    int pivot;
    if (low < high) {
        pivot = Partition(array, low, high);
        QSort(array, low, pivot - 1);
        QSort(array, pivot + 1, high);
    }
}

// 快速排序
// 目前最快的内部排序算法，适用于记录较多且基本无序的序列
// 时间复杂度：O(nlogn)
// 快速排序接口函数
// 参数列表：待排序序列
void QuickSort(RecordList *list) {
    QSort(list->base, 1, list->length);
}
