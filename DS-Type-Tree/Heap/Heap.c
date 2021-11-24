//
// Created by P7XXTM1-G on 2021/11/24.
//

#include "Heap.h"

// 大顶堆优先函数
int greatPrior(int x, int y) {
    return x >= y;
}

// 小顶堆优先函数
int lessPrior(int x, int y) {
    return x <= y;
}

// 建堆
void MakeHeap(Heap *heap, RecordElemType *elem, int heapLength, int heapSize, int tag, int (*prior)(KeyType, KeyType)) {
    heap->base = elem;
    heap->heapLength = heapLength;
    heap->heapSize = heapSize;
    heap->tag = tag;
    heap->prior = prior;

    for (int i = heapLength / 2; i > 0; i--) {
        ShiftDown(heap, i);
    }
}

// 交换堆中的 第i结点 和 第j结点
Status swapHeapElem(Heap *heap, int i, int j) {
    RecordElemType elemType;

    if (i <= 0 || i > heap->heapLength || j <= 0 || j > heap->heapLength) {
        return ERROR;
    }

    elemType = heap->base[i];
    heap->base[i] = heap->base[j];
    heap->base[j] = elemType;

    return OK;
}

// 向下调堆
// 对堆中位置为position的结点做筛选，将以position为根的子树调整为子堆
void ShiftDown(Heap *heap, int position) {
    int leftChild, rightChild;

    // 当 调整位置position 为 叶子结点 时停止调整
    while (position <= heap->heapLength / 2) {
        // leftChild 为 调整位置position 的左孩子位置
        leftChild = position * 2;

        // rightChild 为 调整位置position 的右孩子位置
        rightChild = position * 2 + 1;

        if (rightChild <= heap->heapLength &&
            heap->prior(heap->base[rightChild].value, heap->base[leftChild].value)) {

            // leftChild 为 position结点的左、右孩子中较优先者的位置
            leftChild = rightChild;
        }

        if (heap->prior(heap->base[position].value, heap->base[leftChild].value)) {
            // position优先级较高，筛选结束
            return;
        }

        // 将 position 和 较优先者leftChild 交换位置
        swapHeapElem(heap, position, leftChild);

        // 继续向下调堆
        position = leftChild;
    }
}

// 堆插入
// 算法思想：
// 1.插入元素首先插入堆尾
// 2.将插入元素与当前根结点进行对比，向上调堆
// 3.将堆进一步调整为大根堆（小根堆）
Status InsertHeap(Heap *heap, RecordElemType elem) {
    int current;

    if (heap->heapLength >= heap->heapSize - 1) {
        // 堆满，插入失败
        return ERROR;
    }

    // 插入元素至堆尾
    current = ++heap->heapLength;
    heap->base[current] = elem;

    while (current != 1 &&
           heap->prior(heap->base[current].value, heap->base[current / 2].value)) {
        // 向上调堆
        swapHeapElem(heap, current, current / 2);
        current /= 2;
    }

    return OK;
}

// 删除堆顶结点
// 算法思想：
// 1.将堆顶结点删除
// 2.将堆尾结点调整至堆顶
// 3.对新堆顶结点进行调整，进一步调整为大根堆（小根堆）
Status RemoveFirstHeap(Heap *heap, RecordElemType *elem) {
    // elem将返回堆顶结点
    if (heap->heapLength <= 0) {
        return ERROR;
    }

    elem = &heap->base[1];

    // 堆最右下角元素上移成为堆顶元素
    swapHeapElem(heap, 1, heap->heapLength);

    heap->heapLength--;

    if (heap->heapLength > 1) {
        ShiftDown(heap, 1);
    }

    return OK;
}