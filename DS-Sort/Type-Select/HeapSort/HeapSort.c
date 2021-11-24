//
// Created by P7XXTM1-G on 2021/11/20.
//

#include "HeapSort.h"

void HeapSort(RecordList *list) {
    Heap heap;
    RecordElemType elem;

    MakeHeap(&heap, list->base, list->length, list->size, 1, greatPrior);

    for (int i = heap.heapLength; i > 0; i--) {
        RemoveFirstHeap(&heap, &elem);
    }
}