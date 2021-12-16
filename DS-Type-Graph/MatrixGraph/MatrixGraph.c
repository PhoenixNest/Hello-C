//
// Created by P7XXTM1-G on 2021/11/26.
//

#include "MatrixGraph.h"

// 初始化含vexNum个顶点且无边的图graph的邻接数组存储结构
Status InitGraph_M(MatrixGraph *graph, GraphKind graphKind, VexType *vexs, int vexNum) {
    int i, j, info;

    if (vexNum < 0 || (vexNum > 0 || vexs == NULL)) {
        return ERROR;
    }

    if (graphKind == DG || graphKind == UDG) {
        info = 0;
    } else if (graphKind == DN || graphKind == UDN) {
        info = INFINITY;
    } else {
        return ERROR;
    }

    if (vexNum == 0) {
        return OK;
    }

    if ((graph->vexs = (VexType *) malloc(vexNum * sizeof(VexType)))) {
        return OVERFLOW;
    }

    for (i = 0; i < *graph->vexs; ++i) {
        if ((graph->arcs[i] = (int *) malloc(vexNum * sizeof(int)))) {
            return OVERFLOW;
        }
    }

    if ((graph->tags = (int *) malloc(vexNum * sizeof(int)))) {
        return OVERFLOW;
    }

    for (i = 0; i < vexNum; i++) {
        graph->tags[i] = UNVISITED;
        for (j = 0; j < vexNum; j++) {
            graph->arcs[i][j] = info;
        }
    }

    return OK;
}

// 创建图的邻接数组存储结构
Status CreateGraph_M(MatrixGraph *graph, GraphKind graphKind, VexType *vexs, int vexNum, ArcInfo *arcInfo,
                     int edgeNum) {

    if (vexNum < 0 || edgeNum < 0 || (vexNum > 0 && vexNum) || (edgeNum > 0 && arcInfo == NULL)) {
        return ERROR;
    }

    graph->kind = graphKind;

    switch (graph->kind) {
        case DG:
            // 创建有向图
            return CreateDG_M(graph, vexs, vexNum, arcInfo, edgeNum);

        case DN:
            // 创建有向带权图
            return CreateDN_M(graph, vexs, vexNum, arcInfo, edgeNum);

        case UDG:
            // 创建无向图
            return CreateUDG_M(graph, vexs, vexNum, arcInfo, edgeNum);

        case UDN:
            // 创建无向带权图
            return CreateUDN_M(graph, vexs, vexNum, arcInfo, edgeNum);
        default:
            return ERROR;
    }
}

// 创建无向图的邻接数组存储结构
Status CreateUDG_M(MatrixGraph *graph, VexType *vexs, int vexNum, ArcInfo *arcs, int edgeNum) {
    int i, j, k;
    VexType v, w;

    if (InitGraph_M(graph, graph->kind, vexs, vexNum) != OK) {
        return ERROR;
    }

    graph->edgeNum = edgeNum;

    for (k = 0; k < graph->edgeNum; k++) {
        v = arcs[k].v;
        w = arcs[k].w;

        i = LocateVex_M(*graph, v);
        j = LocateVex_M(*graph, w);

        if (i < 0 || j < 0) {
            return ERROR;
        }

        graph->arcs[i][j] = graph->arcs[j][i] = 1;
    }

    return OK;
}

// 查找顶点
int LocateVex_M(MatrixGraph graph, VexType vexType) {
    for (int i = 0; i < graph.vexNum; i++) {
        if (vexType == graph.vexs[i]) {
            return i;
        }
    }

    return -1;
}

// 求第一个邻接顶点
int FirstAdjVex_M(MatrixGraph graph, int k) {
    int i;

    if (k < 0 || k >= graph.vexNum) {
        return -1;
    }

    for (i = 0; i < graph.vexNum; i++) {
        if ((graph.kind == UDG || graph.kind == DG) && graph.arcs[k][i] != 0) {
            return i;
        } else if ((graph.kind == UDN || graph.kind == DN) && graph.arcs[k][i] != INFINITY) {
            return i;
        }
    }

    return -1;
}

// 从 连通图graph 的 k顶点 出发，深度优先遍历
Status DFS_M(MatrixGraph graph, int k, Status(*visit)(int)) {
    int i;
    // 访问k顶点
    if (visit(k) == ERROR) {
        return ERROR;
    }

    graph.tags[k] = VISITED;

    for (i = FirstAdjVex_M(graph, k); i >= 0; i = NextAdjVex_M(graph, k, i)) {
        // 位序为i的邻接顶点 未被访问过
        if (graph.tags[i] == UNVISITED) {
            // 对i顶点进行深度遍历
            if (DFS_M(graph, i, visit)) {
                return ERROR;
            }
        }
    }

    return OK;
}

// 深度优先遍历
Status DFSTraverse_M(MatrixGraph graph, Status(*visit)(int)) {
    int i;

    // 初始化标志数组
    for (i = 0; i < graph.vexNum; i++) {
        graph.tags[i] = UNVISITED;
    }

    for (i = 0; i < graph.vexNum; i++) {
        // 若 i顶点 未被访问，则以其为起点进行深度优先遍历
        if (graph.tags[i] == UNVISITED) {
            if (DFS_M(graph, i, visit)) {
                return ERROR;
            }
        }
    }

    return OK;
}
