//
// Created by P7XXTM1-G on 2021/11/18.
//

#include "ShellSort.h"

void PrintElem(RecordElemType e) {
    printf("%d ", e.key);
}

int main() {
    RecordList recordList;

    printf("---初始化\n");
    {
        InitList_Rec(&recordList, listSize);
    }

    printf("---插入元素\n");
    {
        RecordElemType array[] = {85, 56, 23, 98, 54, 74, 12, 4, 8, 31};
        for (int i = 0; i < recordList.size; i++) {
            Insert_Rec(&recordList, i, array[i]);
            printf("在第 %d 个位置插入 \"%d\"\n", i, array[i].key);
        }
    }

    printf("---当前表内元素\n");
    {
        printf("当前表中元素：List = ");
        ListTraverse_Rec(recordList, PrintElem);
    }


    printf("---对该表进行希尔排序\n");
    {
        int gap = 3;
        int gapArray[] = {5, 3, 1};
        ShellSort(&recordList, gapArray, gap);
    }

    printf("---排序后表内元素\n");
    {
        printf("当前表中元素：List = ");
        ListTraverse_Rec(recordList, PrintElem);
    }

    return 0;
}