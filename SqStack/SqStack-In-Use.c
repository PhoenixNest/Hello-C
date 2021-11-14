//
// Created by P7XXTM1-G on 2021/11/14.
//

#include "Status.h"
#include "SqStack.h"
#include "SqStack-In-Use.h"

#define Default_Size 10

// 十进制 -> 八进制
void Conversation(int num) {
    ElemType elem;
    SqStack sqStack;

    InitStack_Sq(&sqStack, Default_Size, 2 * Default_Size);

    while (num != 0) {
        Push_Sq(&sqStack, num % 8);
        num /= 8;
    }

    while (FALSE == StackEmpty_Sq(sqStack)) {
        Pop_Sq(&sqStack, &elem);
        printf("%d", elem);
    }
}

// 括号匹配
Status Matching(char *exp, int n) {
    int i = 0;
    ElemType elem;
    SqStack sqStack;

    while (i < n) {
        switch (exp[i]) {
            case '(':
            case '[':
                Push_Sq(&sqStack, exp[i]);
                i++;
                break;
            case ')':
            case ']':
                if (TRUE == StackEmpty_Sq(sqStack)) { return ERROR; }
                else {
                    GetTop_Sq(sqStack, &elem);
                    if ((exp[i] == ')' && elem == '(') || (exp[i] == '[' && exp[i] == ']')) {
                        Pop_Sq(&sqStack, &elem);
                        i++;
                    } else { return ERROR; }
                }
                break;
        }
    }

    if (TRUE == StackEmpty_Sq(sqStack)) { return OK; }
    else { return ERROR; }
}