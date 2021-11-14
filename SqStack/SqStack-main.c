//
// Created by P7XXTM1-G on 2021/11/13.
//

#include <stdio.h>
#include "SqStack.h"

#define Default_Size 10

void printElem(ElemType elem) {
    printf("\"%d\" ", elem);
}

int main() {
    printf("---SqStack\n");
    SqStack sqStack;
    ElemType elem;

    printf("---初始化\n");
    {
        InitStack_Sq(&sqStack, Default_Size, Default_Size * 2);
    }

    printf("---判空\n");
    {
        StackEmpty_Sq(sqStack) ? printf("Empty!\n") : printf("Pass!\n");
    }

    printf("---进栈---\n");
    {
        for (int i = 0; i < Default_Size; ++i) {
            Push_Sq(&sqStack, 2 * i);
            printf("\"%d\" 进栈\n", 2 * i);
        }
    }

    printf("---出栈\n");
    {
        Pop_Sq(&sqStack, &elem);
        printf("%d\n", elem);
    }

    printf("---取栈顶\n");
    {
        GetTop_Sq(sqStack, &elem);
        printf("%d", elem);
    }

    return 0;
}