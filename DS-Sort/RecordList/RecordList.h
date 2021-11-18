//
// Created by P7XXTM1-G on 2021/11/17.
//

#ifndef HELLO_C_RECORDLIST_H
#define HELLO_C_RECORDLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "Status.h"
#include "RecordType/RecordType.h"

typedef struct {
    RecordElemType *base;
    int length;
    int size;
} RecordList;

Status InitList_Rec(RecordList *recordList, int size);

Status Insert_Rec(RecordList *recordList, int position, RecordElemType elem);

#endif //HELLO_C_RECORDLIST_H
