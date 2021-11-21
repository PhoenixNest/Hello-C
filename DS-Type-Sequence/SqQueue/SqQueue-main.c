//
// Created by P7XXTM1-G on 2021/11/14.
//

#include <stdio.h>
#include "SqQueue.h"

#define Default_Size 5

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main() {
    SqQueue sqQueue;
    ElemType elem;

    printf("---初始化\n");
    {
        InitQueue_Sq(&sqQueue, Default_Size);
    }

    printf("---入队\n");
    {
        for (int i = 1; i <= Default_Size; ++i) {
            EnQueue_Sq(&sqQueue, 3 * i);
            printf("\"%d\" 入队\n", 3 * i);
        }
    }

    printf("---判空\n");
    {
        QueueEmpty_Sq(sqQueue) ? printf("空队，请先将元素入队！\n") : printf("非空！\n");
    }

    printf("---出队\n");
    {
        DeQueue_Sq(&sqQueue, &elem);
        printf("%d\n", elem);
    }

    printf("---取队头\n");
    {
        GetHead_Sq(sqQueue, &elem);
        printf("%d", elem);
    }

    return 0;
}