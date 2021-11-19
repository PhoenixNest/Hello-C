//
// Created by P7XXTM1-G on 2021/11/15.
//

#include "SqList.h"

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main() {
    printf("SqList\n");

    SqList sqList;

    printf("---初始化\n");
    {
        InitList_Sq(&sqList, 10, 10);
    }

    printf("---插入元素\n");
    {
        ElemType array[10] = {85, 56, 23, 98, 54, 74, 1, 4, 8, 31};
        for (int i = 0; i < sqList.size; i++) {
            Insert_Sq(&sqList, i + 1, array[i]);
            printf("在第 %d 个位置插入 \"%d\"\n", i, array[i]);
        }
    }

    printf("---非空判断\n");
    {
        printf(ListEmpty_Sq(sqList) ? "空\n" : "非空\n");
    }

    printf("---当前表长\n");
    {
        printf("%d\n", ListLength(sqList));
    }

    printf("---当前表内元素\n");
    {
        printf("当前表中元素：sqList = ");
        ListTraverse_Sq(sqList, PrintElem);
    }

    return 0;
}

