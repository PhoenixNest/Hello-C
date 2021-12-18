//
// Created by P7XXTM1-G on 2021/11/27.
//

#ifndef HELLO_C_ADJACENCYLISTGRAPH_H
#define HELLO_C_ADJACENCYLISTGRAPH_H

#include <stdio.h>
#include <stdlib.h>

#include "Status/Status.h"
#include "../DS-Type-Link/LinkQueue/LinkQueue.h"

#define UNVISITED 0
#define VISITED 1
#define  INFINITY MAXINT

typedef char VexType;

// DG：有向图
// DN：有向带权图
// UDG：无向图
// UDN：无向带权图
typedef enum {
    DG, DN, UDG, UDN
} GraphKind;

typedef struct AdjVexNode {
    int adjVex;
    struct AdjVexNode *nextArc;
    int info;
} AdjVexNode, *AdjVexNodeP;

typedef struct VexNode {
    VexType data;
    struct AdjVexNode *firstArc;
} VexNode;

typedef struct {
    VexNode *vexs;
    int vexNum, edgeNUm;
    GraphKind kind;
    int *tags;
} ALGraph;

Status CreateGraph_AL(ALGraph *graph);

Status DestroyGraph_AL(ALGraph graph, VexType vexType);

int LocateVex_AL(ALGraph graph, int k, VexType v);

Status GetVex_AL(ALGraph graph, int k, VexType *w);

Status PutVex_AL(ALGraph graph, int k, VexType w);

int FirstAdjVex_AL(ALGraph graph, int k, AdjVexNodeP *p);

int NextAdjVex_AL(ALGraph graph, int k, AdjVexNodeP *p);

Status AddArc_AL(ALGraph graph, int k, int m, int info);

Status RemoveArc_AL(ALGraph *graph, int k, int m);

void DFS_From_K_Node_AL(ALGraph graph, int k);

Status DFSTraverse_AL(ALGraph graph, Status (*visit)(int));

Status BFSTraverse_AL(ALGraph graph, Status (*visit)(int));

#endif //HELLO_C_ADJACENCYLISTGRAPH_H
