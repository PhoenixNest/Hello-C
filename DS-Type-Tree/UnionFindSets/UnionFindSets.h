//
// Created by P7XXTM1-G on 2021/12/5.
//

#ifndef HELLO_C_UNIONFINDSETS_H
#define HELLO_C_UNIONFINDSETS_H

#include <stdio.h>
#include <stdlib.h>

#include "Status/Status.h"

typedef struct {
    // 双亲数组
    // 其中数组下标表示元素
    // 数组存储对应元素所属树的双亲结点的位序，当为 -1 时，表示是树的根结点
    int *parent;

    // 森林中结点数目
    int nodeNum;
} ParentForest, UnionFindSets;

Status InitUnionFindSets(UnionFindSets *sets, int nodeNum);

Status DestroyUnionFindSets(UnionFindSets *sets);

int Find(UnionFindSets *sets, int i);

int Find_PC(UnionFindSets *sets, int i);

Status Diff(UnionFindSets *sets, int i, int j);

Status Union(UnionFindSets *sets, int i, int j);

Status Union_WUR(UnionFindSets *sets, int i, int j);

#endif //HELLO_C_UNIONFINDSETS_H
