//
// Created by P7XXTM1-G on 2021/11/24.
//

#ifndef HELLO_C_HEAP_H
#define HELLO_C_HEAP_H

#include <stdio.h>
#include <stdlib.h>

#include "Status/Status.h"
#include "RecordList/RecordList.h"

typedef struct {
    // 堆基址，0号单元闲置
    RecordElemType *base;

    // 堆长度
    int heapLength;

    // 堆容量
    int heapSize;

    // 小顶堆与大顶堆的标志
    // tag = 0 为小顶堆
    // tag = 1 为大顶堆
    int tag;

    // 函数变量，用于关键字优先级比较
    int (*prior)(KeyType, KeyType);
} Heap;

int greatPrior(int x, int y);

int lessPrior(int x, int y);

Status InitHeap(Heap *heap, int size, int tag, int (*prior)(KeyType, KeyType));

void MakeHeap(Heap *heap, RecordElemType *elem, int heapLength, int heapSize, int tag, int (*prior)(KeyType, KeyType));

Status DestroyHeap(Heap *heap);

void ShiftDown(Heap *heap, int position);

Status InsertHeap(Heap *heap, RecordElemType elem);

Status RemoveFirstHeap(Heap *heap, RecordElemType *elem);

Status RemoveHeap(Heap *heap, int position, RecordElemType elemType);

#endif //HELLO_C_HEAP_H
