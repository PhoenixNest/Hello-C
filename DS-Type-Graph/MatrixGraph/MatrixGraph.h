//
// Created by P7XXTM1-G on 2021/11/26.
//

#ifndef HELLO_C_MATRIXGRAPH_H
#define HELLO_C_MATRIXGRAPH_H

#include <stdio.h>
#include <stdlib.h>

#include "Status/Status.h"

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

typedef struct {
    VexType *vexs;
    int **arcs;

    int vexNum, edgeNum;
    GraphKind kind;
    int *tags;
} MatrixGraph;

// v，w：从顶点v 到 顶点w
// info：权值
typedef struct {
    VexType v, w;
    int info;
} ArcInfo;

Status InitGraph_M(MatrixGraph *graph, GraphKind graphKind, VexType *vexs, int vexNum);

Status
CreateGraph_M(MatrixGraph *graph, GraphKind graphKind, VexType *vexs, int vexNum, ArcInfo *arcInfo, int edgeNum);

Status CreateDG_M(MatrixGraph *matrixGraph, VexType *vexs, int vexNum, ArcInfo *arcInfo, int edgeNum);

Status CreateDN_M(MatrixGraph *matrixGraph, VexType *vexs, int vexNum, ArcInfo *arcInfo, int edgeNum);

Status CreateUDG_M(MatrixGraph *graph, VexType *vexs, int vexNum, ArcInfo *arcs, int edgeNum);

Status CreateUDN_M(MatrixGraph *matrixGraph, VexType *vexs, int vexNum, ArcInfo *arcInfo, int edgeNum);

int LocateVex_M(MatrixGraph graph, VexType vexType);

Status GetVex_M(MatrixGraph matrixGraph, int k, VexType *w);

Status PutVex_M(MatrixGraph matrixGraph, int k, VexType w);

int FirstAdjVex_M(MatrixGraph graph, int k);

int NextAdjVex_M(MatrixGraph matrixGraph, int k, int m);

Status AddArc_M(MatrixGraph *matrixGraph, int k, int m, int info);

Status RemoveArc_M(MatrixGraph *matrixGraph, int k, int m);

Status DFSTraverse_M(MatrixGraph matrixGraph, Status(*visit)(int));

Status BFSTraverse_M(MatrixGraph matrixGraph, Status(*visit)(int));

#endif //HELLO_C_MATRIXGRAPH_H
