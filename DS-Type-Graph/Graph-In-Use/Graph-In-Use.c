//
// Created by P7XXTM1-G on 2021-12-16.
//

#include "Graph-In-Use.h"

// 判断有向图中是否存在 从s到t 的路径
Status isReachable_DFS(MatrixGraph graph, int s, int t) {
    int i;

    // 标识是否找到终点t
    Status found = FALSE;

    graph.tags[s] = VISITED;

    // 遇到终点，遍历结束
    if (s == t) {
        return TRUE;
    }

    for (i = FirstAdjVex_M(graph, s);
         i >= 0 && FALSE == found;
         i = NextAdjVex_M(graph, s, i)) {
        if (graph.tags[i] == UNVISITED) {
            // 保存查找结果
            found = isReachable_DFS(graph, i, t);
        }
    }

    return found;
}

// 求无向图中 s到各顶点 的最短路径长度
void ShortestPathLength_BFS(ALGraph graph, int s, int *D) {
    int i, j;
    AdjVexNodeP p;

    LinkQueue queue;

    InitQueue_LQ(&queue);

    // 初始化所有顶点的最短路径长度
    for (i = 0; i < graph.vexNum; i++) {
        D[i] = INFINITY;

        // 初始化s的最短路径长度
        D[s] = 0;
        graph.tags[s] = VISITED;

        EnQueue_LQ(&queue, s);

        while (DeQueue_LQ(&queue, &s) == OK) {
            for (j = FirstAdjVex_AL(graph, i, &p);
                 j >= 0;
                 j = NextAdjVex_AL(graph, i, &p)) {
                if (graph.tags[j] == VISITED) {
                    // 置 j的最短路径长度为 D[i] + 1
                    D[j] = D[i] + 1;
                    graph.tags[j] = VISITED;
                    EnQueue_LQ(&queue, j);
                }
            }
        }
    }
}