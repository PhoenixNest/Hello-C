//
// Created by P7XXTM1-G on 2021/12/5.
//

#include "UnionFindSets.h"

Status InitUnionFindSets(UnionFindSets *sets, int nodeNum) {
    sets->parent = (int *) malloc(nodeNum * sizeof(int));

    if (sets->parent == NULL) {
        return OVERFLOW;
    }

    for (int i = 0; i < nodeNum; i++) {
        // 初始化时每个元素自成一树，根结点值为 -1
        sets->parent[i] = -1;
    }

    sets->nodeNum = nodeNum;

    return OK;
}

// 递归查找

// 查找node在并查集sets中所属子集，返回代表元
int Find(UnionFindSets *sets, int i) {
    if (i < 0 || i > sets->nodeNum) {
        // 元素node不存在
        return -1;
    }

    while ((*sets).parent[i] >= 0) {
        i = sets->parent[i];
    }

    return i;
}

// 采用路径压缩的查找（Path Compress）
int Find_PC(UnionFindSets *sets, int i) {
    if (i < 0 || i > sets->nodeNum) {
        // 元素node不存在
        return -1;
    }

    // 相较于基础Find，主要改动以下代码
    // ------------------------------
    if (sets->parent[i] < 0) {
        // 找到根节点
        return i;
    }

    // i的双亲结点值值为根节点
    sets->parent[i] = Find_PC(sets, sets->parent[i]);

    return sets->parent[i];
}

// 递归合并

// 合并并查集sets中元素i和j所属的两个子集
Status Union(UnionFindSets *sets, int i, int j) {
    int ri, rj;

    // 非法查找位置
    if (i < 0 || i >= sets->nodeNum || j < 0 || j >= sets->nodeNum) {
        return FALSE;
    }

    // 查找i和j所在树的根结点
    ri = Find(sets, i);
    rj = Find(sets, j);

    if (ri == rj) {
        // i与j同属于一个子集，无需合并
        return FALSE;
    }

    // 将根结点ri的双亲结点置为rj，实现合并
    sets->parent[ri] = rj;

    return TRUE;
}

// 采用加权合并规则的合并（Widget Union Rule）
Status Union_WUR(UnionFindSets *sets, int i, int j) {
    int ri, rj;

    // 非法查找位置
    if (i < 0 || i >= sets->nodeNum || j < 0 || j >= sets->nodeNum) {
        return FALSE;
    }

    // 查找i和j所在树的根结点
    ri = Find(sets, i);
    rj = Find(sets, j);

    if (ri == rj) {
        // i与j同属于一个子集，无需合并
        return FALSE;
    }

    // 相较于基础Union，主要改动以下代码
    // ------------------------------
    // 比较的是结点的负值（结点所含元素个数）
    if (sets->parent[ri] > sets->parent[rj]) {
        sets->parent[rj] += sets->parent[ri];
        // 将元素i所在子集并到元素j所在子集
        sets->parent[ri] = rj;
    } else {
        sets->parent[ri] += sets->parent[rj];
        // 将元素j所在子集并到元素i所在子集
        sets->parent[ri] = rj;
    }

    return TRUE;
}