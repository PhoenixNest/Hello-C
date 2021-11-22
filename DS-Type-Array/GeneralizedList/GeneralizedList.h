//
// Created by P7XXTM1-G on 2021/11/22.
//

#ifndef HELLO_C_GENERALIZEDLIST_H
#define HELLO_C_GENERALIZEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"

typedef int ElemType;

typedef char AtomType;
typedef enum {
    // 原子表（不可分，层数小于1）
    ATOM,
    // 正常表（层数大于1）
    LIST
} ElemTag;

typedef struct GLNode {
    ElemTag tag;
    union {
        AtomType atom;
        struct {
            struct GLNode *headPointer;
            struct GLNode *tailPointer;
        } pointer;
    } un;
} GLNode, *GList;

GLNode *MakeAtom(AtomType elem);

void InitGList(GList *gList);

Status DestroyGList(GList *gList);

GLNode *GetHead(GList *gList);

GList GetTail(GList gList);

Status InsertHead(GList *gList, GLNode *glNode);

Status Append(GList *gList, GLNode *glNode);

Status DeleteHead(GList gList, GList *headPointer);

int GListDepth(GList gList);

GList CopyGList(GList gList);

int GListLength(GList gList);

Status GListEmpty(GList gList);

Status GListTraverse(GList gList, Status(*visit)(ElemType elem));

#endif //HELLO_C_GENERALIZEDLIST_H
