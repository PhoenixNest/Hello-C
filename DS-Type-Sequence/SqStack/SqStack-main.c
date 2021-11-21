//
// Created by P7XXTM1-G on 2021/11/13.
//

#include <stdio.h>
#include "SqStack.h"
#include "SqStack-In-Use.h"

#define Default_Size 5

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
        printf(StackEmpty_Sq(sqStack) ? "空\n" : "非空\n");
    }

    printf("---进栈\n");
    {
        for (int i = 1; i <= Default_Size; ++i) {
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
        printf("%d\n", elem);
    }

    // printf("---十进制转八进制\n");
    // {
    //     Conversion(342391);
    // }

    return 0;
}