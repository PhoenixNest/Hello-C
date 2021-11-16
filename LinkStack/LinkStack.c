//
// Created by P7XXTM1-G on 2021/11/16.
//

#include "LinkStack.h"

Status Push_LS(LinkStack *linkStack, ElemType elem) {
    LinkStackNode *node;
    node = (LinkStackNode *) malloc(sizeof(LinkStackNode));
    if (node == NULL) {
        return OVERFLOW;
    }

    node->data = elem;
    node->next = *linkStack;
    *linkStack = node;

    return OK;

}

Status Pop_LS(LinkStack *linkStack, ElemType elem) {
    LinkStackNode *node;
    if (linkStack == NULL) {
        return ERROR;
    }

    node = *linkStack;
    elem = (*linkStack)->data;
    *linkStack = (*linkStack)->next;

    free(node);

    return OK;
}