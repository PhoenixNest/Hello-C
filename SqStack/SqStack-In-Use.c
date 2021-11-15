//
// Created by P7XXTM1-G on 2021/11/14.
//

#include "Status.h"
#include "SqStack.h"
#include "SqStack-In-Use.h"

#define Default_Size 10

// 十进制 -> 八进制
// ----------
// 存储每一步计算后的余数，将栈的内容依次输出，计算结束
// ----------
void Conversion(int num) {
    ElemType elem;
    SqStack sqStack;

    // 栈初始容量为 10
    InitStack_Sq(&sqStack, Default_Size, 2 * Default_Size);

    printf("十进制数 %d 转换为八进制数后为：0", num);

    while (num != 0) {
        // 将 num 除以 8 的余数入栈
        Push_Sq(&sqStack, num % 8);

        // num 取值为其除以8的商
        num /= 8;
    }

    while (StackEmpty_Sq(sqStack) == FALSE) {
        // 依次输出栈中的余数
        Pop_Sq(&sqStack, &elem);
        printf("%d", elem);
    }

    printf("\n");
}

// 括号匹配
// ----------
// 1.依次扫描括号序列，每读入一个括号：
//   1）若是左括号，则入栈
//   2）若是右括号，首先检查栈，若栈空，则表明该“右括号”多余，不匹配，结束
//   3）否则与栈顶元素比较，若相匹配，则“左括号”出栈，否则不匹配，结束
// ----------
// 2.当读入完所有括号时检查栈，若栈空，则括号正确匹配，结束，否则“左括号”多余，不匹配，结束
// ----------
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
                if (TRUE == StackEmpty_Sq(sqStack)) {
                    // 当读入所有括号时检查栈，若栈空，则括号正确匹配，结束。
                    return ERROR;
                } else {
                    // 否则，“左括号多余”，不匹配，结束
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