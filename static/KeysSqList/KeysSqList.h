//
// Created by P7XXTM1-G on 2021/11/19.
//

#ifndef HELLO_C_KEYSSEQLIST_H
#define HELLO_C_KEYSSEQLIST_H

typedef int KeysType;

typedef struct {
    KeysType *keys;
} KeysRecordElemType;

typedef struct {
    KeysRecordElemType *base;
    int length;
    int size;
    int digitNum;
    int radix;
} KeysSqList;

#endif //HELLO_C_KEYSSEQLIST_H
