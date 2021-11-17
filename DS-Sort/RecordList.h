//
// Created by P7XXTM1-G on 2021/11/17.
//

#ifndef HELLO_C_RECORDLIST_H
#define HELLO_C_RECORDLIST_H

#include "RecordType.h"

typedef struct {
    RecordElemType *recordElem;
    int length;
    int size;
} RecordList;

#endif //HELLO_C_RECORDLIST_H
